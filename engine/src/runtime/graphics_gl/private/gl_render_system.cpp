#include "graphics_gl.hpp"
#include "gl_helpers.hpp"

using namespace openworld;

gl_render_system::gl_render_system() :
	m_immediate_ctx(),
	m_vertex_buffer_impl_factory(*this),
	m_index_buffer_impl_factory(*this)
{
}

graphics_resource_impl_factory& gl_render_system::get_impl_factory(graphics_resource_type resource_type)
{
	if (resource_type == graphics_resource_type::vertex_buffer)
	{
		return m_vertex_buffer_impl_factory;
	}

	if (resource_type == graphics_resource_type::index_buffer)
	{
		return m_index_buffer_impl_factory;
	}

	throw graphics_exception("Unsupported graphics resource type");
}

bool gl_render_system::is_supported(graphics_resource_type resource_type)
{
	return (resource_type == graphics_resource_type::vertex_buffer) ||
		(resource_type == graphics_resource_type::index_buffer);
}