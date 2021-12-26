#pragma once

#include "core/math/half.hpp"

namespace openworld
{
    class half4 final
    {
    public:
        half x = 0;
        half y = 0;
        half z = 0;
        half w = 0;

        constexpr half4()
        {}

        constexpr half4(half x, half y, half z, half w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };

    static_assert(sizeof(half4) == (4 * sizeof(half)));

    constexpr bool operator ==(const half4& lhs, const half4& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
    }

    constexpr bool operator !=(const half4& lhs, const half4& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z) || (lhs.w != rhs.w);
    }
}