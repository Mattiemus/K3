#pragma once

#include "core/math/vector3.hpp"
#include "core/math/quaternion.hpp"
#include "core/math/matrix4x4.hpp"

namespace openworld
{
    class transform final
    {
    public:
        constexpr transform()
        {}

        const vector3& get_scale() const
        {
            return m_scale;
        }

        void set_scale(const vector3& new_scale)
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

        const vector3& get_translation() const
        {
            return m_translation;
        }

        void set_translation(const vector3& new_translation)
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

        const matrix4x4& matrix() const
        {
            if (m_cache_refresh)
            {
                compute_matrix();
            }

            return m_cached_matrix;
        }

    private:
        vector3 m_scale;
        quaternion m_rotation;
        vector3 m_translation;
        matrix4x4 m_cached_matrix;
        mutable bool m_cache_refresh = false;

        void compute_matrix() const
        {
            //Matrix.FromScale(m_scale, out Matrix scaleM);
            //Matrix.FromQuaternion(m_rotation, out Matrix rotationM);
            //Matrix.FromTranslation(m_translation, out Matrix translationM);

            ////((Scale * Rotation) * Translation)
            //Matrix.Multiply(scaleM, rotationM, out m_cachedMatrix);
            //Matrix.Multiply(m_cachedMatrix, translationM, out m_cachedMatrix);
            m_cache_refresh = false;
        }
    };
}