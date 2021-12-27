#pragma once

#include "core/platform/platform_service.hpp"
#include "core/platform/win32/win32_application_host_impl.hpp"

namespace openworld
{
    class win32_platform_service final :
        public platform_service
    {
    public:
        win32_platform_service(HINSTANCE hinst = GetModuleHandle(NULL)) :
            m_hinst(hinst)
        {}

        virtual std::shared_ptr<application_host_impl> create_application_host_impl() override
        {
            return std::make_shared<win32_application_host_impl>(m_hinst);
        }

    private:
        HINSTANCE m_hinst = NULL;
    };
}