#include "graphics.hpp"

using namespace openworld;

index_buffer_impl::index_buffer_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	index_format format,
	size_t index_count,
	resource_usage usage) :
	graphics_resource_impl(resource_id, render_system),
	m_index_count(index_count),
	m_index_format(format),
	m_usage(usage)
{
	if (usage == resource_usage::immutable)
	{
		throw graphics_exception("Must supply data for immutable resource");
	}

	if (index_count <= 0)
	{
		throw graphics_exception("Resource size must be greater than zero");
	}
}

index_buffer_impl::index_buffer_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	index_format format,
	const memory_region& data,
	resource_usage usage) :
	graphics_resource_impl(resource_id, render_system),
	m_index_count(0),
	m_index_format(format),
	m_usage(usage)
{
	if (data.size() <= 0)
	{
		throw graphics_exception("Index count must be greater than zero");
	}

	auto totalSize = data.size_bytes();
	auto indexSize = format_size(format);

	if (totalSize % indexSize != 0)
	{
		throw graphics_exception("Index format size mismatch");
	}

	m_index_count = totalSize / indexSize;
}