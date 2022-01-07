#pragma once

namespace openworld
{
    class render_system;
    class render_context;

    template <>
    class graphics_resource_traits<class index_buffer>
    {
    public:
        using impl = index_buffer_impl;
        using impl_factory = index_buffer_impl_factory;

        static constexpr graphics_resource_type resource_type = graphics_resource_type::index_buffer;
    };

    class index_buffer final :
        public graphics_resource
    {
        OPENWORLD_DELETE_COPY_OPERATORS(index_buffer);

    public:
        index_buffer(
            openworld::render_system& render_sys,
            index_format format,
            size_t index_count,
            resource_usage usage = resource_usage::static_usage);

        index_buffer(
            openworld::render_system& render_sys,
            index_format format,
            const memory_region& data,
            resource_usage usage = resource_usage::static_usage);

        virtual ~index_buffer() {}

        openworld::index_buffer_impl& index_buffer_impl() const
        {
            return static_cast<openworld::index_buffer_impl&>(impl());
        }

        size_t index_count() const
        {
            return index_buffer_impl().index_count();
        }

        index_format format() const
        {
            return index_buffer_impl().format();
        }

        resource_usage usage() const
        {
            return index_buffer_impl().usage();
        }

        void get_data(
            const memory_region& data,
            size_t start_index,
            size_t element_count,
            size_t buffer_read_start_offset)
        {
            index_buffer_impl().get_data(
                data, 
                start_index,
                element_count,
                buffer_read_start_offset);
        }

        void set_data(
            render_context& render_ctx,
            const memory_region& data,
            size_t start_index,
            size_t element_count,
            size_t buffer_write_start_offset,
            data_write_options write_opts)
        {
            index_buffer_impl().set_data(
                render_ctx,
                data,
                start_index,
                element_count,
                buffer_write_start_offset,
                write_opts);
        }
    };
}