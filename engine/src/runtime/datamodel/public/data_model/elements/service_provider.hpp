#pragma once

#include "data_model/elements/instance.hpp"

namespace openworld
{
    class service_provider :
        public instance
    {
    public:
        static const std::string ClassName;

        service_provider(std::shared_ptr<instance_manager> instance_manager) :
            instance(instance_manager)
        {
        }

        virtual ~service_provider() = 0 {}

        virtual const std::string& class_name() const override
        {
            throw_if_destroyed();
            return ClassName;
        }
    };
}