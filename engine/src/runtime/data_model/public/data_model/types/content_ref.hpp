#pragma once

namespace openworld
{
    class content_ref final
    {
    public:
        content_ref()
        {}

        content_ref(const std::string& id) :
            m_id(id)
        {}

        const std::string& id() const
        {
            return m_id;
        }

    private:
        std::string m_id;
    };

    inline bool operator ==(const content_ref& lhs, const content_ref& rhs)
    {
        return lhs.id() == rhs.id();
    }

    inline bool operator !=(const content_ref& lhs, const content_ref& rhs)
    {
        return lhs.id() != rhs.id();
    }
}