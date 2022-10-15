#pragma once

namespace openworld
{
    class window
    {
    public:
        signal<window&> client_size_changed;
        //event TypedEventHandler<IWindow> OrientationChanged;
        signal<window&> got_focus;
        signal<window&> lost_focus;
        //event TypedEventHandler<IWindow> ResumeRendering;
        //event TypedEventHandler<IWindow> SuspendRendering;
        //event TypedEventHandler<IWindow> Paint;
        //event TypedEventHandler<IWindow> Closed;
        //event TypedEventHandler<IWindow> Disposed;

        signal<window&> mouse_enter;
        signal<window&> mouse_leave;
        //event TypedEventHandler<IWindow> MouseHover;
        
        //event TypedEventHandler<IWindow, MouseStateEventArgs> MouseClick;
        //event TypedEventHandler<IWindow, MouseStateEventArgs> MouseDoubleClick;
        //event TypedEventHandler<IWindow, MouseStateEventArgs> MouseUp;
        //event TypedEventHandler<IWindow, MouseStateEventArgs> MouseDown;
        //event TypedEventHandler<IWindow, MouseStateEventArgs> MouseMove;
        //event TypedEventHandler<IWindow, MouseStateEventArgs> MouseWheel;

        //event TypedEventHandler<IWindow, KeyboardStateEventArgs> KeyDown;
        //event TypedEventHandler<IWindow, KeyboardStateEventArgs> KeyPress;
        //event TypedEventHandler<IWindow, KeyboardStateEventArgs> KeyUp;

        virtual ~window() = 0;

        //bool EnableUserResizing{ get; set; }
        virtual bool enable_input_events() = 0;
        virtual void enable_input_events(bool enable) = 0;
        //bool EnablePaintEvents{ get; set; }
        //bool EnableResizeRedraw{ get; set; }
        //bool IsMouseVisible{ get; set; }
        virtual bool is_minimized() = 0;
        virtual bool is_maximized() = 0;
        virtual bool is_mouse_inside_window() = 0;
        //bool IsFullScreen{ get; set; }
        //bool IsVisible{ get; set; }
        //bool IsTopLevelWindow{ get; }
        //bool IsDisposed{ get; }
        virtual bool is_focused() = 0;
        //Int2 Location{ get; set; }
        //Rectangle ClientBounds{ get; }
        //Rectangle ScreenBounds{ get; }
        virtual void* handle() = 0;
        //SwapChain SwapChain{ get; }        
        virtual std::string title() = 0;
        virtual void title(const std::string& new_title) = 0;
        //Object NativeWindow{ get; }
        //Object Tag{ get; }
        //ApplicationHost Host{ get; }

        virtual void focus() = 0;
        //void CenterToScreen();
        //void Close();
        //void Repaint();
        //void Reset(PresentationParameters pp);
        //void Resize(int width, int height);
    };
}