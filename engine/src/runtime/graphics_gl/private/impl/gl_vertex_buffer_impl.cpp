#include "graphics_gl.hpp"

using namespace openworld;

gl_vertex_buffer_impl::gl_vertex_buffer_impl(
	size_t resource_id,
	openworld::gl_render_system& render_sys,
	const vertex_layout& layout,
	size_t vertex_count,
	resource_usage usage) :
	vertex_buffer_impl(resource_id, render_sys, layout, vertex_count, usage),
	m_gl_render_sys(render_sys),
	m_buffer_id(0)
{
	throw std::exception("not implemented");
}

gl_vertex_buffer_impl::gl_vertex_buffer_impl(
	size_t resource_id,
	openworld::gl_render_system& render_sys,
	const vertex_layout& layout,
	const memory_region& data,
	resource_usage usage) :
	vertex_buffer_impl(resource_id, render_sys, layout, data, usage),
	m_gl_render_sys(render_sys),
	m_buffer_id(0)
{
	glCreateBuffers(1, &m_buffer_id);
	glNamedBufferStorage(m_buffer_id, data.size_bytes(), data.data(), GL_MAP_WRITE_BIT | GL_DYNAMIC_STORAGE_BIT);
}

gl_vertex_buffer_impl::gl_vertex_buffer_impl(
	size_t resource_id,
	openworld::gl_render_system& render_sys,
	const vertex_layout& layout,
	const std::vector<memory_region>& data,
	resource_usage usage) :
	vertex_buffer_impl(resource_id, render_sys, layout, data, usage),
	m_gl_render_sys(render_sys),
	m_buffer_id(0)
{
	throw std::exception();
}

gl_vertex_buffer_impl::~gl_vertex_buffer_impl()
{
	glDeleteBuffers(1, &m_buffer_id);
}

void gl_vertex_buffer_impl::get_interleaved_data(
	const std::vector<memory_region>& data)
{
	throw std::exception("not implemented");
}

void gl_vertex_buffer_impl::set_interleaved_data(
	render_context& render_ctx,
	const std::vector<memory_region>& data)
{
	throw std::exception("not implemented");
}

void gl_vertex_buffer_impl::get_data(
	const memory_region& data,
	size_t start_index,
	size_t element_count,
	size_t buffer_read_start_offset,
	size_t vertex_stride)
{
	throw std::exception("not implemented");
}

void gl_vertex_buffer_impl::set_data(
	render_context& render_ctx,
	const memory_region& data,
	size_t start_index,
	size_t element_count,
	size_t buffer_write_start_offset,
	size_t vertex_stride,
	data_write_options write_opts)
{
	glBindBuffer(GL_ARRAY_BUFFER, m_buffer_id);
	glBufferData(GL_ARRAY_BUFFER, element_count * data.size_element(), data.data(), GL_STATIC_DRAW);
}