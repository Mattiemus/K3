#pragma once

namespace openworld
{
    class quaternion final
    {
    public:
        float x = 0;
        float y = 0;
        float z = 0;
        float w = 0;

        constexpr quaternion()
        {}

        constexpr quaternion(float x, float y, float z, float w) :
            x(x),
            y(y),
            z(z),
            w(w)
        {}
    };
}