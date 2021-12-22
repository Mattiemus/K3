#pragma once

namespace openworld
{
    class float4 final
    {
    public:
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;

        constexpr float4()
        {}

        constexpr float4(float x, float y, float z, float w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };

    static_assert(sizeof(float4) == (4 * sizeof(float)));

    constexpr bool operator ==(const float4& lhs, const float4& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
    }

    constexpr bool operator !=(const float4& lhs, const float4& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z) || (lhs.w != rhs.w);
    }
}