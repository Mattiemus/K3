#pragma once

namespace openworld
{
    class float3 final
    {
    public:
        float x = 0;
        float y = 0;
        float z = 0;

        constexpr float3()
        {}

        constexpr float3(float x, float y, float z) :
            x(x),
            y(y),
            z(z)
        {}
    };

    static_assert(sizeof(float3) == (3 * sizeof(float)));

    constexpr bool operator ==(const float3& lhs, const float3& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
    }

    constexpr bool operator !=(const float3& lhs, const float3& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z);
    }
}