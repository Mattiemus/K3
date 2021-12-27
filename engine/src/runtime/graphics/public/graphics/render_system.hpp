#pragma once

namespace openworld
{
    class render_context;

    class render_system
    {
    public:
        virtual ~render_system() = 0 {}

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

        virtual graphics_resource_impl_factory& get_impl_factory(
            graphics_resource_type resource_type) = 0;

        virtual bool is_supported(
            graphics_resource_type resource_type) = 0;

        template <typename Resource>
        typename graphics_resource_traits<Resource>::impl_factory& get_impl_factory()
        {
            auto& factory = get_impl_factory(graphics_resource_traits<Resource>::resource_type);
            return dynamic_cast<graphics_resource_traits<Resource>::impl_factory&>(factory);
        }

        template <typename Resource>
        typename bool is_supported()
        {
            return is_supported(graphics_resource_traits<Resource>::resource_type);
        }

        template<typename Resource, typename... Args>
        std::unique_ptr<typename graphics_resource_traits<Resource>::impl> make_impl(Args&&... args)
        {
            auto& impl_factory = get_impl_factory<Resource>();
            return impl_factory.create_impl(args...);
        }
    };
}