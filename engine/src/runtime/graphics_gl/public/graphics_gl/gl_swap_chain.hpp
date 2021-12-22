#pragma once

#include "core/platform/window.hpp"
#include "core/platform/win32/win32_api.hpp"

namespace openworld
{
    class gl_swap_chain final
    {
    public:
        gl_swap_chain(const std::shared_ptr<window>& window);
        gl_swap_chain(const gl_swap_chain&) = delete;

        virtual ~gl_swap_chain();

        void present();

    private:
        HWND m_hwnd;
        HDC m_hdc;
        HGLRC m_hglrc;
    };
}