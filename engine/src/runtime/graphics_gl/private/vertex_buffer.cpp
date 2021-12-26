#include "graphics_gl.hpp"
#include "gl_helpers.hpp"
#include "graphics/vertex_buffer.hpp"

using namespace openworld;

vertex_buffer::vertex_buffer(const vertex_layout& layout, size_t vertex_count) :
    m_vertex_layout(layout), m_vertex_count(vertex_count), m_resource_usage(resource_usage::static_usage)
{
    throw std::runtime_error("not implemented");
}

vertex_buffer::vertex_buffer(const vertex_layout& layout, size_t vertex_count, resource_usage usage) :
    m_vertex_layout(layout), m_vertex_count(vertex_count), m_resource_usage(usage)
{
    throw std::runtime_error("not implemented");
}

vertex_buffer::vertex_buffer(const vertex_layout& layout, const std::span<const std::byte>& data) :
    m_vertex_layout(layout), m_vertex_count(0), m_resource_usage(resource_usage::static_usage)
{
    GLuint buffer_id = 0;
    glCreateBuffers(1, &buffer_id);
    m_pimpl = to_pimpl(buffer_id);

    glNamedBufferStorage(buffer_id, data.size(), data.data(), GL_MAP_WRITE_BIT | GL_DYNAMIC_STORAGE_BIT);
}

vertex_buffer::vertex_buffer(const vertex_layout& layout, const std::span<const std::byte>& data, resource_usage usage) :
    m_vertex_layout(layout), m_vertex_count(0), m_resource_usage(usage)
{
    throw std::runtime_error("not implemented");
}

vertex_buffer::vertex_buffer(const vertex_layout& layout, const std::span<const std::span<const std::byte>>& data) :
    m_vertex_layout(layout), m_vertex_count(0), m_resource_usage(resource_usage::static_usage)
{
    throw std::runtime_error("not implemented");
}

vertex_buffer::vertex_buffer(const vertex_layout& layout, const std::span<const std::span<const std::byte>>& data, resource_usage usage) :
    m_vertex_layout(layout), m_vertex_count(0), m_resource_usage(usage)
{
    throw std::runtime_error("not implemented");
}

vertex_buffer::~vertex_buffer()
{
    auto buffer_id = from_pimpl(m_pimpl);
    glDeleteBuffers(1, &buffer_id);
}

void vertex_buffer::get_data(
    const std::span<std::byte>& data,
    size_t element_count,
    size_t element_size,
    size_t read_start_offset,
    size_t vertex_stride)
{
    throw std::runtime_error("not implemented");
}

void vertex_buffer::set_data(
    render_context& render_ctx,
    const std::span<const std::byte>& data,
    size_t element_count,
    size_t element_size,
    size_t write_start_offset,
    size_t vertex_stride,
    data_write_options write_opts)
{
    auto buffer_id = from_pimpl(m_pimpl);

    glBindBuffer(GL_ARRAY_BUFFER, buffer_id);
    glBufferData(GL_ARRAY_BUFFER, element_count * element_size, data.data(), GL_STATIC_DRAW);
}