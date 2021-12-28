#pragma once

namespace openworld
{
    class ushort2 final
    {
    public:
        unsigned short x = 0;
        unsigned short y = 0;

        constexpr ushort2()
        {}

        constexpr ushort2(unsigned short x, unsigned short y) :
            x(x),
            y(y)
        {}
    };

    static_assert(sizeof(ushort2) == (2 * sizeof(unsigned short)));

    constexpr bool operator ==(const ushort2& lhs, const ushort2& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    constexpr bool operator !=(const ushort2& lhs, const ushort2& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y);
    }
}