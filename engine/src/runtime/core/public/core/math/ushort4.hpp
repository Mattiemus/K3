#pragma once

namespace openworld
{
    class ushort4 final
    {
    public:
        unsigned short x = 0;
        unsigned short y = 0;
        unsigned short z = 0;
        unsigned short w = 0;

        constexpr ushort4()
        {}

        constexpr ushort4(unsigned short x, unsigned short y, unsigned short z, unsigned short w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };

    static_assert(sizeof(ushort4) == (4 * sizeof(unsigned short)));

    constexpr bool operator ==(const ushort4& lhs, const ushort4& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
    }

    constexpr bool operator !=(const ushort4& lhs, const ushort4& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z) || (lhs.w != rhs.w);
    }
}