#include "graphics.hpp"

using namespace openworld;

index_buffer::index_buffer(
    openworld::render_system& render_sys,
    index_format format,
    size_t index_count,
    resource_usage usage) :
    m_impl(render_sys.make_impl<index_buffer>(format, index_count, usage))
{}

index_buffer::index_buffer(
    openworld::render_system& render_sys,
    index_format format,
    const std::span<const std::byte>& data,
    resource_usage usage) :
    m_impl(render_sys.make_impl<index_buffer>(format, data, usage))
{}

index_buffer::index_buffer(
    openworld::render_system& render_sys,
    const std::span<const unsigned int>& data,
    resource_usage usage) :
    m_impl(render_sys.make_impl<index_buffer>(index_format::bits32, std::as_bytes(data), usage))
{}

index_buffer::index_buffer(
    openworld::render_system& render_sys,
    const std::span<const unsigned short>& data,
    resource_usage usage) :
    m_impl(render_sys.make_impl<index_buffer>(index_format::bits16, std::as_bytes(data), usage))
{}