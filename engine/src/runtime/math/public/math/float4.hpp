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

    inline bool operator ==(const float4& lhs, const float4& rhs)
    {
        return is_equal(lhs.x, rhs.x) && is_equal(lhs.y, rhs.y) && is_equal(lhs.z, rhs.z) && is_equal(lhs.w, rhs.w);
    }

    inline bool operator !=(const float4& lhs, const float4& rhs)
    {
        return !is_equal(lhs.x, rhs.x) || !is_equal(lhs.y, rhs.y) || !is_equal(lhs.z, rhs.z) || !is_equal(lhs.w, rhs.w);
    }
}