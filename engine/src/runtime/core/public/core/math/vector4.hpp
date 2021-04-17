#pragma once

namespace openworld
{
    class vector4 final
    {
    public:
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;

        constexpr vector4()
        {}

        constexpr vector4(float x, float y, float z, float w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };
}