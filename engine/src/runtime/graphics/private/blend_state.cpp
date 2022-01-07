#include "graphics.hpp"

using namespace openworld;

blend_state::blend_state(openworld::render_system& render_sys)
{
    auto impl = render_sys.make_impl<blend_state>();
    bind_impl(std::move(impl));

    set_defaults();
}

void blend_state::set_defaults()
{
    blend_state_impl().alpha_to_coverage_enable(false);
    blend_state_impl().independent_blend_enable(false);
    blend_state_impl().blend_factor(color::white);
    blend_state_impl().multi_sample_mask(std::numeric_limits<size_t>::max());

    for (size_t i = 0; i < blend_state_impl().render_target_blend_count(); i++)
    {
        auto desc = render_target_blend_description::default_description;
        if (i == 0)
        {
            desc.blend_enable = true;
        }

        blend_state_impl().set_render_target_blend_description(i, desc);
    }
}

render_state_key blend_state::compute_render_state_key() const
{
    std::hash<blend_state> hasher{};

    auto hash = hasher(*this);
    return { render_state_type::blend_state, hash };
}