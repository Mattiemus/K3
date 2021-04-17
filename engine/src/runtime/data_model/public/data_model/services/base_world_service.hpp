#pragma once

#include "data_model/services/base_data_model_service.hpp"

namespace openworld
{
    class world;

    class base_world_service :
        public base_data_model_service<world>
    {
    public:
        virtual ~base_world_service() = 0 {};
    };
}