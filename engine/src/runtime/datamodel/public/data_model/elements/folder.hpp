#pragma once

#include "data_model/elements/instance.hpp"

namespace openworld
{
    class folder final :
        public instance
    {
    public:
        static const std::string ClassName;

        folder(std::shared_ptr<instance_manager> instance_manager) :
            instance(instance_manager)
        {
        }

        virtual const std::string& class_name() const override
        {
            throw_if_destroyed();
            return ClassName;
        }
    };
}