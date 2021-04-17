#pragma once

#include "data_model/elements/instance.hpp"

namespace openworld
{
    class folder final :
        public instance
    {
    public:
        static const std::string ClassName;

        folder(const std::string& name = ClassName) :
            instance(name)
        {}

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }
    };
}