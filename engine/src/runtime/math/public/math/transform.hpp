#pragma once

namespace openworld
{
    class transform final
    {
    public:
        constexpr transform() :
            m_scale(1.0f, 1.0f, 1.0f),
            m_rotation(0.0f, 0.0f, 0.0f, 1.0f),
            m_translation(0.0f, 0.0f, 0.0f),
            m_cached_matrix(float4x4::identity),
            m_cache_refresh(false)
        {}

        const float3& get_scale() const
        {
            return m_scale;
        }

        void set_scale(const float3& new_scale)
        {
            m_scale = new_scale;
            m_cache_refresh = true;
        }

        void set_scale(float scale)
        {
            m_scale.x = scale;
            m_scale.y = scale;
            m_scale.z = scale;
            m_cache_refresh = true;
        }

        void set_scale(float x, float y, float z)
        {
            m_scale.x = x;
            m_scale.y = y;
            m_scale.z = z;
            m_cache_refresh = true;
        }

        const quaternion& get_rotation() const
        {
            return m_rotation;
        }

        void set_rotation(const quaternion& new_rotation)
        {
            m_rotation = new_rotation;
            m_cache_refresh = true;
        }

        const float3& get_translation() const
        {
            return m_translation;
        }

        void set_translation(const float3& new_translation)
        {
            m_translation = new_translation;
            m_cache_refresh = true;
        }

        void set_translation(float x, float y, float z)
        {
            m_translation.x = x;
            m_translation.y = y;
            m_translation.z = z;
            m_cache_refresh = true;
        }

        const float4x4& matrix()
        {
            if (m_cache_refresh)
            {
                compute_matrix();
            }

            return m_cached_matrix;
        }

    private:
        float3 m_scale;
        quaternion m_rotation;
        float3 m_translation;
        float4x4 m_cached_matrix;
        bool m_cache_refresh;

        void compute_matrix()
        {
            auto scale_matrix = float4x4::from_scale(m_scale);
            auto rotation_matrix = float4x4::from_quaternion(m_rotation);
            auto translation_matrix = float4x4::from_translation(m_translation);

            // ((Scale * Rotation) * Translation)
            float4x4::multiply(scale_matrix, rotation_matrix, m_cached_matrix);
            float4x4::multiply(m_cached_matrix, translation_matrix, m_cached_matrix);

            m_cache_refresh = false;
        }
    };
}