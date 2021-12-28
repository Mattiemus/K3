#pragma once

namespace openworld
{
    class int4 final
    {
    public:
        int x = 0;
        int y = 0;
        int z = 0;
        int w = 0;

        constexpr int4()
        {}

        constexpr int4(int x, int y, int z, int w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };

    static_assert(sizeof(int4) == (4 * sizeof(int)));

    constexpr bool operator ==(const int4& lhs, const int4& rhs)
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y) && (lhs.z == rhs.z) && (lhs.w == rhs.w);
    }

    constexpr bool operator !=(const int4& lhs, const int4& rhs)
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y) || (lhs.z != rhs.z) || (lhs.w != rhs.w);
    }
}