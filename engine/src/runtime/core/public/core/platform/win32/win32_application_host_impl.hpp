#pragma once

#include <atomic>

#include "core/platform/impl/application_host_impl.hpp"
#include "core/platform/win32/win32_api.hpp"

namespace openworld
{
    class win32_application_host_impl final :
        public application_host_impl
    {
    public:
        win32_application_host_impl(HINSTANCE hinst);
        virtual ~win32_application_host_impl();

        virtual bool is_running() override
        {
            return m_is_running;
        }

        virtual std::shared_ptr<window> create_window(bool is_top_level) override;

        virtual int run() override;
        virtual int run(std::function<void()> idle_callback) override;
        virtual void shutdown() override;

    private:
        HINSTANCE m_hinst;
        std::atomic<bool> m_is_running = false;
    };
}