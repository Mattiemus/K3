#pragma once

#include <stdexcept>

namespace openworld
{
    class abstract_instance_class final :
        public std::runtime_error
    {
    public:
        abstract_instance_class(const std::string& class_name) :
            std::runtime_error("Instance class '" + class_name + "' is abstract and cannot be created")
        {
        }
    };
}