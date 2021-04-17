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

    class instance_destroyed final :
        public std::runtime_error
    {
    public:
        instance_destroyed() :
            std::runtime_error("Instance has already been destroyed")
        {
        }
    };

    class unknown_instance_class final :
        public std::runtime_error
    {
    public:
        unknown_instance_class() :
            std::runtime_error("Instance class is unknown")
        {
        }

        unknown_instance_class(const std::string& class_name) :
            std::runtime_error("Instance class '" + class_name + "' is unknown")
        {
        }
    };

    class bad_instance_parent final :
        public std::runtime_error
    {
    public:
        bad_instance_parent(const std::string& msg) :
            std::runtime_error(msg)
        {
        }
    };

    class service_not_found final :
        public std::runtime_error
    {
    public:
        service_not_found() :
            std::runtime_error("Could not find the specified service")
        {
        }
    };

    class service_already_attatched final :
        public std::runtime_error
    {
    public:
        service_already_attatched() :
            std::runtime_error("Cannot attatch service implementation as it has already been attatched")
        {
        }
    };

    class service_not_attatched final :
        public std::runtime_error
    {
    public:
        service_not_attatched() :
            std::runtime_error("Cannot detatch from different data model to the one the service is connected to")
        {
        }
    };
}