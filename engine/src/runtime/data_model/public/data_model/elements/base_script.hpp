#pragma once

#include "data_model/elements/instance.hpp"

namespace openworld
{
    enum class script_language
    {
        lua
    };

    class base_script :
        public instance
    {
    public:
        static const std::string ClassName;
        static const std::string LanguageProperty;
        static const std::string SourceProperty;

        base_script(const std::string& name = ClassName) :
            instance(name)
        {}

        virtual ~base_script() = 0 {}

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }

        script_language get_language() const
        {
            return m_language;
        }

        void set_language(script_language new_language)
        {
            set_property_internal(m_language, new_language, LanguageProperty, property_changed_mode::normal);
        }

        const std::string& get_source() const
        {
            return m_source;
        }

        void set_source(const std::string& new_source)
        {
            set_property_internal(m_source, new_source, SourceProperty, property_changed_mode::normal);
        }

    private:
        script_language m_language = script_language::lua;
        std::string m_source;
    };
}