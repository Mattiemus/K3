#include "graphics_gl.hpp"

using namespace openworld;

gl_index_buffer_impl::gl_index_buffer_impl(
	size_t resource_id,
	openworld::gl_render_system& render_sys,
	index_format format,
	size_t index_count,
	resource_usage usage) :
	index_buffer_impl(resource_id, render_sys, format, index_count, usage),
	m_gl_render_sys(render_sys),
	m_buffer_id(0)
{
	throw std::exception("not implemented");
}

gl_index_buffer_impl::gl_index_buffer_impl(
	size_t resource_id,
	openworld::gl_render_system& render_sys,
	index_format format,
	const memory_region& data,
	resource_usage usage) :
	index_buffer_impl(resource_id, render_sys, format, data, usage),
	m_gl_render_sys(render_sys),
	m_buffer_id(0)
{
	glCreateBuffers(1, &m_buffer_id);
	glNamedBufferStorage(m_buffer_id, data.size_bytes(), data.data(), GL_MAP_WRITE_BIT | GL_DYNAMIC_STORAGE_BIT);
}

gl_index_buffer_impl::~gl_index_buffer_impl()
{
	glDeleteBuffers(1, &m_buffer_id);
}

void gl_index_buffer_impl::get_data(
	const memory_region& data,
	size_t start_index,
	size_t element_count,
	size_t buffer_read_start_offset)
{
	throw std::exception("not implemented");
}

void gl_index_buffer_impl::set_data(
	render_context& render_ctx,
	const memory_region& data,
	size_t start_index,
	size_t element_count,
	size_t buffer_write_start_offset,
	data_write_options write_opts)
{
	throw std::exception("not implemented");
}