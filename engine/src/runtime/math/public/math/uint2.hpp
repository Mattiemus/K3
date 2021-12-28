#pragma once

namespace openworld
{
    class uint2 final
    {
    public:
        unsigned int x = 0;
        unsigned int y = 0;

        constexpr uint2()
        {}

        constexpr uint2(unsigned int x, unsigned int y) :
            x(x),
            y(y)
        {}
    };

    static_assert(sizeof(uint2) == (2 * sizeof(unsigned int)));

    constexpr bool operator ==(const uint2& lhs, const uint2& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    constexpr bool operator !=(const uint2& lhs, const uint2& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y);
    }
}