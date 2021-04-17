#pragma once

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <cassert>

#include "core/signals/signal.hpp"
#include "data_model/instance_ptr.hpp"
#include "data_model/exceptions.hpp"

namespace openworld
{
    enum class property_changed_mode
    {
        normal,
        computed
    };

    class instance :
        public std::enable_shared_from_this<instance>
    {
    public:
        static const std::string ClassName;
        static const std::string ClassNameProperty;
        static const std::string NameProperty;
        static const std::string ParentProperty;

        instance(const std::string& name = ClassName) :
            m_name(name)
        {}

        virtual ~instance() = 0 
        {
            assert(m_parent == nullptr);
            assert(m_children.empty());
        }

        signal<void(instance_ptr<instance>, instance_ptr<instance>)>& ancestry_changed()
        {
            return m_ancestry_changed;
        }

        signal<void(const std::string&, property_changed_mode)>& property_changed()
        {
            return m_property_changed;
        }

        signal<void(instance_ptr<instance>)>& child_added()
        {
            return m_child_added;
        }

        signal<void(instance_ptr<instance>)>& child_removed()
        {
            return m_child_removed;
        }

        signal<void(instance_ptr<instance>)>& descendant_added()
        {
            return m_descendant_added;
        }

        signal<void(instance_ptr<instance>)>& descendant_removing()
        {
            return m_descendant_removing;
        }

        signal<void(instance_ptr<instance>)>& descendant_removed()
        {
            return m_descendant_removed;
        }

        virtual const std::string& class_name() const
        {
            return ClassName;
        }

        const std::string& get_name() const
        {
            return m_name;
        }

        void set_name(const std::string& new_name)
        {
            set_property_internal(m_name, new_name, NameProperty, property_changed_mode::normal);
        }

        instance_ptr<instance> get_parent() const
        {
            if (m_parent == nullptr)
            {
                return nullptr;
            }

            return instance_ptr<instance>(m_parent->shared_from_this());
        }

        void set_parent(const instance_ptr<instance>& new_parent)
        {
            if (m_parent == new_parent.get())
            {
                return;
            }

            auto instance_ptr_this = instance_ptr<instance>(shared_from_this());

            if (new_parent == instance_ptr_this)
            {
                throw bad_instance_parent("Cannot set " + get_full_name() + " as its own parent");
            }

            if (is_ancestor_of(new_parent.get()))
            {
                auto path_a = get_full_name();
                auto path_b = new_parent->get_full_name();
                throw bad_instance_parent("Attempt to set parent of " + path_a + " to " + path_b + " would result in a circular reference");
            }

            auto old_parent = m_parent;

            if (m_parent_lock)
            {
                auto new_parent_name = new_parent != nullptr ? new_parent->get_name() : "NULL";
                auto old_parent_name = old_parent != nullptr ? old_parent->get_name() : "NULL";
                throw bad_instance_parent("The Parent property of " + m_name + " is locked, current parent: " + old_parent_name + ", new parent " + new_parent_name);
            }

            m_parent_lock = true;

            if (old_parent != nullptr)
            {
                old_parent->fire_descendant_removing_recursive(instance_ptr_this);
            }

            m_parent = new_parent.get();
            fire_property_changed(ParentProperty, property_changed_mode::normal);

            if (old_parent != nullptr)
            {
                old_parent->m_children.erase(
                    std::remove_if(
                        old_parent->m_children.begin(),
                        old_parent->m_children.end(),
                        [=](auto child) { return child == instance_ptr_this; }),
                    old_parent->m_children.end());

                old_parent->fire_child_removed(instance_ptr_this);
                old_parent->fire_descendant_removed_recursive(instance_ptr_this);
            }

            if (new_parent != nullptr)
            {
                new_parent->m_children.push_back(instance_ptr_this);
                new_parent->fire_child_added(instance_ptr_this);
                new_parent->fire_descendant_added_recursive(instance_ptr_this);
            }

            fire_ancestry_changed_recursive(instance_ptr_this, new_parent);

            m_parent_lock = false;
        }

        std::string get_full_name() const
        {
            if (m_parent == nullptr)
            {
                return m_name;
            }

            return m_parent->get_full_name() + "/" + m_name;
        }

        std::vector<instance_ptr<instance>> get_children() const
        {
            return m_children;
        }

        std::vector<instance_ptr<instance>> get_descendants() const
        {
            std::vector<instance_ptr<instance>> descendants{};
            get_descendants_internal(descendants);

            return descendants;
        }

        signal<void(const std::string&, property_changed_mode)>& get_property_changed_signal(const std::string& prop_name)
        {
            // TODO: Assert property exists?

            auto it = m_property_changed_signals.find(prop_name);
            if (it == m_property_changed_signals.end())
            {
                m_property_changed_signals.insert(std::make_pair(prop_name, signal<void(const std::string&, property_changed_mode)>{}));
                it = m_property_changed_signals.find(prop_name);
            }

            return it->second;
        }

        bool is_ancestor_of(const instance* descendant) const
        {
            while (descendant != nullptr)
            {
                if (descendant == this)
                {
                    return true;
                }

                descendant = descendant->m_parent;
            }

            return false;
        }

        bool is_descendant_of(const instance* ancestor) const
        {
            if (ancestor == nullptr)
            {
                return false;
            }

            ancestor->is_ancestor_of(this);
        }

        void clear_all_children()
        {
            for (auto child : m_children)
            {
                child->set_parent(nullptr);
            }
        }

    protected:
        template <typename PropertyT>
        bool set_property_internal(PropertyT& field,
                                   const PropertyT& new_value,
                                   const std::string& prop_name,
                                   property_changed_mode prop_changed_mode)
        {
            if (field == new_value)
            {
                return false;
            }

            field = new_value;
            fire_property_changed(prop_name, prop_changed_mode);

            return true;
        }

        void get_descendants_internal(std::vector<instance_ptr<instance>>& descendants) const
        {
            for (auto child : m_children)
            {
                descendants.push_back(child);
                child->get_descendants_internal(descendants);
            }
        }

        void fire_property_changed(const std::string& prop_name, property_changed_mode prop_changed_mode) const
        {
            auto it = m_property_changed_signals.find(prop_name);
            if (it != m_property_changed_signals.end())
            {
                it->second.dispatch(prop_name, prop_changed_mode);
            }

            m_property_changed.dispatch(prop_name, prop_changed_mode);
        }

    private:
        signal<void(instance_ptr<instance>, instance_ptr<instance>)> m_ancestry_changed;
        signal<void(const std::string&, property_changed_mode)> m_property_changed;
        signal<void(instance_ptr<instance>)> m_child_added;
        signal<void(instance_ptr<instance>)> m_child_removed;
        signal<void(instance_ptr<instance>)> m_descendant_added;
        signal<void(instance_ptr<instance>)> m_descendant_removing;
        signal<void(instance_ptr<instance>)> m_descendant_removed;

        std::string m_name;
        instance* m_parent = nullptr;
        bool m_parent_lock = false;
        std::vector<instance_ptr<instance>> m_children;
        std::map<std::string, signal<void(const std::string&, property_changed_mode)>> m_property_changed_signals;

        instance(const instance& other) = delete;
        instance& operator =(const instance& other) = delete;

        void fire_ancestry_changed_recursive(const instance_ptr<instance>& child, const instance_ptr<instance>& parent) const
        {
            m_ancestry_changed.dispatch(child, parent);
            for (auto direct_child : m_children)
            {
                direct_child->fire_ancestry_changed_recursive(child, parent);
            }
        }

        void fire_child_added(const instance_ptr<instance>& child) const
        {
            m_child_added.dispatch(child);
        }

        void fire_child_removed(const instance_ptr<instance>& child) const
        {
            m_child_removed.dispatch(child);
        }

        void fire_descendant_added_recursive(const instance_ptr<instance>& descendant) const
        {
            m_descendant_added.dispatch(descendant);
            if (m_parent != nullptr)
            {
                m_parent->fire_descendant_added_recursive(descendant);
            }
        }

        void fire_descendant_removing_recursive(const instance_ptr<instance>& descendant) const
        {
            m_descendant_removing.dispatch(descendant);
            if (m_parent != nullptr)
            {
                m_parent->fire_descendant_removing_recursive(descendant);
            }
        }

        void fire_descendant_removed_recursive(const instance_ptr<instance>& descendant) const
        {
            m_descendant_removed.dispatch(descendant);
            if (m_parent != nullptr)
            {
                m_parent->fire_descendant_removed_recursive(descendant);
            }
        }
    };
}