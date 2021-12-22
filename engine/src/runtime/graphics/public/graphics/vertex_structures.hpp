#pragma once

#include "core/math/float3.hpp"
#include "graphics/vertex_layout.hpp"

namespace openworld
{
    class vertex_position_color final
    {
    public:
        static const vertex_layout vertex_layout;

        float3 position;
        float3 color;

        constexpr vertex_position_color()
        {}

        constexpr vertex_position_color(const float3& position, const float3& color) :
            position(position),
            color(color)
        {}
    };

    constexpr bool operator ==(
        const vertex_position_color& lhs,
        const vertex_position_color& rhs)
    {
        return (lhs.position == rhs.position) && (lhs.color == rhs.color);
    }

    constexpr bool operator !=(
        const vertex_position_color& lhs,
        const vertex_position_color& rhs)
    {
        return (lhs.position != rhs.position) || (lhs.color != rhs.color);
    }
}