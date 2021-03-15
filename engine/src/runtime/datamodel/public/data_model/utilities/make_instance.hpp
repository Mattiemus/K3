#pragma once

#include <type_traits>
#include <memory>
#include <string>

#include "data_model/utilities/invoke_by_class_name.hpp"
#include "data_model/exceptions/abstract_instance_class.hpp"

namespace openworld
{
    namespace detail
    {
        template <typename Instance>
        struct make_instance_impl
        {
            std::shared_ptr<instance> operator()(std::shared_ptr<instance_manager> instance_manager)
            {
                return invoke(instance_manager, std::is_abstract<Instance>{});
            }

            std::shared_ptr<instance> invoke(std::shared_ptr<instance_manager> instance_manager, std::true_type)
            {
                throw abstract_instance_class(Instance::ClassName);
            }

            std::shared_ptr<instance> invoke(std::shared_ptr<instance_manager> instance_manager, std::false_type)
            {
                auto inst = std::make_shared<Instance>(instance_manager);
                inst->set_name(Instance::ClassName);

                instance_manager->on_instance_created(inst);

                return std::static_pointer_cast<instance>(inst);
            }
        };
    }

    template <typename Instance>
    std::shared_ptr<Instance> make_instance(std::shared_ptr<instance_manager> instance_manager)
    {
        auto inst = detail::make_instance_impl<Instance>()(instance_manager);
        return std::static_pointer_cast<Instance>(inst);
    }

    inline std::shared_ptr<instance> make_instance(std::shared_ptr<instance_manager> instance_manager, const std::string& class_name)
    {
        return invoke_by_class_name<detail::make_instance_impl>(class_name, instance_manager);
    }
}