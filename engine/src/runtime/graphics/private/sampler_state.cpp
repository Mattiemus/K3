#include "graphics.hpp"

using namespace openworld;

sampler_state::sampler_state(openworld::render_system& render_sys)
{
    m_impl = render_sys.make_impl<sampler_state>();
    set_defaults();
}

void sampler_state::set_defaults()
{
    m_impl->address_u(texture_address_mode::clamp);
    m_impl->address_v(texture_address_mode::clamp);
    m_impl->address_w(texture_address_mode::clamp);
    m_impl->filter(texture_filter::linear);
    m_impl->max_anisotropy(1);
    m_impl->mip_map_level_of_detail_bias(0.0f);
    m_impl->min_mip_map_level(0);
    m_impl->max_mip_map_level(std::numeric_limits<size_t>::max());
    m_impl->border_color(color::white);
    m_impl->compare_function(comparison_function::never);
}

render_state_key sampler_state::compute_render_state_key() const
{
    std::hash<sampler_state> hasher{};

    auto hash = hasher(*this);
    return { render_state_type::sampler_state, hash };
}