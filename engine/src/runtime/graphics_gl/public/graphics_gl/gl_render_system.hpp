#pragma once

#include "graphics.hpp"

namespace openworld
{
	class gl_render_system final :
		public render_system
	{
        OPENWORLD_DELETE_COPY_OPERATORS(gl_render_system);

    public:
        gl_render_system();
        virtual ~gl_render_system() {}

        gl_render_context& gl_immediate_context()
        {
            return m_immediate_ctx;
        }

        virtual std::string platform() override
        {
            return "opengl";
        }

        virtual render_context& immediate_context() override
        {
            return m_immediate_ctx;
        }

        virtual const graphics_adapter& adapter() const override
        {
            throw std::runtime_error("not implemented");
        }

        //bool AreCommandListsSupported{ get; }
        //IPredefinedBlendStateProvider PredefinedBlendStates{ get; }
        //IPredefinedDepthStencilStateProvider PredefinedDepthStencilStates{ get; }
        //IPredefinedRasterizerStateProvider PredefinedRasterizerStates{ get; }
        //IPredefinedSamplerStateProvider PredefinedSamplerStates{ get; }
        //StandardEffectLibrary StandardEffects{ get; }
        //IDeferredRenderContext CreateDeferredRenderContext();

        virtual graphics_resource_impl_factory& get_impl_factory(graphics_resource_type resource_type) override;
        virtual bool is_supported(graphics_resource_type resource_type) override;

    private:
        gl_render_context m_immediate_ctx;
        gl_vertex_buffer_impl_factory m_vertex_buffer_impl_factory;
        gl_index_buffer_impl_factory m_index_buffer_impl_factory;
	};
}