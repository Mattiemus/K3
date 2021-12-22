#pragma once

namespace openworld
{
    class component_manager final
    {
    public:
        template <typename Component>
        void set_component(const entity& e, const Component& c)
        {
            auto store = get_or_create_component_store<Component>();
            store->set(e, c);
        }

        template <typename Component>
        void remove_component(const entity& e)
        {
            auto store = get_component_store<Component>();

            if (store == nullptr)
            {
                return;
            }

            store->remove(e);
        }

        template <typename Component>
        Component* get_component(const entity& e)
        {
            auto store = get_component_store<Component>();

            if (store == nullptr)
            {
                return nullptr;
            }

            return store->get(e);
        }

        template <typename Component>
        const Component* get_component(const entity& e) const
        {
            auto store = get_component_store<Component>();

            if (store == nullptr)
            {
                return nullptr;
            }

            return store->get(e);
        }

    private:
        mutable std::unordered_map<std::type_index, std::shared_ptr<void>> m_component_stores;

        template <typename Component>
        std::shared_ptr<typename component_traits<Component>::storage> get_component_store() const
        {
            const auto& component_type = typeid(Component);

            auto it = m_component_stores.find(component_type);
            if (it == m_component_stores.end())
            {
                return nullptr;
            }

            return std::static_pointer_cast<typename component_traits<Component>::storage>(it->second);
        }

        template <typename Component>
        std::shared_ptr<typename component_traits<Component>::storage> get_or_create_component_store()
        {
            auto store = get_component_store<Component>();

            if (store != nullptr)
            {
                return store;
            }

            const auto& component_type = typeid(Component);

            store = std::make_shared<typename component_traits<Component>::storage>();
            m_component_stores.insert({ component_type, std::static_pointer_cast<void>(store) });

            return store;
        }
    };
}