#pragma once

namespace openworld
{
    class vector2 final
    {
    public:
        float x = 0;
        float y = 0;

        constexpr vector2()
        {}

        constexpr vector2(float x, float y) :
            x(x),
            y(y)
        {}
    };
}