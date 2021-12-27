#include "graphics_gl.hpp"

using namespace openworld;

gl_index_buffer_impl::gl_index_buffer_impl(
	openworld::gl_render_system& render_sys,
	index_format format,
	size_t index_count,
	resource_usage usage) :
	m_render_sys(render_sys),
	m_buffer_id(0),
	m_index_count(index_count),
	m_index_format(format),
	m_resource_usage(usage)
{

}

gl_index_buffer_impl::gl_index_buffer_impl(
	openworld::gl_render_system& render_sys,
	index_format format,
	const std::span<const std::byte>& data,
	resource_usage usage) :
	m_render_sys(render_sys),
	m_buffer_id(0),
	m_index_count(0),
	m_index_format(format),
	m_resource_usage(usage)
{
	glCreateBuffers(1, &m_buffer_id);
	glNamedBufferStorage(m_buffer_id, data.size(), data.data(), GL_MAP_WRITE_BIT | GL_DYNAMIC_STORAGE_BIT);
}

gl_index_buffer_impl::~gl_index_buffer_impl()
{
	glDeleteBuffers(1, &m_buffer_id);
}

openworld::render_system& gl_index_buffer_impl::render_system() const
{
	return m_render_sys;
}

void gl_index_buffer_impl::get_data(
	const std::span<std::byte>& data,
	size_t element_count,
	size_t element_size,
	size_t read_start_offset)
{
	throw std::exception("not implemented");
}

void gl_index_buffer_impl::set_data(
	render_context& render_ctx,
	const std::span<const std::byte>& data,
	size_t element_count,
	size_t element_size,
	size_t write_start_offset,
	data_write_options write_opts)
{
	throw std::exception("not implemented");
}