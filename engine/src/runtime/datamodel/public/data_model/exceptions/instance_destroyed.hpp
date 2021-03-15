#pragma once

#include <stdexcept>

namespace openworld
{
    class instance_destroyed final :
        public std::runtime_error
    {
    public:
        instance_destroyed() :
            std::runtime_error("Instance has already been destroyed")
        {
        }
    };
}