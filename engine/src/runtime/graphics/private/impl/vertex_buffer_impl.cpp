#include "graphics.hpp"

using namespace openworld;

vertex_buffer_impl::vertex_buffer_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	const vertex_layout& layout,
	size_t vertex_count,
	resource_usage usage) :
	graphics_resource_impl(resource_id, render_system),
	m_vertex_layout(layout),
	m_vertex_count(vertex_count),
	m_resource_usage(usage)
{
	if (usage == resource_usage::immutable)
	{
		throw graphics_exception("Must supply data for immutable resource");
	}

	if (vertex_count <= 0)
	{
		throw graphics_exception("Vertex count must be greater than zero");
	}
}

vertex_buffer_impl::vertex_buffer_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	const vertex_layout& layout,
	const memory_region& data,
	resource_usage usage) :
	graphics_resource_impl(resource_id, render_system),
	m_vertex_layout(layout),
	m_vertex_count(0),
	m_resource_usage(usage)
{
	auto total_size_bytes = data.size_bytes();
	auto vertex_stride = layout.vertex_stride();

	if (total_size_bytes == 0)
	{
		throw graphics_exception("Vertex count must be greater than zero");
	}

	if (total_size_bytes % vertex_stride != 0)
	{
		throw graphics_exception("Vertex layout stride mismatch");
	}

	m_vertex_count = total_size_bytes / vertex_stride;
}

vertex_buffer_impl::vertex_buffer_impl(
	size_t resource_id,
	openworld::render_system& render_system,
	const vertex_layout& layout,
	const std::vector<memory_region>& data,
	resource_usage usage) :
	graphics_resource_impl(resource_id, render_system),
	m_vertex_layout(layout),
	m_vertex_count(0),
	m_resource_usage(usage)
{
	if (data.size() != layout.vertex_elements().size())
	{
		throw graphics_exception("Vertex layout element count mismatch");
	}

	size_t total_size_bytes = 0;
	size_t vertex_stride = 0;

	for (size_t i = 0; i < data.size(); i++)
	{
		const auto& region = data[i];
		const auto& element = layout.vertex_elements()[i];

		auto element_size_bytes = region.size_element();
		auto region_vertex_count = region.size_bytes() / element_size_bytes;

		if (i == 0)
		{
			m_vertex_count = region_vertex_count;
			if (m_vertex_count <= 0)
			{
				throw graphics_exception("Vertex count must be greater than zero");
			}
		}
		else
		{
			if (region_vertex_count != m_vertex_count)
			{
				throw graphics_exception("Vertex count mistmatch");
			}
		}

		if (element_size_bytes != format_size(element.format))
		{
			throw graphics_exception("Vertex element size mistmatch");
		}

		total_size_bytes += region.size_bytes();
		vertex_stride += element_size_bytes;
	}

	if (total_size_bytes > layout.vertex_stride() * m_vertex_count)
	{
		throw graphics_exception("Vertex buffer size mismatch");
	}
}

vertex_buffer_impl::~vertex_buffer_impl()
{}

vertex_buffer_impl_factory::~vertex_buffer_impl_factory()
{}