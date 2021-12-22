#pragma once

#include <string>

#include "core/math/color.hpp"
#include "graphics/enums.hpp"

namespace openworld
{
    class render_context;

    class render_system
    {
    public:
        virtual ~render_system() = 0 {};

        virtual std::string platform() = 0;
        virtual render_context& immediate_context() = 0;
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
    };
}