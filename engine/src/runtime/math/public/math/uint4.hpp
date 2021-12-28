#pragma once

namespace openworld
{
    class uint4 final
    {
    public:
        unsigned int x = 0;
        unsigned int y = 0;
        unsigned int z = 0;
        unsigned int w = 0;

        constexpr uint4()
        {}

        constexpr uint4(unsigned int x, unsigned int y, unsigned int z, unsigned int w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };

    static_assert(sizeof(uint4) == (4 * sizeof(unsigned int)));

    constexpr bool operator ==(const uint4& lhs, const uint4& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
    }

    constexpr bool operator !=(const uint4& lhs, const uint4& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z) || (lhs.w != rhs.w);
    }
}