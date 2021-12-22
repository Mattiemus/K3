#pragma once

#include <memory>
#include <functional>

namespace openworld
{
    class window;

    class application_host_impl
    {
    public:
        virtual ~application_host_impl() = 0 {}

        // TODO: main_window
        // TODO: windows
        virtual bool is_running() = 0;

        virtual std::shared_ptr<window> create_window(bool is_top_level) = 0;

        virtual int run() = 0;
        virtual int run(std::function<void()> idle_callback) = 0;
        virtual void shutdown() = 0;
    };
}