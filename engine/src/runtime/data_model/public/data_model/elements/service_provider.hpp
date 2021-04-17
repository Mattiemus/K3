#pragma once

#include "data_model/elements/instance.hpp"

namespace openworld
{
    class service_provider :
        public instance
    {
    public:
        static const std::string ClassName;

        service_provider(const std::string& name = ClassName) :
            instance(name)
        {}

        virtual ~service_provider() = 0 {}

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }
    };
}