#pragma once

#include "data_model/exceptions.hpp"

#include <memory>
#include <stdexcept>

namespace openworld
{
    template <typename Instance>
    class base_data_model_service
    {
    public:
        virtual ~base_data_model_service() = 0 {};

        Instance* current_instance() const
        {
            return m_current_instance;
        }

        void attatch(Instance* inst)
        {
            if (m_current_inst != nullptr)
            {
                throw service_already_attatched();
            }

            m_current_inst = inst;
            on_attatch(inst);
        }

        void detatch(Instance* inst)
        {
            if (m_current_inst != inst)
            {
                throw service_not_attatched();
            }

            on_detatch();
            m_current_inst = nullptr;
        }

    protected:
        virtual void on_attatch(Instance* inst)
        {
            // No-op
        }

        virtual void on_detatch()
        {
            // No-op
        }

    private:
        Instance* m_current_inst = nullptr;
    };
}