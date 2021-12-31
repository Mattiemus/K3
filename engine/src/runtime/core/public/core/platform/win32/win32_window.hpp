#pragma once

namespace openworld
{
    class win32_window final :
        public window
    {
    public:
        win32_window(HINSTANCE hinst, bool is_top_level);
        virtual ~win32_window();

        virtual bool enable_input_events() override;
        virtual void enable_input_events(bool enable) override;
        virtual bool is_minimized() override;
        virtual bool is_maximized() override;
        virtual bool is_mouse_inside_window() override;
        virtual bool is_focused() override;
        virtual void* handle() override;
        virtual std::string title() override;
        virtual void title(const std::string& new_title) override;

        virtual void focus() override;

    private:
        static std::string s_window_class_name;

        HWND m_hwnd = NULL;
        bool m_is_input_events_enabled = true;
        bool m_is_top_level = false;
        bool m_is_focused = false;
        bool m_is_mouse_over = false;

        static LRESULT CALLBACK window_proc_static(HWND hwnd, UINT msg, WPARAM w_param, LPARAM l_param);

        LRESULT window_proc(UINT msg, WPARAM w_param, LPARAM l_param);
        
        void throw_if_window_destroyed() const;
    };
}