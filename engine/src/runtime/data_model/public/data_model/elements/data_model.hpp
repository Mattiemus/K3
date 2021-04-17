#pragma once

#include "data_model/elements/service_provider.hpp"

namespace openworld
{
    class data_model final :
        public service_provider
    {
    public:
        static const std::string ClassName;

        data_model(const std::string& name = ClassName) :
            service_provider(name)
        {}

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }
    };
}