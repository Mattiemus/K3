#pragma once

namespace openworld
{
    class vertex_position_color final
    {
    public:
        static const vertex_layout vertex_layout;

        float3 position;
        openworld::color color;

        constexpr vertex_position_color()
        {}

        constexpr vertex_position_color(const float3& position, const openworld::color& color) :
            position(position),
            color(color)
        {}
    };

    inline bool operator ==(
        const vertex_position_color& lhs,
        const vertex_position_color& rhs)
    {
        return (lhs.position == rhs.position) && (lhs.color == rhs.color);
    }

    inline bool operator !=(
        const vertex_position_color& lhs,
        const vertex_position_color& rhs)
    {
        return (lhs.position != rhs.position) || (lhs.color != rhs.color);
    }
}