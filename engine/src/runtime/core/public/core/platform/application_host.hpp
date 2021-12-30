#pragma once

namespace openworld
{
    class application_host final
    {
    public:
        application_host()
        {
            auto playform_sys = engine::services().get_service<platform_system>();
            m_impl = playform_sys->create_application_host_impl();
        }

        application_host(platform_system& playform_sys)
        {
            m_impl = playform_sys.create_application_host_impl();
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
        std::unique_ptr<application_host_impl> m_impl;
    };
}