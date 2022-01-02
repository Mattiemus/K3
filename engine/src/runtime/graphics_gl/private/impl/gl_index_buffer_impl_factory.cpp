#include "graphics_gl.hpp"

using namespace openworld;

gl_index_buffer_impl_factory::gl_index_buffer_impl_factory(gl_render_system& render_sys) :
	index_buffer_impl_factory(render_sys), m_gl_render_sys(render_sys)
{}

gl_index_buffer_impl_factory::~gl_index_buffer_impl_factory()
{}

std::unique_ptr<index_buffer_impl> gl_index_buffer_impl_factory::create_impl(
	index_format format,
	size_t index_count,
	resource_usage usage)
{
	return std::make_unique<gl_index_buffer_impl>(
		0,
		m_gl_render_sys,
		format,
		index_count,
		usage);
}

std::unique_ptr<index_buffer_impl> gl_index_buffer_impl_factory::create_impl(
	index_format format,
	const memory_region& data,
	resource_usage usage)
{
	return std::make_unique<gl_index_buffer_impl>(
		0,
		m_gl_render_sys,
		format,
		data,
		usage);
}