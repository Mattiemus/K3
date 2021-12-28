#pragma once

namespace openworld
{
    class half2 final
    {
    public:
        half x = 0;
        half y = 0;

        constexpr half2()
        {}

        constexpr half2(half x, half y) :
            x(x),
            y(y)
        {}
    };

    static_assert(sizeof(half2) == (2 * sizeof(half)));

    constexpr bool operator ==(const half2& lhs, const half2& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    constexpr bool operator !=(const half2& lhs, const half2& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y);
    }
}