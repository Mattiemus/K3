#pragma once

namespace openworld
{
    class platform_system
    {
    public:
        virtual ~platform_system() = 0;

        virtual std::string platform() = 0;

        virtual std::unique_ptr<application_host_impl> create_application_host_impl() = 0;
    };
}