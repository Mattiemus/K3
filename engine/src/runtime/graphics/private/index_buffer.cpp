#include "graphics.hpp"

using namespace openworld;

index_buffer::index_buffer(
    openworld::render_system& render_sys,
    index_format format,
    size_t index_count,
    resource_usage usage)
{
    if (usage == resource_usage::immutable)
    {
        throw graphics_exception("Must supply data for immutable resource");
    }

    if (index_count <= 0)
    {
        throw graphics_exception("Index count must be greater than zero");
    }

    if (!render_sys.is_supported<index_buffer>())
    {
        throw graphics_exception("Render system does not supported index buffers");
    }

    m_impl = render_sys.make_impl<index_buffer>(format, index_count, usage);
}

index_buffer::index_buffer(
    openworld::render_system& render_sys,
    index_format format,
    const memory_region& data,
    resource_usage usage)
{
    auto total_size_bytes = data.size_bytes();
    auto index_size = format_size(format);

    if (total_size_bytes == 0)
    {
        throw graphics_exception("Vertex count must be greater than zero");
    }

    if (data.size_element() != index_size || total_size_bytes % index_size != 0)
    {
        throw graphics_exception("Index format size mismatch");
    }

    if (!render_sys.is_supported<index_buffer>())
    {
        throw graphics_exception("Render system does not supported index buffers");
    }

    m_impl = render_sys.make_impl<index_buffer>(format, data, usage);
}
