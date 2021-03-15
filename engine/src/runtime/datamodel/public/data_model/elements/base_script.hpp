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

        base_script(std::shared_ptr<instance_manager> instance_manager) :
            instance(instance_manager)
        {
        }

        virtual ~base_script() = 0 {}

        virtual const std::string& class_name() const override
        {
            throw_if_destroyed();
            return ClassName;
        }

        script_language get_language() const
        {
            throw_if_destroyed();
            return m_language;
        }

        void set_language(script_language new_language)
        {
            throw_if_destroyed();
            set_property_internal(m_language, new_language, LanguageProperty);
        }

        const std::string& get_source() const
        {
            throw_if_destroyed();
            return m_source;
        }

        void set_source(const std::string& new_source)
        {
            throw_if_destroyed();
            set_property_internal(m_source, new_source, SourceProperty);
        }

    private:
        script_language m_language = script_language::lua;
        std::string m_source;
    };
}