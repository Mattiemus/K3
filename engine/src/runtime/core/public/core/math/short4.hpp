#pragma once

namespace openworld
{
    class short4 final
    {
    public:
        short x = 0;
        short y = 0;
        short z = 0;
        short w = 0;

        constexpr short4()
        {}

        constexpr short4(short x, short y, short z, short w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };

    static_assert(sizeof(short4) == (4 * sizeof(short)));

    constexpr bool operator ==(const short4& lhs, const short4& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
    }

    constexpr bool operator !=(const short4& lhs, const short4& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z) || (lhs.w != rhs.w);
    }
}