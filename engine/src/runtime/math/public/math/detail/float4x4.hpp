#pragma once

namespace openworld
{
    inline float4x4 float4x4::multiply(const float4x4& a, const float4x4& b)
    {
        float4x4 result{};
        float4x4::multiply(a, b, result);

        return result;
    }

    inline void float4x4::multiply(const float4x4& a, const float4x4& b, float4x4& result)
    {
        float m11 = (((a.m11 * b.m11) + (a.m12 * b.m21)) + (a.m13 * b.m31)) + (a.m14 * b.m41);
        float m12 = (((a.m11 * b.m12) + (a.m12 * b.m22)) + (a.m13 * b.m32)) + (a.m14 * b.m42);
        float m13 = (((a.m11 * b.m13) + (a.m12 * b.m23)) + (a.m13 * b.m33)) + (a.m14 * b.m43);
        float m14 = (((a.m11 * b.m14) + (a.m12 * b.m24)) + (a.m13 * b.m34)) + (a.m14 * b.m44);

        float m21 = (((a.m21 * b.m11) + (a.m22 * b.m21)) + (a.m23 * b.m31)) + (a.m24 * b.m41);
        float m22 = (((a.m21 * b.m12) + (a.m22 * b.m22)) + (a.m23 * b.m32)) + (a.m24 * b.m42);
        float m23 = (((a.m21 * b.m13) + (a.m22 * b.m23)) + (a.m23 * b.m33)) + (a.m24 * b.m43);
        float m24 = (((a.m21 * b.m14) + (a.m22 * b.m24)) + (a.m23 * b.m34)) + (a.m24 * b.m44);

        float m31 = (((a.m31 * b.m11) + (a.m32 * b.m21)) + (a.m33 * b.m31)) + (a.m34 * b.m41);
        float m32 = (((a.m31 * b.m12) + (a.m32 * b.m22)) + (a.m33 * b.m32)) + (a.m34 * b.m42);
        float m33 = (((a.m31 * b.m13) + (a.m32 * b.m23)) + (a.m33 * b.m33)) + (a.m34 * b.m43);
        float m34 = (((a.m31 * b.m14) + (a.m32 * b.m24)) + (a.m33 * b.m34)) + (a.m34 * b.m44);

        float m41 = (((a.m41 * b.m11) + (a.m42 * b.m21)) + (a.m43 * b.m31)) + (a.m44 * b.m41);
        float m42 = (((a.m41 * b.m12) + (a.m42 * b.m22)) + (a.m43 * b.m32)) + (a.m44 * b.m42);
        float m43 = (((a.m41 * b.m13) + (a.m42 * b.m23)) + (a.m43 * b.m33)) + (a.m44 * b.m43);
        float m44 = (((a.m41 * b.m14) + (a.m42 * b.m24)) + (a.m43 * b.m34)) + (a.m44 * b.m44);

        result.m11 = m11;
        result.m12 = m12;
        result.m13 = m13;
        result.m14 = m14;

        result.m21 = m21;
        result.m22 = m22;
        result.m23 = m23;
        result.m24 = m24;

        result.m31 = m31;
        result.m32 = m32;
        result.m33 = m33;
        result.m34 = m34;

        result.m41 = m41;
        result.m42 = m42;
        result.m43 = m43;
        result.m44 = m44;
    }

    inline float4x4 float4x4::multiply(const float4x4& value, float scale)
    {
        float4x4 result{};
        float4x4::multiply(value, scale, result);

        return result;
    }

    inline void float4x4::multiply(const float4x4& value, float scale, float4x4& result)
    {
        result.m11 = value.m11 * scale;
        result.m12 = value.m12 * scale;
        result.m13 = value.m13 * scale;
        result.m14 = value.m14 * scale;

        result.m21 = value.m21 * scale;
        result.m22 = value.m22 * scale;
        result.m23 = value.m23 * scale;
        result.m24 = value.m24 * scale;

        result.m31 = value.m31 * scale;
        result.m32 = value.m32 * scale;
        result.m33 = value.m33 * scale;
        result.m34 = value.m34 * scale;

        result.m41 = value.m41 * scale;
        result.m42 = value.m42 * scale;
        result.m43 = value.m43 * scale;
        result.m44 = value.m44 * scale;
    }

