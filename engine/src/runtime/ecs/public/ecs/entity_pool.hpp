#pragma once

namespace openworld
{
    class entity_pool final
    {
    public:
        entity create_entity()
        {
            return m_entity_manager.create_entity();
        }

        void destroy_entity(const entity& entity)
        {
            m_entity_manager.destroy_entity(entity);
            // TODO: component manager / components
        }

        entity_iterator begin() const
        {
            return m_entity_manager.begin();
        }

        entity_iterator begin(const matcher& m) const
        {
            return m_entity_manager.begin(m);
        }

        entity_iterator end() const
        {
            return m_entity_manager.end();
        }

        template <typename Component>
        void set_component(const entity& e, const Component& c)
        {
            m_component_manager.set_component(e, c);

            auto mask = m_entity_manager.get_component_mask(e);
            mask.set(component_registry::get_component_id<Component>(), true);
            m_entity_manager.set_component_mask(e, mask);
        }

        template <typename Component>
        void remove_component(const entity& e)
        {
            m_component_manager.remove_component<Component>(e);

            auto mask = m_entity_manager.get_component_mask(e);
            mask.set(component_registry::get_component_id<Component>(), false);
            m_entity_manager.set_component_mask(e, mask);
        }

        template <typename Component>
        Component* get_component(const entity& e)
        {
            return m_component_manager.get_component<Component>(e);
        }

        template <typename Component>
        const Component* get_component(const entity& e) const
        {
            return m_component_manager.get_component<Component>(e);
        }

    private:
        component_manager m_component_manager;
        entity_manager m_entity_manager;
    };
}