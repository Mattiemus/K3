#pragma once

namespace openworld
{
    class entity_iterator final
    {
        friend constexpr bool operator ==(const entity_iterator& lhs, const entity_iterator& rhs);
        friend constexpr bool operator !=(const entity_iterator& lhs, const entity_iterator& rhs);

    public:
        entity_iterator(
            entity_id eid,
            const std::vector<bool>& entity_is_living,
            const std::vector<component_mask>& entity_component_masks) :
            m_current_entity(eid),
            m_entity_is_living(entity_is_living),
            m_entity_component_masks(entity_component_masks)
        {
        }

        entity_iterator(
            entity_id eid,
            const matcher& m, 
            const std::vector<bool>& entity_is_living,
            const std::vector<component_mask>& entity_component_masks) :
            m_current_entity(eid),
            m_matcher(m),
            m_entity_is_living(entity_is_living),
            m_entity_component_masks(entity_component_masks)
        {
        }

        const entity& operator *() const
        {
            return m_current_entity;
        }

        entity const* operator ->() const
        {
            return &m_current_entity;
        }

        entity_iterator& operator++()
        {
            if (m_current_entity == null_entity)
            {
                return *this;
            }

            auto next_entity_id = m_current_entity.id();

            if (m_matcher.has_value())
            {
                do
                {
                    next_entity_id++;
                    if (next_entity_id >= m_entity_is_living.size())
                    {
                        m_current_entity = null_entity;
                        return *this;
                    }
                } while (!m_entity_is_living[next_entity_id] || !m_matcher.value().matches(m_entity_component_masks[next_entity_id]));
            }
            else
            {
                do
                {
                    next_entity_id++;
                    if (next_entity_id >= m_entity_is_living.size())
                    {
                        m_current_entity = null_entity;
                        return *this;
                    }
                } while (!m_entity_is_living[next_entity_id]);
            }

            m_current_entity = { next_entity_id };

            return *this;
        }

        entity_iterator operator++(int)
        {
            auto tmp = *this;
            ++(*this);
            return tmp;
        }

    private:
        entity m_current_entity;
        std::optional<matcher> m_matcher;
        const std::vector<bool>& m_entity_is_living;
        const std::vector<component_mask>& m_entity_component_masks;
    };

    constexpr bool operator ==(const entity_iterator& lhs, const entity_iterator& rhs)
    {
        return *lhs == *rhs;
    }

    constexpr bool operator !=(const entity_iterator& lhs, const entity_iterator& rhs)
    {
        return *lhs != *rhs;
    }

    class entity_manager final
    {
    public:
        entity create_entity()
        {
            if (!m_available_entity_ids.empty())
            {
                auto recycled_entity_id = m_available_entity_ids.front();
                m_available_entity_ids.pop();

                m_entity_is_living[recycled_entity_id] = true;

                m_living_entity_count++;

                return entity(recycled_entity_id);
            }

            entity new_entity{ m_next_entity_id++ };

            m_entity_component_masks.push_back({});
            m_entity_is_living.push_back(true);

            m_living_entity_count++;

            return new_entity;
        }

        void destroy_entity(const entity& e)
        {
            m_entity_component_masks[e.id()].reset();
            m_entity_is_living[e.id()] = false;

            m_available_entity_ids.push(e.id());
            m_living_entity_count--;
        }

        entity_iterator begin() const
        {
            return entity_iterator(0, m_entity_is_living, m_entity_component_masks);
        }

        entity_iterator begin(const matcher& m) const
        {
            return entity_iterator(0, m, m_entity_is_living, m_entity_component_masks);
        }

        entity_iterator end() const
        {
            return entity_iterator(null_entity_id, m_entity_is_living, m_entity_component_masks);
        }

        void set_component_mask(const entity& e, const component_mask& mask)
        {
            m_entity_component_masks[e.id()] = mask;
        }

        component_mask get_component_mask(const entity& e) const
        {
            return m_entity_component_masks[e.id()];
        }

    private:
        entity_id m_next_entity_id = 0;
        std::queue<entity_id> m_available_entity_ids;
        std::vector<bool> m_entity_is_living;
        std::vector<component_mask> m_entity_component_masks;
        size_t m_living_entity_count = 0;
    };
}