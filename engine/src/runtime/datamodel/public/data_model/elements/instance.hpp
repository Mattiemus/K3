#pragma once

#include <memory>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "data_model/exceptions/instance_destroyed.hpp"
#include "data_model/signals/signal.hpp"

namespace openworld
{
    class instance_manager;

    class instance : public std::enable_shared_from_this<instance>
    {
    public:
        static const std::string ClassName;
        static const std::string ClassNameProperty;
        static const std::string NameProperty;
        static const std::string ParentProperty;

        instance(std::shared_ptr<instance_manager> instance_manager) :
            m_instance_manager(instance_manager)
        {
        }

        virtual ~instance() = 0
        {
            destroy();
        }

        signal<void(std::shared_ptr<instance>, std::shared_ptr<instance>)>& ancestry_changed()
        {
            throw_if_destroyed();
            return m_ancestry_changed;
        }

        signal<void(const std::string&)>& property_changed()
        {
            throw_if_destroyed();
            return m_property_changed;
        }

        signal<void(std::shared_ptr<instance>)>& child_added()
        {
            throw_if_destroyed();
            return m_child_added;
        }

        signal<void(std::shared_ptr<instance>)>& child_removed()
        {
            throw_if_destroyed();
            return m_child_removed;
        }

        signal<void(std::shared_ptr<instance>)>& descendant_added()
        {
            throw_if_destroyed();
            return m_descendant_added;
        }

        signal<void(std::shared_ptr<instance>)>& descendant_removing()
        {
            throw_if_destroyed();
            return m_descendant_removing;
        }

        virtual const std::string& class_name() const
        {
            throw_if_destroyed();
            return ClassName;
        }

        const std::string& get_name() const
        {
            throw_if_destroyed();
            return m_name;
        }

        void set_name(const std::string& new_name)
        {
            throw_if_destroyed();
            set_property_internal(m_name, new_name, NameProperty);
        }

        std::shared_ptr<instance> get_parent() const
        {
            throw_if_destroyed();
            return m_parent;
        }

        void set_parent(std::shared_ptr<instance> new_parent)
        {
            throw_if_destroyed();

            if (m_parent == new_parent)
            {
                return;
            }

            auto old_parent = m_parent;

            if (old_parent != nullptr)
            {
                old_parent->fire_descendant_removing_recursive(shared_from_this());

            }

            m_parent = new_parent;
            fire_property_changed(ParentProperty);

            if (old_parent != nullptr)
            {
                old_parent->m_children.erase(shared_from_this());
                old_parent->fire_child_removed(shared_from_this());
                old_parent->fire_ancestry_changed_recursive(shared_from_this(), new_parent);
            }

            if (new_parent != nullptr)
            {
                new_parent->m_children.insert(shared_from_this());
                new_parent->fire_child_added(shared_from_this());
                new_parent->fire_descendant_added_recursive(shared_from_this());
                new_parent->fire_ancestry_changed_recursive(shared_from_this(), new_parent);
            }
        }

        std::string get_full_name() const
        {
            throw_if_destroyed();

            if (m_parent == nullptr)
            {
                return m_name;
            }

            return m_parent->get_full_name() + "/" + m_name;
        }

        std::set<std::shared_ptr<instance>> get_children() const
        {
            throw_if_destroyed();
            return m_children;
        }

        // TODO: GetDescendants

        // TODO: GetPropertyChangedSignal

        // TODO: FirstChildNamed

        // TODO: FirstAncestorNamed

        bool is_ancestor_of(const std::shared_ptr<const instance> descendant) const
        {
            throw_if_destroyed();

            if (descendant == nullptr)
            {
                return false;
            }

            return descendant->is_ancestor_of(std::const_pointer_cast<const instance>(shared_from_this()));
        }

        bool is_descendant_of(const std::shared_ptr<const instance> ancestor) const
        {
            throw_if_destroyed();

            if (ancestor == nullptr || m_parent == ancestor)
            {
                return true;
            }

            if (m_parent == nullptr)
            {
                return false;
            }

            return m_parent->is_descendant_of(std::const_pointer_cast<const instance>(ancestor));
        }

        void clear_all_children()
        {
            throw_if_destroyed();

            auto children = m_children;
            for (auto child : children)
            {
                child->destroy();
            }
        }

        void destroy();

    protected:
        template <typename PropertyT>
        bool set_property_internal(PropertyT& field,
                                   const PropertyT& new_value,
                                   const std::string& prop_name)
        {
            if (field == new_value)
            {
                return false;
            }

            field = new_value;
            fire_property_changed(prop_name);

            return true;
        }

        void fire_property_changed(const std::string& prop_name) const
        {
            auto it = m_property_changed_signals.find(prop_name);
            if (it != m_property_changed_signals.end())
            {
                it->second.dispatch(prop_name);
            }

            m_property_changed.dispatch(prop_name);
        }

        void throw_if_destroyed() const
        {
            if (m_is_destroyed)
            {
                throw instance_destroyed();
            }
        }

    private:
        signal<void(std::shared_ptr<instance>, std::shared_ptr<instance>)> m_ancestry_changed;
        signal<void(const std::string&)> m_property_changed;
        signal<void(std::shared_ptr<instance>)> m_child_added;
        signal<void(std::shared_ptr<instance>)> m_child_removed;
        signal<void(std::shared_ptr<instance>)> m_descendant_added;
        signal<void(std::shared_ptr<instance>)> m_descendant_removing;

        bool m_is_destroyed = false;
        std::shared_ptr<instance_manager> m_instance_manager;
        std::string m_name;
        std::shared_ptr<instance> m_parent;
        std::set<std::shared_ptr<instance>> m_children;
        std::map<std::string, signal<void(const std::string&)>> m_property_changed_signals;

        instance(const instance& other) = delete;
        instance& operator =(const instance& other) = delete;

        void fire_ancestry_changed_recursive(std::shared_ptr<instance> child, std::shared_ptr<instance> parent) const
        {
            m_ancestry_changed.dispatch(child, parent);
            for (auto direct_child : m_children)
            {
                direct_child->fire_ancestry_changed_recursive(child, parent);
            }
        }

        void fire_child_added(std::shared_ptr<instance> child) const
        {
            m_child_added.dispatch(child);
        }

        void fire_child_removed(std::shared_ptr<instance> child) const
        {
            m_child_removed.dispatch(child);
        }

        void fire_descendant_added_recursive(std::shared_ptr<instance> descendant) const
        {
            m_descendant_added.dispatch(descendant);
            if (m_parent != nullptr)
            {
                m_parent->fire_descendant_added_recursive(descendant);
            }
        }

        void fire_descendant_removing_recursive(std::shared_ptr<instance> descendant) const
        {
            m_descendant_removing.dispatch(descendant);
            if (m_parent != nullptr)
            {
                m_parent->fire_descendant_removing_recursive(descendant);
            }
        }
    };
}