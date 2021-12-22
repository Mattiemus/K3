#include "graphics_gl.hpp"

using namespace openworld;

gl_vertex_buffer::gl_vertex_buffer() :
    m_buffer_id(0)
{
    glGenBuffers(1, &m_buffer_id);
}

gl_vertex_buffer::gl_vertex_buffer(gl_vertex_buffer&& other) noexcept :
    m_buffer_id(other.m_buffer_id)
{
    other.m_buffer_id = 0;
}

gl_vertex_buffer::~gl_vertex_buffer()
{
    glDeleteBuffers(1, &m_buffer_id);
}

void gl_vertex_buffer::get_data(
    const std::span<std::byte>& data,
    size_t element_count,
    size_t element_size,
    size_t read_start_offset,
    size_t vertex_stride)
{
    // TOOD
}

void gl_vertex_buffer::set_data(
    render_context& render_ctx,
    const std::span<const std::byte>& data,
    size_t element_count,
    size_t element_size,
    size_t write_start_offset,
    size_t vertex_stride,
    data_write_options write_opts)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
    glBufferData(GL_ARRAY_BUFFER, element_count * element_size, data.data(), GL_STATIC_DRAW);
}