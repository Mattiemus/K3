#pragma once

namespace openworld
{
    class uint3 final
    {
    public:
        unsigned int x = 0;
        unsigned int y = 0;
        unsigned int z = 0;

        constexpr uint3()
        {}

        constexpr uint3(unsigned int x, unsigned int y, unsigned int z) :
            x(x),
            y(y),
            z(z)
        {}
    };

    static_assert(sizeof(uint3) == (3 * sizeof(unsigned int)));

    constexpr bool operator ==(const uint3& lhs, const uint3& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
    }

    constexpr bool operator !=(const uint3& lhs, const uint3& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z);
    }
}