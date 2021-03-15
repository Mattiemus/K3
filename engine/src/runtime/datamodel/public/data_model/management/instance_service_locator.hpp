#pragma once

#include <memory>

#include "data_model/elements.hpp"

namespace openworld
{
    class instance_service_locator final
    {
    public:
        instance_service_locator(std::shared_ptr<instance_manager> instance_manager)
        {
        }

        bool has_service_instance(std::shared_ptr<service_provider> provider, const std::string& class_name)
        {
            // TODO
            return false;
        }

        std::shared_ptr<instance> find_service_instance(std::shared_ptr<service_provider> provider, const std::string& class_name)
        {
            // TODO
            return nullptr;
        }

        std::shared_ptr<instance> get_service_instance(std::shared_ptr<service_provider> provider, const std::string& class_name)
        {
            // TODO
            return nullptr;
        }
    };
}