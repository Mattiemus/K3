#pragma once

namespace openworld
{
    class short2 final
    {
    public:
        short x = 0;
        short y = 0;

        constexpr short2()
        {}

        constexpr short2(short x, short y) :
            x(x),
            y(y)
        {}
    };

    static_assert(sizeof(short2) == (2 * sizeof(short)));

    constexpr bool operator ==(const short2& lhs, const short2& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    constexpr bool operator !=(const short2& lhs, const short2& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y);
    }
}