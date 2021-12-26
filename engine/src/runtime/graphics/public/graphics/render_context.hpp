#pragma once

#include "core/math/color.hpp"
#include "graphics/enums.hpp"
#include "graphics/vertex_buffer_binding.hpp"

namespace openworld
{
    class render_context final
    {
    public:
        render_context();
        render_context(const render_context&) = delete;
        render_context(render_context&& other) noexcept :
            m_pimpl(other.m_pimpl)
        {
            other.m_pimpl = nullptr;
        }
        ~render_context();

        render_context& operator =(const render_context&) = delete;
        render_context& operator =(render_context&& other) noexcept
        {
            m_pimpl = other.m_pimpl;
            other.m_pimpl = nullptr;
            return *this;
        }

        constexpr void* pimpl() const noexcept
        {
            return m_pimpl;
        }

        bool is_immediate_context();

        //IRenderSystem RenderSystem{ get; }
        //BlendState BlendState{ get; set; }
        //RasterizerState RasterizerState{ get; set; }
        //DepthStencilState DepthStencilState{ get; set; }
        //EnforcedRenderState EnforcedRenderState{ get; set; }
        //Rectangle ScissorRectangle{ get; set; }
        //Color BlendFactor{ get; set; }
        //int BlendSampleMask{ get; set; }
        //int ReferenceStencil{ get; set; }
        //Camera Camera{ get; set; }
        //SwapChain BackBuffer{ get; set; }

        //IShaderStage GetShaderStage(ShaderStage shaderStage);
        //IEnumerable<IShaderStage> GetShaderStages();
        //bool IsShaderStageSupported(ShaderStage shaderStage);
        //T GetExtension<T>() where T : IRenderContextExtension;
        //IEnumerable<IRenderContextExtension> GetExtensions();
        //bool IsExtensionSupported<T>() where T : IRenderContextExtension;
        //void ExecuteCommandList(ICommandList commandList, bool restoreImmediateContextState);
        //void SetIndexBuffer(IndexBuffer indexBuffer);
        void set_vertex_buffer(const vertex_buffer_binding& vertex_buffer);
        //void SetVertexBuffers(params VertexBufferBinding[] vertexBuffers);
        //void SetStreamOutputTarget(StreamOutputBufferBinding streamOutputBuffer);
        //void SetStreamOutputTargets(params StreamOutputBufferBinding[] streamOutputBuffers);
        //void SetRenderTarget(SetTargetOptions options, IRenderTarget renderTarget);
        //void SetRenderTargets(SetTargetOptions options, params IRenderTarget[] renderTargets);
        //IndexBuffer GetIndexBuffer();
        //VertexBufferBinding[] GetVertexBuffers();
        //StreamOutputBufferBinding[] GetStreamOutputTargets();
        //IRenderTarget[] GetRenderTargets();
        //void ClearState();

        void clear(const color& clear_color);

        void clear(
            clear_options options,
            const color& clear_color,
            float depth,
            int stencil);

        void draw(
            primitive_type prim_type,
            size_t vertex_count,
            size_t start_vertex_index);

        void draw_indexed(
            primitive_type prim_type,
            size_t index_count,
            size_t start_index,
            size_t base_vertex_offset);

        void draw_indexed_instanced(
            primitive_type prim_type,
            size_t index_count_per_instance,
            size_t instance_count,
            size_t start_index,
            size_t base_vertex_offset,
            size_t start_instance_offset);
        
        void draw_instanced(
            primitive_type prim_type,
            size_t vertex_count_per_instance,
            size_t instance_count,
            size_t base_vertex_offset,
            size_t start_instance_offset);
        
        void draw_auto(primitive_type prim_type);

        void flush();

    private:
        void* m_pimpl;
    };
}