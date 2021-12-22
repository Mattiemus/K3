#pragma once

namespace openworld
{
    template <typename Component, size_t MaxComponentInstances>
    class array_component_storage final
    {
    public:
        constexpr size_t size() const
        {
            return m_size;
        }

        Component* get(const entity& e)
        {
            auto it = m_entity_to_index.find(e);
            if (it == m_entity_to_index.end())
            {
                return nullptr;
            }

            return &m_component_arr[it->second];
        }

        const Component* get(const entity& e) const
        {
            auto it = m_entity_to_index.find(e);
            if (it == m_entity_to_index.end())
            {
                return nullptr;
            }

            return &m_component_arr[it->second];
        }

        void set(const entity& e, const Component& c)
        {
            auto it = m_entity_to_index.find(e);
            if (it != m_entity_to_index.end())
            {
                m_component_arr[it->second] = c;
                return;
            }

            m_entity_to_index[e] = m_size;
            m_index_to_entity[m_size] = e;
            m_component_arr[m_size] = c;

            ++m_size;
        }

        bool remove(const entity& e)
        {
            auto it = m_entity_to_index.find(e);
            if (it == m_entity_to_index.end())
            {
                return false;
            }

            auto removed_entity_idx = m_entity_to_index[e];
            auto last_element_idx = m_size - 1;
            m_component_arr[removed_entity_idx] = m_component_arr[last_element_idx];

            auto entity_of_last_element = m_entity_to_index[last_element_idx];
            m_entity_to_index[entity_of_last_element] = removed_entity_idx;
            m_index_to_entity[removed_entity_idx] = entity_of_last_element;

            m_entity_to_index.erase(e);
            m_index_to_entity.erase(last_element_idx);

            --m_size;

            return true;
        }

    private:
        std::array<Component, MaxComponentInstances> m_component_arr;
        std::unordered_map<entity, size_t> m_entity_to_index;
        std::unordered_map<size_t, entity> m_index_to_entity;
        size_t m_size = 0;
    };
}