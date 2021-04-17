#pragma once

#include "data_model/services/base_data_model_service.hpp"

namespace openworld
{
    class scheduler;

    class base_scheduler_service :
        public base_data_model_service<scheduler>
    {
    public:
        virtual ~base_scheduler_service() = 0 {};

        virtual bool is_client() = 0;
        virtual bool is_server() = 0;
        virtual bool is_editor() = 0;
        virtual bool is_running() = 0;
        virtual void run() = 0;
        virtual void stop() = 0;
        virtual void pause() = 0;
    };
}