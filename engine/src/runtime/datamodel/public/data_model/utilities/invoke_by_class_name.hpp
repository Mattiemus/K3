#pragma once

#include <type_traits>
#include <string>
#include <map>
#include <functional>

#include "data_model/elements.hpp"
#include "data_model/exceptions/unknown_instance_class.hpp"

namespace openworld
{
    template <template<typename> typename Callback, typename... Args>
    auto invoke_by_class_name(const std::string& class_name, Args... args)
    {
        if (class_name == base_script::ClassName)
        {
            return Callback<base_script>()(args...);
        }
        
        if (class_name == data_model::ClassName)
        {
            return Callback<data_model>()(args...);
        }
        
        if (class_name == folder::ClassName)
        {
            return Callback<folder>()(args...);
        }
        
        if (class_name == instance::ClassName)
        {
            return Callback<instance>()(args...);
        }
        
        if (class_name == service_provider::ClassName)
        {
            return Callback<service_provider>()(args...);
        }

        throw unknown_instance_class(class_name);
    }
}