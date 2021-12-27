#include "graphics.hpp"

using namespace openworld;

graphics_resource::graphics_resource() :
	m_name("<no name>"), m_tag(nullptr)
{}

size_t graphics_resource::resource_id() const
{
	return impl()->resource_id();
}

openworld::render_system& graphics_resource::render_system() const
{
	return impl()->render_system();
}