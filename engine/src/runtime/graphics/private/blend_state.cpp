#include "graphics.hpp"

using namespace openworld;

blend_state::blend_state(openworld::render_system& render_sys)
{
    m_impl = render_sys.make_impl<blend_state>();    
    set_defaults();
}

void blend_state::set_defaults()
{
    m_impl->alpha_to_coverage_enable(false);
    m_impl->independent_blend_enable(false);
    m_impl->blend_factor(color::white);
    m_impl->multi_sample_mask(std::numeric_limits<size_t>::max());

    for (size_t i = 0; i < m_impl->render_target_blend_count(); i++)
    {
        auto desc = render_target_blend_description::default_description;
        if (i == 0)
        {
            desc.blend_enable = true;
        }

        m_impl->set_render_target_blend_description(i, desc);
    }
}

render_state_key blend_state::compute_render_state_key() const
{
    std::hash<blend_state> hasher{};

    auto hash = hasher(*this);
    return { render_state_type::blend_state, hash };
}