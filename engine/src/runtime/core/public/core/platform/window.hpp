#pragma once

#include <string>

namespace openworld
{
    class window
    {
    public:
        virtual ~window() = 0 {}

        virtual void* handle() = 0;

        virtual std::string get_title() = 0;
        virtual void set_title(const std::string& new_title) = 0;
    };
}