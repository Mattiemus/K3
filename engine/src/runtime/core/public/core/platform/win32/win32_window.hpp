#pragma once

#include "core/platform/win32/win32_api.hpp"
#include "core/platform/window.hpp"

namespace openworld
{
    class win32_window final :
        public window
    {
    public:
        win32_window(HINSTANCE hinst, bool is_top_level);
        virtual ~win32_window();

        virtual void* handle() override;

        virtual std::string get_title() override;
        virtual void set_title(const std::string& new_title) override;

    private:
        static std::string s_window_class_name;

        HWND m_hwnd = NULL;
        bool m_is_top_level = false;

        static LRESULT CALLBACK window_proc_static(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param);

        LRESULT window_proc(UINT msg, WPARAM w_param, LPARAM l_param);
        
        void throw_if_window_destroyed() const;
    };
}