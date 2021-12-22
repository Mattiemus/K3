#pragma once

#include <memory>

#include "core/platform/impl/application_host_impl.hpp"

namespace openworld
{
    class platform_service
    {
    public:
        virtual ~platform_service() = 0 {}

        virtual std::shared_ptr<application_host_impl> create_application_host_impl() = 0;
    };
}