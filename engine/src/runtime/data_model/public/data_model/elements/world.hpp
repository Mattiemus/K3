#pragma once

#include "data_model/elements/instance.hpp"
#include "data_model/services/base_world_service.hpp"

namespace openworld
{
    class world final :
        public instance
    {
    public:
        static const std::string ClassName;

        world(std::shared_ptr<base_world_service> impl, const std::string& name = ClassName) :
            instance(name), m_impl(impl)
        {
            impl->attatch(this);
        }

        virtual ~world()
        {
            m_impl->detatch(this);
        }

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }

    private:
        std::shared_ptr<base_world_service> m_impl;
    };
}