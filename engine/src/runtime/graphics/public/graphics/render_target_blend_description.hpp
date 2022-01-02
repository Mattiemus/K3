#pragma once

namespace openworld
{
    class render_target_blend_description final
    {
    public:
        static const render_target_blend_description default_description;

        bool blend_enable = false;
        blend_function alpha_blend_function = blend_function::add;
        blend alpha_source_blend = blend::one;
        blend alpha_destination_blend = blend::zero;
        blend_function color_blend_function = blend_function::add;
        blend color_source_blend = blend::one;
        blend color_destination_blend = blend::zero;
        color_write_channels write_channels = color_write_channels::all;

        constexpr render_target_blend_description() noexcept
        {}

        constexpr render_target_blend_description(
            bool blend_enable,
            blend_function alpha_blend_function,
            blend alpha_source_blend,
            blend alpha_destination_blend,
            blend_function color_blend_function,
            blend color_source_blend,
            blend color_destination_blend,
            color_write_channels write_channels) noexcept :
            blend_enable(blend_enable),
            alpha_blend_function(alpha_blend_function),
            alpha_source_blend(alpha_source_blend),
            alpha_destination_blend(alpha_destination_blend),
            color_blend_function(color_blend_function),
            color_source_blend(color_source_blend),
            color_destination_blend(color_destination_blend),
            write_channels(write_channels)
        {}

        constexpr bool is_default() const noexcept
        {
            return (blend_enable == false) &&
                (alpha_blend_function == blend_function::add) &&
                (alpha_source_blend == blend::one) &&
                (alpha_destination_blend == blend::zero) &&
                (color_blend_function == blend_function::add) &&
                (color_source_blend == blend::one) &&
                (color_destination_blend == blend::zero) &&
                (write_channels == color_write_channels::all);
        }
    };

    constexpr bool operator ==(
        const render_target_blend_description& lhs,
        const render_target_blend_description& rhs) noexcept
    {
        return (lhs.blend_enable == rhs.blend_enable) &&
            (lhs.alpha_blend_function == rhs.alpha_blend_function) &&
            (lhs.alpha_source_blend == rhs.alpha_source_blend) &&
            (lhs.alpha_destination_blend == rhs.alpha_destination_blend) &&
            (lhs.color_blend_function == rhs.color_blend_function) &&
            (lhs.color_source_blend == rhs.color_source_blend) &&
            (lhs.color_destination_blend == rhs.color_destination_blend) &&
            (lhs.write_channels == rhs.write_channels);
    }

    constexpr bool operator !=(
        const render_target_blend_description& lhs,
        const render_target_blend_description& rhs) noexcept
    {
        return (lhs.blend_enable != rhs.blend_enable) ||
            (lhs.alpha_blend_function != rhs.alpha_blend_function) ||
            (lhs.alpha_source_blend != rhs.alpha_source_blend) ||
            (lhs.alpha_destination_blend != rhs.alpha_destination_blend) ||
            (lhs.color_blend_function != rhs.color_blend_function) ||
            (lhs.color_source_blend != rhs.color_source_blend) ||
            (lhs.color_destination_blend != rhs.color_destination_blend) ||
            (lhs.write_channels != rhs.write_channels);
    }
}

OPENWORLD_DEFINE_STD_HASH(
    ::openworld::render_target_blend_description,
    x.blend_enable,
    x.alpha_blend_function, x.alpha_source_blend, x.alpha_destination_blend,
    x.color_blend_function, x.color_source_blend, x.color_destination_blend,
    x.write_channels)