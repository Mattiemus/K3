#pragma once

namespace openworld
{
    class quaternion final
    {
    public:
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;

        constexpr quaternion()
        {}

        constexpr quaternion(float x, float y, float z, float w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };

    static_assert(sizeof(quaternion) == (4 * sizeof(float)));

    constexpr bool operator ==(const quaternion& lhs, const quaternion& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
    }

    constexpr bool operator !=(const quaternion& lhs, const quaternion& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z) || (lhs.w != rhs.w);
    }
}