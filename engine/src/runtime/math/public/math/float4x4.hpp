#pragma once

namespace openworld
{
    class quaternion;

    class float4x4 final
    {
    public:
        static const float4x4 identity;

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

        constexpr float4x4(float value)  :
            m11(value),
            m12(value),
            m13(value),
            m14(value),
            m21(value),
            m22(value),
            m23(value),
            m24(value),
            m31(value),
            m32(value),
            m33(value),
            m34(value),
            m41(value),
            m42(value),
            m43(value),
            m44(value)
        {}

        constexpr float4x4(
            float m11, float m12, float m13, float m14,
            float m21, float m22, float m23, float m24,
            float m31, float m32, float m33, float m34,
            float m41, float m42, float m43, float m44)  :
            m11(m11),
            m12(m12),
            m13(m13),
            m14(m14),
            m21(m21),
            m22(m22),
            m23(m23),
            m24(m24),
            m31(m31),
            m32(m32),
            m33(m33),
            m34(m34),
            m41(m41),
            m42(m42),
            m43(m43),
            m44(m44)
        {}

        static float4x4 multiply(const float4x4& a, const float4x4& b);
        static void multiply(const float4x4& a, const float4x4& b, float4x4& result);
        static float4x4 multiply(const float4x4& value, float scale);
        static void multiply(const float4x4& value, float scale, float4x4& result);

        static float4x4 from_scale(const float3& scale);
        static void from_scale(const float3& scale, float4x4& result);
        static float4x4 from_scale(float scale);
        static void from_scale(float scale, float4x4& result);
        static float4x4 from_scale(float x, float y, float z);
        static void from_scale(float x, float y, float z, float4x4& result);

        static float4x4 from_translation(const float3& translation);
        static void from_translation(const float3& translation, float4x4& result);
        static float4x4 from_translation(float x, float y, float z);
        static void from_translation(float x, float y, float z, float4x4& result);

        static float4x4 from_quaternion(const quaternion& rot);
        static void from_quaternion(const quaternion& rot, float4x4& result);

        float3 translation() const;
        void translation(const float3& new_translation);

        float3 up() const;
        void up(const float3& new_up);

        float3 down() const;
        void down(const float3& new_down);

        float3 backward() const;
        void backward(const float3& new_backward);

        float3 forward() const;
        void forward(const float3& new_forward);

        float3 right() const;
        void right(const float3& new_right);

        float3 left() const;
        void left(const float3& new_left);
    };

    static_assert(sizeof(float4x4) == (16 * sizeof(float)));

    inline bool operator ==(const float4x4& lhs, const float4x4& rhs) 
    {
        return is_equal(lhs.m11, rhs.m11) && is_equal(lhs.m12, rhs.m12) && is_equal(lhs.m13, rhs.m13) && is_equal(lhs.m14, rhs.m14) &&
            is_equal(lhs.m21, rhs.m21) && is_equal(lhs.m22, rhs.m22) && is_equal(lhs.m23, rhs.m23) && is_equal(lhs.m24, rhs.m24) &&
            is_equal(lhs.m31, rhs.m31) && is_equal(lhs.m32, rhs.m32) && is_equal(lhs.m33, rhs.m33) && is_equal(lhs.m34, rhs.m34) &&
            is_equal(lhs.m41, rhs.m41) && is_equal(lhs.m42, rhs.m42) && is_equal(lhs.m43, rhs.m43) && is_equal(lhs.m44, rhs.m44);
    }

    inline bool operator !=(const float4x4& lhs, const float4x4& rhs) 
    {
        return !is_equal(lhs.m11, rhs.m11) || !is_equal(lhs.m12, rhs.m12) || !is_equal(lhs.m13, rhs.m13) || !is_equal(lhs.m14, rhs.m14) ||
            !is_equal(lhs.m21, rhs.m21) || !is_equal(lhs.m22, rhs.m22) || !is_equal(lhs.m23, rhs.m23) || !is_equal(lhs.m24, rhs.m24) ||
            !is_equal(lhs.m31, rhs.m31) || !is_equal(lhs.m32, rhs.m32) || !is_equal(lhs.m33, rhs.m33) || !is_equal(lhs.m34, rhs.m34) ||
            !is_equal(lhs.m41, rhs.m41) || !is_equal(lhs.m42, rhs.m42) || !is_equal(lhs.m43, rhs.m43) || !is_equal(lhs.m44, rhs.m44);
    }
}