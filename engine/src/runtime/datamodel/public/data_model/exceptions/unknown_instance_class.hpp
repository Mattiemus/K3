#pragma once

#include <stdexcept>

namespace openworld
{
    class unknown_instance_class final :
        public std::runtime_error
    {
    public:
        unknown_instance_class(const std::string& class_name) :
            std::runtime_error("Instance class '" + class_name + "' is unknown")
        {
        }
    };
}