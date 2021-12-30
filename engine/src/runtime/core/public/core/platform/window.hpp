#pragma once

namespace openworld
{
    class window
    {
    public:
        virtual ~window() = 0 {}

        /*event TypedEventHandler<IWindow> ClientSizeChanged;
        event TypedEventHandler<IWindow> OrientationChanged;
        event TypedEventHandler<IWindow> GotFocus;
        event TypedEventHandler<IWindow> LostFocus;
        event TypedEventHandler<IWindow> ResumeRendering;
        event TypedEventHandler<IWindow> SuspendRendering;
        event TypedEventHandler<IWindow> Paint;
        event TypedEventHandler<IWindow> Closed;
        event TypedEventHandler<IWindow> Disposed;

        event TypedEventHandler<IWindow, MouseStateEventArgs> MouseClick;
        event TypedEventHandler<IWindow, MouseStateEventArgs> MouseDoubleClick;
        event TypedEventHandler<IWindow, MouseStateEventArgs> MouseUp;
        event TypedEventHandler<IWindow, MouseStateEventArgs> MouseDown;
        event TypedEventHandler<IWindow, MouseStateEventArgs> MouseMove;
        event TypedEventHandler<IWindow, MouseStateEventArgs> MouseWheel;

        event TypedEventHandler<IWindow, KeyboardStateEventArgs> KeyDown;
        event TypedEventHandler<IWindow, KeyboardStateEventArgs> KeyPress;
        event TypedEventHandler<IWindow, KeyboardStateEventArgs> KeyUp;

        event TypedEventHandler<IWindow> MouseEnter;
        event TypedEventHandler<IWindow> MouseLeave;
        event TypedEventHandler<IWindow> MouseHover;

        bool EnableUserResizing{ get; set; }
        bool EnableInputEvents{ get; set; }
        bool EnablePaintEvents{ get; set; }
        bool EnableResizeRedraw{ get; set; }
        bool IsMouseVisible{ get; set; }*/

        virtual bool is_minimized() = 0;
        virtual bool is_maximized() = 0;

        //bool IsMouseInsideWindow{ get; }

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