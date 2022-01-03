#include "graphics.hpp"

using namespace openworld;

rasterizer_state::rasterizer_state(openworld::render_system& render_sys)
{
    m_impl = render_sys.make_impl<rasterizer_state>();
    set_defaults();
}

void rasterizer_state::set_defaults()
{
    m_impl->cull(cull_mode::back);
    m_impl->vertex_winding(vertex_winding::clockwise);
    m_impl->fill(fill_mode::solid);
    m_impl->depth_bias(0);
    m_impl->depth_bias_clamp(0.0f);
    m_impl->slope_scaled_depth_bias(0.0f);
    m_impl->depth_clip_enable(true);
    m_impl->multi_sample_enable(true);
    m_impl->antialiased_line_enable(false);
    m_impl->scissor_test_enable(false);
}

render_state_key rasterizer_state::compute_render_state_key() const
{
    std::hash<rasterizer_state> hasher{};

    auto hash = hasher(*this);
    return { render_state_type::rasterizer_state, hash };
}