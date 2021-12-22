#pragma once

#include "graphics/render_system.hpp"

namespace openworld
{
    class gl_render_system final :
        public render_system
    {
    public:
        gl_render_system();
        virtual ~gl_render_system();

        virtual std::string platform() override
        {
            return "opengl";
        }

        virtual render_context& immediate_context() override
        {
            return m_render_context;
        }

        //IGraphicsAdapter Adapter{ get; }

        //bool AreCommandListsSupported{ get; }

        //IPredefinedBlendStateProvider PredefinedBlendStates{ get; }

        //IPredefinedDepthStencilStateProvider PredefinedDepthStencilStates{ get; }

        //IPredefinedRasterizerStateProvider PredefinedRasterizerStates{ get; }

        //IPredefinedSamplerStateProvider PredefinedSamplerStates{ get; }

        //StandardEffectLibrary StandardEffects{ get; }

        //IDeferredRenderContext CreateDeferredRenderContext();

        //T GetImplementationFactory<T>() where T : IGraphicsResourceImplFactory;

        //bool TryGetImplementationFactory<T>(out T implementationFactory) where T : IGraphicsResourceImplFactory;

        //bool IsSupported<T>() where T : GraphicsResource;

    private:
        gl_render_context m_render_context;
    };
}