#include "graphics_gl.hpp"

using namespace openworld;

gl_vertex_buffer_impl::gl_vertex_buffer_impl(
	openworld::gl_render_system& render_sys,
	const vertex_layout& layout,
	size_t vertex_count,
	resource_usage usage) :
	m_render_sys(render_sys),
	m_buffer_id(0),
	m_vertex_layout(layout),
	m_vertex_count(0),
	m_resource_usage(usage)
{
	throw std::exception();
}

gl_vertex_buffer_impl::gl_vertex_buffer_impl(
	openworld::gl_render_system& render_sys,
	const vertex_layout& layout,
	const std::span<const std::byte>& data,
	resource_usage usage) :
	m_render_sys(render_sys),
	m_buffer_id(0),
	m_vertex_layout(layout),
	m_vertex_count(0),
	m_resource_usage(usage)
{
	glCreateBuffers(1, &m_buffer_id);
	glNamedBufferStorage(m_buffer_id, data.size(), data.data(), GL_MAP_WRITE_BIT | GL_DYNAMIC_STORAGE_BIT);
}

gl_vertex_buffer_impl::gl_vertex_buffer_impl(
	openworld::gl_render_system& render_sys,
	const vertex_layout& layout,
	const std::span<const std::span<const std::byte>>& data,
	resource_usage usage) :
	m_render_sys(render_sys),
	m_buffer_id(0),
	m_vertex_layout(layout),
	m_vertex_count(0),
	m_resource_usage(usage)
{
	throw std::exception();
}

gl_vertex_buffer_impl::~gl_vertex_buffer_impl()
{
	glDeleteBuffers(1, &m_buffer_id);
}

openworld::render_system& gl_vertex_buffer_impl::render_system() const
{
	return m_render_sys;
}

void gl_vertex_buffer_impl::get_data(
	const std::span<std::byte>& data,
	size_t element_count,
	size_t element_size,
	size_t read_start_offset,
	size_t vertex_stride)
{
	throw std::exception();
}

void gl_vertex_buffer_impl::set_data(
	render_context& render_ctx,
	const std::span<const std::byte>& data,
	size_t element_count,
	size_t element_size,
	size_t write_start_offset,
	size_t vertex_stride,
	data_write_options write_opts)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
	glBufferData(GL_ARRAY_BUFFER, element_count * element_size, data.data(), GL_STATIC_DRAW);
}