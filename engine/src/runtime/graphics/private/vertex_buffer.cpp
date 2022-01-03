#include "graphics.hpp"

using namespace openworld;

vertex_buffer::vertex_buffer(
    openworld::render_system& render_sys,
    const vertex_layout& layout,
    size_t vertex_count,
    resource_usage usage)
{
    m_impl = render_sys.make_impl<vertex_buffer>(layout, vertex_count, usage);
}

vertex_buffer::vertex_buffer(
    openworld::render_system& render_sys,
    const vertex_layout& layout,
    const memory_region& data,
    resource_usage usage)
{
    m_impl = render_sys.make_impl<vertex_buffer>(layout, data, usage);
}

vertex_buffer::vertex_buffer(
    openworld::render_system& render_sys,
    const vertex_layout& layout,
    const std::vector<memory_region>& data,
    resource_usage usage)
{
    m_impl = render_sys.make_impl<vertex_buffer>(layout, data, usage);
}