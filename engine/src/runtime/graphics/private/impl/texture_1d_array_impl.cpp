#include "graphics.hpp"

using namespace openworld;

texture_1d_array_impl::texture_1d_array_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	size_t width,
	size_t array_count,
	bool gen_mip_maps,
	surface_format format,
	resource_usage usage) :
	texture_1d_impl(resource_id, render_system, width, gen_mip_maps, format, usage),
	m_array_count(array_count)
{
	if (m_array_count <= 0)
	{
		throw graphics_exception("Array count cannot be zero");
	}
}

texture_1d_array_impl::texture_1d_array_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	size_t width,
	bool gen_mip_maps,
	surface_format format,
	resource_usage usage,
	const std::vector<memory_region>& data) :
	texture_1d_impl(resource_id, render_system, width, gen_mip_maps, format, usage),
	m_array_count(data.size())
{
	if (m_array_count <= 0)
	{
		throw graphics_exception("Array count cannot be zero");
	}
}

texture_1d_array_impl::~texture_1d_array_impl()
{}

texture_1d_array_impl_factory::~texture_1d_array_impl_factory()
{}