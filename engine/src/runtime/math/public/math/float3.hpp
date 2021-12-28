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

    inline bool operator ==(const float3& lhs, const float3& rhs)
    {
        return is_equal(lhs.x, rhs.x) && is_equal(lhs.y, rhs.y) && is_equal(lhs.z, rhs.z);
    }

    inline bool operator !=(const float3& lhs, const float3& rhs)
    {
        return !is_equal(lhs.x, rhs.x) || !is_equal(lhs.y, rhs.y) || !is_equal(lhs.z, rhs.z);
    }
}