    inline float4x4 float4x4::from_scale(const float3& scale)
    {
        float4x4 result{};
        float4x4::from_scale(scale, result);

        return result;
    }

    inline void float4x4::from_scale(const float3& scale, float4x4& result)
    {
        result.m11 = scale.x;
        result.m12 = 0.0f;
        result.m13 = 0.0f;
        result.m14 = 0.0f;

        result.m21 = 0.0f;
        result.m22 = scale.y;
        result.m23 = 0.0f;
        result.m24 = 0.0f;

        result.m31 = 0.0f;
        result.m32 = 0.0f;
        result.m33 = scale.z;
        result.m34 = 0.0f;

        result.m41 = 0.0f;
        result.m42 = 0.0f;
        result.m43 = 0.0f;
        result.m44 = 1.0f;
    }

    inline float4x4 float4x4::from_scale(float scale)
    {
        float4x4 result{};
        float4x4::from_scale(scale, result);

        return result;
    }

    inline void float4x4::from_scale(float scale, float4x4& result)
    {
        result.m11 = scale;
        result.m12 = 0.0f;
        result.m13 = 0.0f;
        result.m14 = 0.0f;

        result.m21 = 0.0f;
        result.m22 = scale;
        result.m23 = 0.0f;
        result.m24 = 0.0f;

        result.m31 = 0.0f;
        result.m32 = 0.0f;
        result.m33 = scale;
        result.m34 = 0.0f;

        result.m41 = 0.0f;
        result.m42 = 0.0f;
        result.m43 = 0.0f;
        result.m44 = 1.0f;
    }

    inline float4x4 float4x4::from_scale(float x, float y, float z)
    {
        float4x4 result{};
        float4x4::from_scale(x, y, z, result);

        return result;
    }

    inline void float4x4::from_scale(float x, float y, float z, float4x4& result)
    {
        result.m11 = x;
        result.m12 = 0.0f;
        result.m13 = 0.0f;
        result.m14 = 0.0f;

        result.m21 = 0.0f;
        result.m22 = y;
        result.m23 = 0.0f;
        result.m24 = 0.0f;

        result.m31 = 0.0f;
        result.m32 = 0.0f;
        result.m33 = z;
        result.m34 = 0.0f;

        result.m41 = 0.0f;
        result.m42 = 0.0f;
        result.m43 = 0.0f;
        result.m44 = 1.0f;
    }

    inline float4x4 float4x4::from_translation(const float3& translation)
    {
        float4x4 result{};
        float4x4::from_translation(translation, result);

        return result;
    }

    inline void float4x4::from_translation(const float3& translation, float4x4& result)
    {
        result.m11 = 1.0f;
        result.m12 = 0.0f;
        result.m13 = 0.0f;
        result.m14 = 0.0f;

        result.m21 = 0.0f;
        result.m22 = 1.0f;
        result.m23 = 0.0f;
        result.m24 = 0.0f;

        result.m31 = 0.0f;
        result.m32 = 0.0f;
        result.m33 = 1.0f;
        result.m34 = 0.0f;

        result.m41 = translation.x;
        result.m42 = translation.y;
        result.m43 = translation.z;
        result.m44 = 1.0f;
    }

    inline float4x4 float4x4::from_translation(float x, float y, float z)
    {
        float4x4 result{};
        float4x4::from_translation(x, y, z, result);

        return result;
    }

