#pragma once

namespace openworld
{
    class service_not_found final :
        public std::runtime_error
    {
    public:
        service_not_found() :
            std::runtime_error("Could not find the requested service")
        {
        }
    };
}