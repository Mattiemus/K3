#pragma once

#include "sol/sol.hpp"

#include "data_model/utilities/invoke_by_class_name.hpp"

namespace openworld
{
    namespace detail
    {
        template <typename Instance>
        struct instance_to_lua_object_impl
        {
            sol::object operator ()(lua_State* lua, std::shared_ptr<instance> inst)
            {
                return { lua, sol::in_place, std::static_pointer_cast<Instance>(inst) };
            }
        };
    }

    inline sol::object to_lua_object(lua_State* lua, std::shared_ptr<instance> inst)
    {
        return invoke_by_class_name<detail::instance_to_lua_object_impl>(inst->class_name(), lua, inst);
    }
}