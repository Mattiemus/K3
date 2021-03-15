#pragma once

#include <stdexcept>
#include <type_traits>

#include "sol/sol.hpp"

#include "data_model/utilities/invoke_by_class_name.hpp"
#include "data_model/utilities/make_instance.hpp"
#include "lua_scripting/data_model/to_lua_object.hpp"

namespace openworld
{
    template <typename Instance>
    inline sol::object make_instance_as_lua(lua_State* lua, std::shared_ptr<instance_manager> instance_manager)
    {
        auto inst = make_instance<Instance>(instance_manager);
        return { lua, sol::in_place, inst };
    }

    template <typename Instance>
    inline sol::object make_instance_as_lua(lua_State* lua, std::shared_ptr<instance_manager> instance_manager, instance* parent)
    {
        auto inst = make_instance<Instance>(instance_manager);

        if (parent != nullptr)
        {
            inst->set_parent(parent->shared_from_this());
        }

        return { lua, sol::in_place, inst };
    }

    template <typename Instance>
    inline sol::object make_instance_as_lua(lua_State* lua, std::shared_ptr<instance_manager> instance_manager, const sol::table& properties)
    {
        auto inst = make_instance<Instance>(instance_manager);

        // TODO: m_lua_instance_deserializer->deserialize(*inst, properties);

        return { lua, sol::in_place, inst };
    }

    namespace detail
    {
        template <typename Instance>
        struct make_instance_as_lua_impl
        {
            sol::object operator()(lua_State* lua, std::shared_ptr<instance_manager> instance_manager)
            {
                return make_instance_as_lua<Instance>(lua, instance_manager);
            }
        };

        template <typename Instance>
        struct make_instance_as_lua_with_parent_impl
        {
            sol::object operator()(lua_State* lua, std::shared_ptr<instance_manager> instance_manager, instance* parent)
            {
                return make_instance_as_lua<Instance>(lua, instance_manager, parent);
            }
        };

        template <typename Instance>
        struct make_instance_as_lua_with_properties_impl
        {
            sol::object operator()(lua_State* lua, std::shared_ptr<instance_manager> instance_manager, const sol::table& properties)
            {
                return make_instance_as_lua<Instance>(lua, instance_manager, properties);
            }
        };
    }

    inline sol::object make_instance_as_lua(lua_State* lua,
                                            std::shared_ptr<instance_manager> instance_manager,
                                            const std::string& class_name)
    {
        return invoke_by_class_name<detail::make_instance_as_lua_impl>(class_name, lua, instance_manager);
    }

    inline sol::object make_instance_as_lua(lua_State* lua,
                                            std::shared_ptr<instance_manager> instance_manager,
                                            const std::string& class_name,
                                            instance* parent)
    {
        return invoke_by_class_name<detail::make_instance_as_lua_with_parent_impl>(class_name, lua, instance_manager, parent);
    }

    inline sol::object make_instance_as_lua(lua_State* lua,
                                            std::shared_ptr<instance_manager> instance_manager,
                                            const std::string& class_name,
                                            const sol::table& properties)
    {
        return invoke_by_class_name<detail::make_instance_as_lua_with_properties_impl>(class_name, lua, instance_manager, properties);
    }
}