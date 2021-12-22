#pragma once

namespace openworld
{
    class float4x4 final
    {
    public:
        float m11 = 0;
        float m12 = 0;
        float m13 = 0;
        float m14 = 0;
        float m21 = 0;
        float m22 = 0;
        float m23 = 0;
        float m24 = 0;
        float m31 = 0;
        float m32 = 0;
        float m33 = 0;
        float m34 = 0;
        float m41 = 0;
        float m42 = 0;
        float m43 = 0;
        float m44 = 0;

        constexpr float4x4()
        {}
    };

    static_assert(sizeof(float4x4) == (16 * sizeof(float)));
}