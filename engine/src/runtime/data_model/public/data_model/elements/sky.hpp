#pragma once

#include "data_model/types/content_ref.hpp"

namespace openworld
{
    class sky final :
        public instance
    {
    public:
        static const std::string ClassName;
        static const std::string SkyboxTopProperty;
        static const std::string SkyboxBottomProperty;
        static const std::string SkyboxLeftProperty;
        static const std::string SkyboxRightProperty;
        static const std::string SkyboxFrontProperty;
        static const std::string SkyboxBackProperty;

        sky(const std::string& name = ClassName) :
            instance(name)
        {}

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }

        const content_ref& get_skybox_top() const
        {
            return m_skybox_top;
        }

        void set_skybox_top(const content_ref& new_value)
        {
            set_property_internal(m_skybox_top, new_value, SkyboxTopProperty, property_changed_mode::normal);
        }

        const content_ref& get_skybox_bottom() const
        {
            return m_skybox_bottom;
        }

        void set_skybox_bottom(const content_ref& new_value)
        {
            set_property_internal(m_skybox_bottom, new_value, SkyboxBottomProperty, property_changed_mode::normal);
        }

        const content_ref& get_skybox_left() const
        {
            return m_skybox_left;
        }

        void set_skybox_left(const content_ref& new_value)
        {
            set_property_internal(m_skybox_left, new_value, SkyboxLeftProperty, property_changed_mode::normal);
        }

        const content_ref& get_skybox_right() const
        {
            return m_skybox_right;
        }

        void set_skybox_right(const content_ref& new_value)
        {
            set_property_internal(m_skybox_right, new_value, SkyboxRightProperty, property_changed_mode::normal);
        }

        const content_ref& get_skybox_front() const
        {
            return m_skybox_front;
        }

        void set_skybox_front(const content_ref& new_value)
        {
            set_property_internal(m_skybox_front, new_value, SkyboxFrontProperty, property_changed_mode::normal);
        }

        const content_ref& get_skybox_back() const
        {
            return m_skybox_back;
        }

        void set_skybox_back(const content_ref& new_value)
        {
            set_property_internal(m_skybox_back, new_value, SkyboxBackProperty, property_changed_mode::normal);
        }

    private:
        content_ref m_skybox_top;
        content_ref m_skybox_bottom;
        content_ref m_skybox_left;
        content_ref m_skybox_right;
        content_ref m_skybox_front;
        content_ref m_skybox_back;
    };
}