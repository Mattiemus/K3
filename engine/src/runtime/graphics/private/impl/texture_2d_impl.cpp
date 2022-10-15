#include "graphics.hpp"

using namespace openworld;

texture_2d_impl::texture_2d_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	size_t width,
	size_t height,
	bool gen_mip_maps,
	surface_format format,
	resource_usage usage) :
	texture_impl(resource_id, render_system, format, usage),
	m_width(width),
	m_height(height)
{
	if (usage == resource_usage::immutable)
	{
		throw graphics_exception("Must supply data for immutable resource");
	}

	auto max_size = render_system.adapter().maximum_texture_2d_size();
	if (m_width > max_size || m_height > max_size)
	{
		throw graphics_exception("Bad texture size");
	}

	if (!render_system.adapter().check_texture_format(format, texture_dimension::two))
	{
		throw graphics_exception("Bad texture size");
	}

	m_mip_count = gen_mip_maps ? texture::calculate_mip_map_count(width, height) : 1;
}

texture_2d_impl::texture_2d_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	size_t width,
	size_t height,
	bool gen_mip_maps,
	surface_format format,
	resource_usage usage,
	const std::vector<memory_region>& data) :
	texture_impl(resource_id, render_system, format, usage),
	m_width(width),
	m_height(height)
{
	auto max_size = render_system.adapter().maximum_texture_2d_size();
	if (m_width > max_size || m_height > max_size)
	{
		throw graphics_exception("Bad texture size");
	}

	if (!render_system.adapter().check_texture_format(format, texture_dimension::two))
	{
		throw graphics_exception("Bad texture size");
	}

	m_mip_count = gen_mip_maps ? texture::calculate_mip_map_count(width, height) : 1;

	if (data.size() != m_mip_count)
	{
		throw graphics_exception("Texture data size mismatch");
	}

	for (size_t mip_level = 0; mip_level < data.size(); mip_level++)
	{
		const auto& data_memory = data[mip_level];
		auto mip_size_in_bytes = texture::calculate_mip_level_size_in_bytes(mip_level, width, height, format);

		if (data_memory.size_bytes() > mip_size_in_bytes)
		{
			throw graphics_exception("Data size larger than mip level");
		}
	}
}

texture_2d_impl::~texture_2d_impl()
{}

texture_2d_impl_factory::~texture_2d_impl_factory()
{}