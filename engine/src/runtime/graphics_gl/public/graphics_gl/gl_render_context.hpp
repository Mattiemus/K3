#pragma once

namespace openworld
{
	class gl_render_context final :
		public render_context
	{
    public:
        gl_render_context();
        virtual ~gl_render_context();

        virtual bool is_immediate_context() override;

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
        virtual void set_vertex_buffer(const vertex_buffer_binding& vertex_buffer) override;
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

        virtual void clear(const color& clear_color) override;

        virtual void clear(
            clear_options options,
            const color& clear_color,
            float depth,
            int stencil) override;

        virtual void draw(
            primitive_type prim_type,
            size_t vertex_count,
            size_t start_vertex_index) override;

        virtual void draw_indexed(
            primitive_type prim_type,
            size_t index_count,
            size_t start_index,
            size_t base_vertex_offset) override;

        virtual void draw_indexed_instanced(
            primitive_type prim_type,
            size_t index_count_per_instance,
            size_t instance_count,
            size_t start_index,
            size_t base_vertex_offset,
            size_t start_instance_offset) override;

        virtual void draw_instanced(
            primitive_type prim_type,
            size_t vertex_count_per_instance,
            size_t instance_count,
            size_t base_vertex_offset,
            size_t start_instance_offset) override;

        virtual void draw_auto(primitive_type prim_type) override;

        virtual void flush() override;

    private:
        GLuint m_vao;
	};
}