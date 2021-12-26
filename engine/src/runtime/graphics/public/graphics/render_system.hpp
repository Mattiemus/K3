#pragma once

#include <string>

#include "core/math/color.hpp"
#include "graphics/enums.hpp"

namespace openworld
{
    class render_context;

    class render_system final
    {
    public:
        render_system();
        render_system(const render_system&) = delete;
        render_system(render_system&& other) noexcept :
            m_pimpl(other.m_pimpl)
        {
            other.m_pimpl = nullptr;
        }
        ~render_system();

        render_system& operator =(const render_system&) = delete;
        render_system& operator =(render_system&& other) noexcept
        {
            m_pimpl = other.m_pimpl;
            other.m_pimpl = nullptr;
            return *this;
        }

        constexpr void* pimpl() const noexcept
        {
            return m_pimpl;
        }

        std::string platform();
        render_context& immediate_context();
        //IGraphicsAdapter Adapter{ get; }
        //bool AreCommandListsSupported{ get; }
        //IPredefinedBlendStateProvider PredefinedBlendStates{ get; }
        //IPredefinedDepthStencilStateProvider PredefinedDepthStencilStates{ get; }
        //IPredefinedRasterizerStateProvider PredefinedRasterizerStates{ get; }
        //IPredefinedSamplerStateProvider PredefinedSamplerStates{ get; }
        //StandardEffectLibrary StandardEffects{ get; }
        //IDeferredRenderContext CreateDeferredRenderContext();
        //bool IsSupported<T>() where T : GraphicsResource;

    private:
        void* m_pimpl = nullptr;
    };
}