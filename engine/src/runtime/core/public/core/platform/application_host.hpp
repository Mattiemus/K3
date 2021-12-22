#pragma once

#include "core/engine/engine.hpp"
#include "core/platform/impl/application_host_impl.hpp"
#include "core/platform/platform_service.hpp"

namespace openworld
{
    class application_host final
    {
    public:
        application_host()
        {
            auto svc = engine::services().get_service<platform_service>();
            m_impl = svc->create_application_host_impl();
        }

        application_host(platform_service& svc)
        {
            m_impl = svc.create_application_host_impl();
        }

        bool is_running()
        {
            return m_impl->is_running();
        }

        std::shared_ptr<window> create_window(bool is_top_level)
        {
            return m_impl->create_window(is_top_level);
        }

        int run()
        {
            return m_impl->run();
        }

        int run(std::function<void()> idle_callback)
        {
            return m_impl->run(idle_callback);
        }

        void shutdown()
        {
            m_impl->shutdown();
        }

    private:
        std::shared_ptr<application_host_impl> m_impl;
    };
}