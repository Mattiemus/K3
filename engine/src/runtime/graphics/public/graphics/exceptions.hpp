#pragma once

#include <stdexcept>

namespace openworld
{
    class graphics_exception final :
        public std::runtime_error
    {
    public:
        graphics_exception() :
            runtime_error("Graphics exception")
        {
        }

        graphics_exception(const std::string& msg) :
            runtime_error(msg)
        {
        }
    };
}