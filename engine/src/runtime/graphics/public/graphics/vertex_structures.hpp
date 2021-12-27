#pragma once

namespace openworld
{
    class vertex_position_color final
    {
    public:
        static const vertex_layout vertex_layout;

        float3 position;
        openworld::color color;

        constexpr vertex_position_color() noexcept
        {}

        constexpr vertex_position_color(const float3& position, const openworld::color& color) noexcept :
            position(position),
            color(color)
        {}
    };

    constexpr bool operator ==(
        const vertex_position_color& lhs,
        const vertex_position_color& rhs) noexcept
    {
        return (lhs.position == rhs.position) && (lhs.color == rhs.color);
    }

    constexpr bool operator !=(
        const vertex_position_color& lhs,
        const vertex_position_color& rhs) noexcept
    {
        return (lhs.position != rhs.position) || (lhs.color != rhs.color);
    }
}