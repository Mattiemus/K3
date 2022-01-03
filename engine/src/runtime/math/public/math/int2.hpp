#pragma once

namespace openworld
{
    class int2 final
    {
    public:
        int x = 0;
        int y = 0;

        constexpr int2() 
        {}

        constexpr int2(int x, int y)  :
            x(x),
            y(y)
        {}
    };

    static_assert(sizeof(int2) == (2 * sizeof(int)));

    constexpr bool operator ==(const int2& lhs, const int2& rhs) 
    {
        return (lhs.x == rhs.x) && (lhs.y == rhs.y);
    }

    constexpr bool operator !=(const int2& lhs, const int2& rhs) 
    {
        return (lhs.x != rhs.x) || (lhs.y != rhs.y);
    }
}