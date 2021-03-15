#pragma once

#include "data_model/elements/service_provider.hpp"

namespace openworld
{
    class data_model final :
        public service_provider
    {
    public:
        static const std::string ClassName;

        data_model(std::shared_ptr<instance_manager> instance_manager) :
            service_provider(instance_manager)
        {
        }

        virtual const std::string& class_name() const override
        {
            throw_if_destroyed();
            return ClassName;
        }
    };
}