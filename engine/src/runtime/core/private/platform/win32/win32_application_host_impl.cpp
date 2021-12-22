#include <cassert>
#include <stdexcept>

#include "core/platform/win32/win32_application_host_impl.hpp"
#include "core/platform/win32/win32_window.hpp"

using namespace openworld;

win32_application_host_impl::win32_application_host_impl(HINSTANCE hinst) :
    m_hinst(hinst)
{}

win32_application_host_impl::~win32_application_host_impl()
{
    assert(!m_is_running);
}

std::shared_ptr<window> win32_application_host_impl::create_window(bool is_top_level)
{
    return std::make_shared<win32_window>(m_hinst, is_top_level);
}

int win32_application_host_impl::run()
{
    if (m_is_running)
    {
        throw std::runtime_error("Application host is already running");
    }

    m_is_running = true;

    MSG msg{};
    int return_value = 0;

    do
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if (msg.message == WM_QUIT)
            {
                m_is_running = false;
                return_value = static_cast<int>(msg.wParam);
            }
        }
    } while (m_is_running);

    return return_value;
}

int win32_application_host_impl::run(std::function<void()> idle_callback)
{
    if (m_is_running)
    {
        throw std::runtime_error("Application host is already running");
    }

    m_is_running = true;

    MSG msg{};
    int return_value = 0;

    do
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) != 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);

            if (msg.message == WM_QUIT)
            {
                m_is_running = false;
                return_value = static_cast<int>(msg.wParam);
            }
        }
        else
        {
            idle_callback();
        }
    } while (m_is_running);

    return return_value;
}

void win32_application_host_impl::shutdown()
{
    m_is_running = false;
}