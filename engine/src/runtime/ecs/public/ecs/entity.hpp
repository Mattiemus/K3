#pragma once

namespace openworld
{
    using entity_id = size_t;

    constexpr entity_id null_entity_id = std::numeric_limits<entity_id>::max();

    class entity final
    {
    public:
        constexpr entity()
        {
        }

        constexpr entity(entity_id id) :
            m_id(id)
        {
        }

        constexpr entity_id id() const
        {
            return m_id;
        }

    private:
        entity_id m_id = null_entity_id;
    };

    constexpr bool operator ==(const entity& lhs, const entity& rhs)
    {
        return lhs.id() == rhs.id();
    }

    constexpr bool operator !=(const entity& lhs, const entity& rhs)
    {
        return lhs.id() != rhs.id();
    }

    constexpr entity null_entity = {};
}

namespace std
{
    template <>
    struct hash<openworld::entity>
    {
        std::size_t operator()(const openworld::entity& e) const
        {
            return e.id();
        }
    };
}
