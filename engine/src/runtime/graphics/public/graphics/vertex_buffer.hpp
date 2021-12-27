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
            const std::span<const std::byte>& data,
            resource_usage usage = resource_usage::static_usage);

        vertex_buffer(
            openworld::render_system& render_sys,
            const vertex_layout& layout,
            const std::span<const std::span<const std::byte>>& data,
            resource_usage usage = resource_usage::static_usage);
        
        virtual ~vertex_buffer() {}

        virtual graphics_resource_impl* impl() const noexcept override
        {
            return m_impl.get();
        }

        openworld::vertex_buffer_impl* vertex_buffer_impl() const noexcept
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
            const std::span<const std::span<std::byte>>& data)
        {
            m_impl->get_interleaved_data(data);
        }

        void set_interleaved_data(
            render_context& render_ctx,
            const std::span<const std::span<const std::byte>>& data)
        {
            m_impl->set_interleaved_data(render_ctx, data);
        }

        void get_data(
            const std::span<std::byte>& data,
            size_t element_count,
            size_t element_size,
            size_t read_start_offset,
            size_t vertex_stride)
        {
            m_impl->get_data(
                data,
                element_count,
                element_size,
                read_start_offset,
                vertex_stride);
        }

        template <typename Element>
        void get_data(
            const std::span<Element>& data,
            size_t vertex_stride)
        {
            m_impl->get_data(
                std::as_bytes(data),
                data.size(),
                sizeof(Element),
                0,
                vertex_stride);
        }

        void set_data(
            render_context& render_ctx,
            const std::span<const std::byte>& data,
            size_t element_count,
            size_t element_size,
            size_t write_start_offset,
            size_t vertex_stride,
            data_write_options write_opts)
        {
            m_impl->set_data(
                render_ctx,
                data,
                element_count,
                element_size,
                write_start_offset,
                vertex_stride,
                write_opts);
        }

        template <typename Element>
        void set_data(
            render_context& render_ctx,
            const std::span<const Element>& data,
            size_t vertex_stride,
            data_write_options write_opts)
        {
            m_impl->set_data(
                render_ctx,
                std::as_bytes(data),
                data.size(),
                sizeof(Element),
                0,
                vertex_stride,
                write_opts);
        }

    private:
        std::unique_ptr<openworld::vertex_buffer_impl> m_impl;
	};
}