    inline void float4x4::from_translation(float x, float y, float z, float4x4& result)
    {
        result.m11 = 1.0f;
        result.m12 = 0.0f;
        result.m13 = 0.0f;
        result.m14 = 0.0f;

        result.m21 = 0.0f;
        result.m22 = 1.0f;
        result.m23 = 0.0f;
        result.m24 = 0.0f;

        result.m31 = 0.0f;
        result.m32 = 0.0f;
        result.m33 = 1.0f;
        result.m34 = 0.0f;

        result.m41 = x;
        result.m42 = y;
        result.m43 = z;
        result.m44 = 1.0f;
    }

    inline float4x4 float4x4::from_quaternion(const quaternion& rot)
    {
        float4x4 result{};
        float4x4::from_quaternion(rot, result);

        return result;
    }

    inline void float4x4::from_quaternion(const quaternion& rot, float4x4& result)
    {
        float x = rot.x;
        float y = rot.y;
        float z = rot.z;
        float w = rot.w;

        float xx = x * x;
        float xy = x * y;
        float xw = x * w;

        float yy = y * y;
        float yz = y * z;
        float yw = y * w;

        float zx = z * x;
        float zz = z * z;
        float zw = z * w;

        result.m11 = 1.0f - (2.0f * (yy + zz));
        result.m12 = 2.0f * (xy + zw);
        result.m13 = 2.0f * (zx - yw);
        result.m14 = 0.0f;

        result.m21 = 2.0f * (xy - zw);
        result.m22 = 1.0f - (2.0f * (xx + zz));
        result.m23 = 2.0f * (yz + xw);
        result.m24 = 0.0f;

        result.m31 = 2.0f * (zx + yw);
        result.m32 = 2.0f * (yz - xw);
        result.m33 = 1.0f - (2.0f * (xx + yy));
        result.m34 = 0.0f;

        result.m41 = 0.0f;
        result.m42 = 0.0f;
        result.m43 = 0.0f;
        result.m44 = 1.0f;
    }

    inline float3 float4x4::translation() const
    {
        float3 v{};
        v.x = m41;
        v.y = m42;
        v.z = m43;

        return v;
    }

    inline void float4x4::translation(const float3& new_translation)
    {
        m41 = new_translation.x;
        m42 = new_translation.y;
        m43 = new_translation.z;
    }

    inline float3 float4x4::up() const
    {
        float3 v{};
        v.x = m21;
        v.y = m22;
        v.z = m23;

        return v;
    }

    inline void float4x4::up(const float3& new_up)
    {
        m21 = new_up.x;
        m22 = new_up.y;
        m23 = new_up.z;
    }

    inline float3 float4x4::down() const
    {
        float3 v{};
        v.x = -m21;
        v.y = -m22;
        v.z = -m23;

        return v;
    }

    inline void float4x4::down(const float3& new_down)
    {
        m21 = -new_down.x;
        m22 = -new_down.y;
        m23 = -new_down.z;
    }

    inline float3 float4x4::backward() const
    {
        float3 v{};
        v.x = m31;
        v.y = m32;
        v.z = m33;

        return v;
    }

    inline void float4x4::backward(const float3& new_backward)
    {
        m31 = new_backward.x;
        m32 = new_backward.y;
        m33 = new_backward.z;
    }

    inline float3 float4x4::forward() const
    {
        float3 v{};
        v.x = -m31;
        v.y = -m32;
        v.z = -m33;

        return v;
    }

    inline void float4x4::forward(const float3& new_forward)
    {
        m31 = -new_forward.x;
        m32 = -new_forward.y;
        m33 = -new_forward.z;
    }

    inline float3 float4x4::right() const
    {
        float3 v{};
        v.x = m11;
        v.y = m12;
        v.z = m13;

        return v;
    }

    inline void float4x4::right(const float3& new_right)
    {
        m11 = new_right.x;
        m12 = new_right.y;
        m13 = new_right.z;
    }

    inline float3 float4x4::left() const
    {
        float3 v{};
        v.x = -m11;
        v.y = -m12;
        v.z = -m13;

        return v;
    }

    inline void float4x4::left(const float3& new_left)
    {
        m11 = -new_left.x;
        m12 = -new_left.y;
        m13 = -new_left.z;
    }
}