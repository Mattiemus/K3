#pragma once

namespace openworld
{
    class int3 final
    {
    public:
        int x = 0;
        int y = 0;
        int z = 0;

        constexpr int3()
        {}

        constexpr int3(int x, int y, int z) :
            x(x),
            y(y),
            z(z)
        {}
    };

    static_assert(sizeof(int3) == (3 * sizeof(int)));

    constexpr bool operator ==(const int3& lhs, const int3& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z);
    }

    constexpr bool operator !=(const int3& lhs, const int3& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z);
    }
}