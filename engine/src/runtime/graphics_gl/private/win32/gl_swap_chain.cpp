#include "graphics_gl.hpp"

using namespace openworld;

gl_swap_chain::gl_swap_chain(const std::shared_ptr<window>& window) :
    m_hwnd(nullptr), m_hdc(nullptr), m_hglrc(nullptr)
{
    m_hwnd = static_cast<HWND>(window->handle());
    m_hdc = GetDC(m_hwnd);

    PIXELFORMATDESCRIPTOR pfd =
    {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER, // Flags
        PFD_TYPE_RGBA, // The kind of framebuffer. RGBA or palette.
        32, // Colordepth of the framebuffer.
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        24, // Number of bits for the depthbuffer
        8, // Number of bits for the stencilbuffer
        0, // Number of Aux buffers in the framebuffer.
        PFD_MAIN_PLANE,
        0,
        0, 0, 0
    };

    int pixel_fmt = ChoosePixelFormat(m_hdc, &pfd);
    SetPixelFormat(m_hdc, pixel_fmt, &pfd);

    m_hglrc = wglCreateContext(m_hdc);
    wglMakeCurrent(m_hdc, m_hglrc);

    GLenum err = glewInit();
    if (err != GLEW_OK)
    {
        // TODO: error
    }
}

gl_swap_chain::~gl_swap_chain()
{
    wglDeleteContext(m_hglrc);
}

void gl_swap_chain::present()
{
    SwapBuffers(m_hdc);
}