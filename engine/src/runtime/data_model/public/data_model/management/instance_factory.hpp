#pragma once

#include <type_traits>

#include "data_model/elements/base_script.hpp"
#include "data_model/elements/client_script.hpp"
#include "data_model/elements/data_model.hpp"
#include "data_model/elements/folder.hpp"
#include "data_model/elements/instance.hpp"
#include "data_model/elements/lighting.hpp"
#include "data_model/elements/scheduler.hpp"
#include "data_model/elements/service_provider.hpp"
#include "data_model/elements/sky.hpp"
#include "data_model/elements/world.hpp"
#include "data_model/exceptions.hpp"

namespace openworld
{
    class instance_factory final
    {
    public:
        instance_factory(std::shared_ptr<base_lighting_service> lighting_service,
                         std::shared_ptr<base_scheduler_service> scheduler_service,
                         std::shared_ptr<base_world_service> world_service) :
            m_lighting_service(lighting_service),
            m_scheduler_service(scheduler_service),
            m_world_service(world_service)
        {}

        template <typename Instance>
        instance_ptr<Instance> create(const std::string& name = Instance::ClassName) const
        {
            if constexpr (std::is_same_v<Instance, client_script>)
            {
                return instance_ptr<Instance>(std::make_shared<client_script>(name));
            }
            
            if constexpr (std::is_same_v<Instance, data_model>)
            {
                return instance_ptr<Instance>(std::make_shared<data_model>(name));
            }
            
            if constexpr (std::is_same_v<Instance, folder>)
            {
                return instance_ptr<Instance>(std::make_shared<folder>(name));
            }

            if constexpr (std::is_same_v<Instance, lighting>)
            {
                return instance_ptr<Instance>(std::make_shared<lighting>(m_lighting_service, name));
            }

            if constexpr (std::is_same_v<Instance, scheduler>)
            {
                return instance_ptr<Instance>(std::make_shared<scheduler>(m_scheduler_service, name));
            }
            
            if constexpr (std::is_same_v<Instance, sky>)
            {
                return instance_ptr<Instance>(std::make_shared<sky>(name));
            }
            
            if constexpr (std::is_same_v<Instance, world>)
            {
                return instance_ptr<Instance>(std::make_shared<world>(m_world_service, name));
            }
        }

    private:
        std::shared_ptr<base_lighting_service> m_lighting_service;
        std::shared_ptr<base_scheduler_service> m_scheduler_service;
        std::shared_ptr<base_world_service> m_world_service;
    };
}