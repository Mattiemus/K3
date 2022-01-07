#include "graphics.hpp"

using namespace openworld;

sampler_state::sampler_state(openworld::render_system& render_sys)
{
    auto impl = render_sys.make_impl<sampler_state>();
    bind_impl(std::move(impl));

    set_defaults();
}

void sampler_state::set_defaults()
{
    sampler_state_impl().address_u(texture_address_mode::clamp);
    sampler_state_impl().address_v(texture_address_mode::clamp);
    sampler_state_impl().address_w(texture_address_mode::clamp);
    sampler_state_impl().filter(texture_filter::linear);
    sampler_state_impl().max_anisotropy(1);
    sampler_state_impl().mip_map_level_of_detail_bias(0.0f);
    sampler_state_impl().min_mip_map_level(0);
    sampler_state_impl().max_mip_map_level(std::numeric_limits<size_t>::max());
    sampler_state_impl().border_color(color::white);
    sampler_state_impl().compare_function(comparison_function::never);
}

render_state_key sampler_state::compute_render_state_key() const
{
    std::hash<sampler_state> hasher{};

    auto hash = hasher(*this);
    return { render_state_type::sampler_state, hash };
}