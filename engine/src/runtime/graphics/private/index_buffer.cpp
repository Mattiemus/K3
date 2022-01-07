#include "graphics.hpp"

using namespace openworld;

index_buffer::index_buffer(
    openworld::render_system& render_sys,
    index_format format,
    size_t index_count,
    resource_usage usage)
{
    auto impl = render_sys.make_impl<index_buffer>(format, index_count, usage);
    bind_impl(std::move(impl));
}

index_buffer::index_buffer(
    openworld::render_system& render_sys,
    index_format format,
    const memory_region& data,
    resource_usage usage)
{
    auto impl = render_sys.make_impl<index_buffer>(format, data, usage);
    bind_impl(std::move(impl));
}
