#pragma once

#include <memory>

#include "data_model/elements.hpp"

namespace openworld
{
    class instance_manager final :
        public std::enable_shared_from_this<instance_manager>
    {
    public:
        instance_manager()
        {
        }

        std::shared_ptr<data_model> data_model()
        {
            // TODO
            return nullptr;
        }

        void on_instance_created(std::shared_ptr<instance> instance)
        {
            // TODO
        }

        void on_instance_destroyed(std::shared_ptr<instance> instance)
        {
            // TODO
        }
    };
}