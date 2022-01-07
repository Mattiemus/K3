#include "graphics.hpp"

using namespace openworld;

rasterizer_state::rasterizer_state(openworld::render_system& render_sys) 
{
    auto impl = render_sys.make_impl<rasterizer_state>();
    bind_impl(std::move(impl));

    set_defaults();
}

void rasterizer_state::set_defaults()
{
    rasterizer_state_impl().cull(cull_mode::back);
    rasterizer_state_impl().vertex_winding(vertex_winding::clockwise);
    rasterizer_state_impl().fill(fill_mode::solid);
    rasterizer_state_impl().depth_bias(0);
    rasterizer_state_impl().depth_bias_clamp(0.0f);
    rasterizer_state_impl().slope_scaled_depth_bias(0.0f);
    rasterizer_state_impl().depth_clip_enable(true);
    rasterizer_state_impl().multi_sample_enable(true);
    rasterizer_state_impl().antialiased_line_enable(false);
    rasterizer_state_impl().scissor_test_enable(false);
}

render_state_key rasterizer_state::compute_render_state_key() const
{
    std::hash<rasterizer_state> hasher{};

    auto hash = hasher(*this);
    return { render_state_type::rasterizer_state, hash };
}