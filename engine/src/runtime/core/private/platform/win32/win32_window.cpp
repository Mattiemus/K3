#include "core.hpp"

using namespace openworld;

std::string win32_window::s_window_class_name = "win32_window";

win32_window::win32_window(HINSTANCE hinst, bool is_top_level) :
    m_is_top_level(is_top_level)
{
    WNDCLASS wndclass{};
    if (!GetClassInfo(hinst, s_window_class_name.c_str(), &wndclass))
    {
        wndclass.style = 0;
        wndclass.hInstance = hinst;
        wndclass.lpszClassName = s_window_class_name.c_str();
        wndclass.lpfnWndProc = &win32_window::window_proc_static;
        wndclass.cbClsExtra = 0;
        wndclass.cbWndExtra = 0;
        wndclass.hIcon = NULL;
        wndclass.hCursor = NULL;
        wndclass.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE + 1);
        wndclass.lpszMenuName = NULL;

        if (RegisterClass(&wndclass) == 0)
        {
            throw std::runtime_error("Window class failed to register");
        }
    }

    auto hwnd =
        CreateWindow(
            s_window_class_name.c_str(),
            "OpenWorld Engine",
            WS_VISIBLE | WS_TILEDWINDOW,
            CW_USEDEFAULT, CW_USEDEFAULT,
            1024, 768,
            NULL,
            NULL,
            hinst,
            reinterpret_cast<LPVOID>(this));

    if (hwnd == NULL)
    {
        throw std::runtime_error("Failed to create window");
    }
}

win32_window::~win32_window()
{
    if (m_hwnd != NULL)
    {
        DestroyWindow(m_hwnd);
    }
}

bool win32_window::is_minimized()
{
    throw_if_window_destroyed();
    return IsIconic(m_hwnd) != FALSE;
}

bool win32_window::is_maximized()
{
    throw_if_window_destroyed();
    return IsZoomed(m_hwnd) != FALSE;
}

bool win32_window::is_focused()
{
    throw_if_window_destroyed();
    return m_is_focused;
}

void* win32_window::handle()
{
    throw_if_window_destroyed();
    return static_cast<void*>(m_hwnd);
}

std::string win32_window::title()
{
    throw_if_window_destroyed();

    SetLastError(0);
    int len = GetWindowTextLength(m_hwnd) + 1;
    if (len == 1 && GetLastError() != 0)
    {
        throw std::runtime_error("Failed to get window title");
    }

    std::string s{};
    s.reserve(static_cast<size_t>(len));

    if (GetWindowText(m_hwnd, s.data(), static_cast<int>(s.capacity())) == 0)
    {
        throw std::runtime_error("Failed to get window title");
    }

    return s;
}

void win32_window::title(const std::string& new_title)
{
    throw_if_window_destroyed();

    if (SetWindowText(m_hwnd, new_title.c_str()) == FALSE)
    {
        throw std::runtime_error("Failed to set window title");
    }
}

void win32_window::focus()
{
    throw_if_window_destroyed();
    SetFocus(m_hwnd);
}

LRESULT CALLBACK win32_window::window_proc_static(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param)
{
    win32_window* window = nullptr;

    if (msg == WM_NCCREATE)
    {
        auto pcs = reinterpret_cast<CREATESTRUCT*>(l_param);

        window = reinterpret_cast<win32_window*>(pcs->lpCreateParams);
        window->m_hwnd = hwnd;

        SetLastError(0);
        if (SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window)) == 0)
        {
            if (GetLastError() != 0)
            {
                return FALSE;
            }
        }
    }
    else
    {
        window = reinterpret_cast<win32_window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
    }

    if (window != nullptr)
    {
        return window->window_proc(msg, w_param, l_param);
    }

    return DefWindowProc(hwnd, msg, w_param, l_param);
}

LRESULT win32_window::window_proc(UINT msg, WPARAM w_param, LPARAM l_param)
{
    switch (msg)
    {
    case WM_DESTROY:
        m_hwnd = NULL;

        if (m_is_top_level)
        {
            PostQuitMessage(0);
        }

        return FALSE;

    case WM_SETFOCUS:
        m_is_focused = true;
        break;

    case WM_KILLFOCUS:
        m_is_focused = false;
        break;
    }

    return DefWindowProc(m_hwnd, msg, w_param, l_param);
}

void win32_window::throw_if_window_destroyed() const
{
    if (m_hwnd == NULL)
    {
        throw std::runtime_error("Window has been destroyed");
    }
}