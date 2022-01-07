#include "graphics.hpp"

using namespace openworld;

texture_1d::texture_1d(
	openworld::render_system& render_sys,
	size_t width,
	resource_usage usage)
{
	auto impl = render_sys.make_impl<texture_1d>(width, false, surface_format::color, usage);
	bind_impl(std::move(impl));
}

texture_1d::texture_1d(
	openworld::render_system& render_sys,
	size_t width,
	bool gen_mip_maps,
	surface_format format,
	resource_usage usage)
{
	auto impl = render_sys.make_impl<texture_1d>(width, gen_mip_maps, format, usage);
	bind_impl(std::move(impl));
}

texture_1d::texture_1d(
	openworld::render_system& render_sys,
	size_t width,
	bool gen_mip_maps,
	surface_format format,
	const memory_region& data,
	resource_usage usage)
{
	std::vector<memory_region> data_arr { data };
	auto impl = render_sys.make_impl<texture_1d>(width, gen_mip_maps, format, usage, data_arr);
	bind_impl(std::move(impl));
}

texture_1d::texture_1d(
	openworld::render_system& render_sys,
	size_t width,
	bool gen_mip_maps,
	surface_format format,
	const std::vector<memory_region>& data,
	resource_usage usage)
{
	auto impl = render_sys.make_impl<texture_1d>(width, gen_mip_maps, format, usage, data);
	bind_impl(std::move(impl));
}