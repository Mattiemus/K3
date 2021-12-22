#pragma once

namespace openworld
{
    class float2 final
    {
    public:
        float x = 0;
        float y = 0;

        constexpr float2()
        {}

        constexpr float2(float x, float y) :
            x(x),
            y(y)
        {}
    };

    static_assert(sizeof(float2) == (2 * sizeof(float)));

    constexpr bool operator ==(const float2& lhs, const float2& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    constexpr bool operator !=(const float2& lhs, const float2& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y);
    }
}