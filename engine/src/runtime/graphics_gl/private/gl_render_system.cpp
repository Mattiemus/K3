#include "graphics_gl.hpp"
#include "gl_helpers.hpp"

using namespace openworld;

gl_render_system::gl_render_system() :
	m_vertex_buffer_impl_factory(*this)
{
}

graphics_resource_impl_factory& gl_render_system::get_impl_factory(graphics_resource_type resource_type)
{
	if (resource_type == graphics_resource_type::vertex_buffer)
	{
		return m_vertex_buffer_impl_factory;
	}

	throw std::exception("Unknown resource type");
}

bool gl_render_system::is_supported(graphics_resource_type resource_type)
{
	return resource_type == graphics_resource_type::vertex_buffer;
}