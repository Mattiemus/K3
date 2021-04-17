#pragma once

#include "data_model/elements/instance.hpp"
#include "data_model/services/base_lighting_service.hpp"

namespace openworld
{
    class lighting final :
        public instance
    {
    public:
        static const std::string ClassName;

        lighting(std::shared_ptr<base_lighting_service> impl, const std::string& name = ClassName) :
            instance(name), m_impl(impl)
        {
            impl->attatch(this);
        }

        virtual ~lighting()
        {
            m_impl->detatch(this);
        }

        virtual const std::string& class_name() const override
        {
            return ClassName;
        }

    private:
        std::shared_ptr<base_lighting_service> m_impl;
    };
}