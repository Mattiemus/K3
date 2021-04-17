#pragma once

#include "data_model/elements/base_script.hpp"

namespace openworld
{
    class client_script final :
        public base_script
    {
    public:
        static const std::string ClassName;

        client_script(const std::string& name = ClassName) :
            base_script(name)
        {}

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }
    };
}