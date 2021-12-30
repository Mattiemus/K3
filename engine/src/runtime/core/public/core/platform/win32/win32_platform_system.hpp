#pragma once

namespace openworld
{
    class win32_platform_system final :
        public platform_system
    {
    public:
        win32_platform_system(HINSTANCE hinst = GetModuleHandle(NULL)) :
            m_hinst(hinst)
        {}

        virtual std::string platform() override
        {
            return "win32";
        }

        virtual std::unique_ptr<application_host_impl> create_application_host_impl() override
        {
            return std::make_unique<win32_application_host_impl>(m_hinst);
        }

    private:
        HINSTANCE m_hinst = NULL;
    };
}