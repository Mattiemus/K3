#pragma once

namespace openworld
{
    class vector3 final
    {
    public:
        float x = 0;
        float y = 0;
        float z = 0;

        constexpr vector3()
        {}

        constexpr vector3(float x, float y, float z) :
            x(x),
            y(y),
            z(z)
        {}
    };
}