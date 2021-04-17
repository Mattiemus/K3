#pragma once

#include "data_model/services/base_data_model_service.hpp"

namespace openworld
{
    class lighting;

    class base_lighting_service :
        public base_data_model_service<lighting>
    {
    public:
        virtual ~base_lighting_service() = 0 {};
    };
}