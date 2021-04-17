#pragma once

#include "data_model/elements/instance.hpp"
#include "data_model/services/base_scheduler_service.hpp"

namespace openworld
{
    class scheduler final :
        public instance
    {
    public:
        static const std::string ClassName;

        scheduler(std::shared_ptr<base_scheduler_service> impl, const std::string& name = ClassName) :
            instance(name), m_impl(impl)
        {
            impl->attatch(this);
        }

        virtual ~scheduler()
        {
            m_impl->detatch(this);
        }

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }

        bool is_client()
        {
            return m_impl->is_client();
        }

        bool is_server()
        {
            return m_impl->is_server();
        }

        bool is_editor()
        {
            return m_impl->is_editor();
        }

        bool is_running()
        {
            return m_impl->is_running();
        }

        void run()
        {
            m_impl->run();
        }

        void stop()
        {
            m_impl->stop();
        }

        void pause()
        {
            m_impl->pause();
        }


    private:
        std::shared_ptr<base_scheduler_service> m_impl;
    };
}