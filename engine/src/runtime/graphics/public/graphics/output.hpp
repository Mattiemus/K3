#pragma once

namespace openworld
{
    class output final
    {
    public:
        output(void* monitor_handle, const std::string& name, const int_rectangle& bounds) :
            m_monitor_handle(monitor_handle),
            m_name(name),
            m_bounds(bounds)
        {}

        constexpr void* monitor_handle() const
        {
            return m_monitor_handle;
        }

        constexpr const std::string& name() const
        {
            return m_name;
        }

        constexpr const int_rectangle& desktop_bounds() const
        {
            return m_bounds;
        }

    private:
        void* m_monitor_handle;
        std::string m_name;
        int_rectangle m_bounds;
    };
}