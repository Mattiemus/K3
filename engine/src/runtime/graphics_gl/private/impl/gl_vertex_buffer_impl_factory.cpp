#include "graphics_gl.hpp"

using namespace openworld;

gl_vertex_buffer_impl_factory::gl_vertex_buffer_impl_factory(gl_render_system& render_sys) :
	vertex_buffer_impl_factory(render_sys), m_gl_render_sys(render_sys)
{}

gl_vertex_buffer_impl_factory::~gl_vertex_buffer_impl_factory()
{}

std::unique_ptr<vertex_buffer_impl> gl_vertex_buffer_impl_factory::create_impl(
	const vertex_layout& layout,
	size_t vertex_count,
	resource_usage usage)
{
	return std::make_unique<gl_vertex_buffer_impl>(
		0,
		m_gl_render_sys,
		layout,
		vertex_count,
		usage);
}

std::unique_ptr<vertex_buffer_impl> gl_vertex_buffer_impl_factory::create_impl(
	const vertex_layout& layout,
	const memory_region& data,
	resource_usage usage)
{
	return std::make_unique<gl_vertex_buffer_impl>(
		0,
		m_gl_render_sys,
		layout,
		data,
		usage);
}

std::unique_ptr<vertex_buffer_impl> gl_vertex_buffer_impl_factory::create_impl(
	const vertex_layout& layout,
	const std::vector<memory_region>& data,
	resource_usage usage)
{
	return std::make_unique<gl_vertex_buffer_impl>(
		0,
		m_gl_render_sys,
		layout,
		data,
		usage);
}