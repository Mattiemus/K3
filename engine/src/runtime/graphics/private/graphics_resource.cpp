#include "graphics.hpp"

using namespace openworld;

size_t graphics_resource::resource_id() const
{
	return impl()->resource_id();
}

openworld::render_system& graphics_resource::render_system() const
{
	return impl()->render_system();
}