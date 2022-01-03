#pragma once

namespace openworld
{
    class render_system;
    class render_context;      

    template <>
    class graphics_resource_traits<class vertex_buffer>
    {
    public:
        using impl = vertex_buffer_impl;
        using impl_factory = vertex_buffer_impl_factory;

        static constexpr graphics_resource_type resource_type = graphics_resource_type::vertex_buffer;
    };

	class vertex_buffer final :
        public graphics_resource
	{
	public:
        vertex_buffer(
            openworld::render_system& render_sys,
            const vertex_layout& layout,
            size_t vertex_count,
            resource_usage usage = resource_usage::static_usage);

        vertex_buffer(
            openworld::render_system& render_sys,
            const vertex_layout& layout,
            const memory_region& data,
            resource_usage usage = resource_usage::static_usage);

        vertex_buffer(
            openworld::render_system& render_sys,
            const vertex_layout& layout,
            const std::vector<memory_region>& data,
            resource_usage usage = resource_usage::static_usage);
        
        virtual ~vertex_buffer() {}

        virtual graphics_resource_impl* impl() const override
        {
            return m_impl.get();
        }

        openworld::vertex_buffer_impl* vertex_buffer_impl() const
        {
            return m_impl.get();
        }

        const vertex_layout& layout() const
        {
            return m_impl->layout();
        }

        size_t vertex_count() const
        {
            return m_impl->vertex_count();
        }

        resource_usage usage() const
        {
            return m_impl->usage();
        }

        void get_interleaved_data(
            const std::vector<memory_region>& data)
        {
            m_impl->get_interleaved_data(data);
        }

        void set_interleaved_data(
            render_context& render_ctx,
            const std::vector<memory_region>& data)
        {
            m_impl->set_interleaved_data(render_ctx, data);
        }

        void get_data(
            const memory_region& data,
            size_t start_index,
            size_t element_count,
            size_t buffer_read_start_offset,
            size_t vertex_stride)
        {
            m_impl->get_data(
                data,
                start_index,
                element_count,
                buffer_read_start_offset,
                vertex_stride);
        }

        void set_data(
            render_context& render_ctx,
            const memory_region& data,
            size_t start_index,
            size_t element_count,
            size_t buffer_write_start_offset,
            size_t vertex_stride,
            data_write_options write_opts)
        {
            m_impl->set_data(
                render_ctx,
                data,
                start_index,
                element_count,
                buffer_write_start_offset,
                vertex_stride,
                write_opts);
        }

    private:
        std::unique_ptr<openworld::vertex_buffer_impl> m_impl;
	};
}