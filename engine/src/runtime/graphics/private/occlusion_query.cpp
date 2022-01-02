#include "graphics.hpp"

using namespace openworld;

occlusion_query::occlusion_query(openworld::render_system& render_sys)
{
    m_impl = render_sys.make_impl<occlusion_query>();
}