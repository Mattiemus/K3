#pragma once

#include "graphics/render_context.hpp"
#include "graphics/vertex_buffer.hpp"

namespace openworld
{
    enum class data_write_options
    {
        none
    };

    class gl_vertex_buffer final
        : public vertex_buffer
    {
    public:
        gl_vertex_buffer();
        gl_vertex_buffer(const gl_vertex_buffer&) = delete;
        gl_vertex_buffer(gl_vertex_buffer&& other) noexcept;

        virtual ~gl_vertex_buffer();

        GLuint id() const
        {
            return m_buffer_id;
        }

        // void GetInterleavedData(params IDataBuffer[] data);
        // void SetInterleavedData(IRenderContext renderContext, params IReadOnlyDataBuffer[] data);

        virtual void get_data(
            const std::span<std::byte>& data,
            size_t element_count,
            size_t element_size,
            size_t read_start_offset,
            size_t vertex_stride) override;

        virtual void set_data(
            render_context& render_ctx,
            const std::span<const std::byte>& data,
            size_t element_count,
            size_t element_size,
            size_t write_start_offset,
            size_t vertex_stride,
            data_write_options write_opts) override;

    private:
        GLuint m_buffer_id;
    };
}