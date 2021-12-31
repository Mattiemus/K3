#include "graphics.hpp"

using namespace openworld;

occlusion_query::occlusion_query(openworld::render_system& render_sys)
{
    if (!render_sys.is_supported<occlusion_query>())
    {
        throw graphics_exception("Render system does not supported occlusion queries");
    }

    try
    {
        m_impl = render_sys.make_impl<occlusion_query>();
    }
    catch (...)
    {
        throw graphics_exception("Failed to create graphics resource");
    }
}