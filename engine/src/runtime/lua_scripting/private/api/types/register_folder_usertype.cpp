#include "data_model/elements/folder.hpp"
#include "lua_scripting/api/types/instance_usertypes.hpp"
#include "lua_scripting/data_model/make_instance_as_lua.hpp"

using namespace openworld;

void openworld::register_folder_usertype(std::shared_ptr<lua_execution_context> execution_context)
{
    auto& lua = execution_context->state();
    auto instance_manager = execution_context->instance_manager();

    auto lua_usertype = lua.new_usertype<folder>(folder::ClassName);

    lua_usertype[sol::base_classes] =
        sol::bases<instance>();

    lua_usertype[sol::meta_function::construct] =
        sol::factories(
            [=](sol::this_state s)
            {
                return make_instance_as_lua<folder>(s, instance_manager);
            },
            [=](sol::this_state s, openworld::instance* parent)
            {
                return make_instance_as_lua<folder>(s, instance_manager, parent);
            },
            [=](sol::this_state s, const sol::table& properties)
            {
                return make_instance_as_lua<folder>(s, instance_manager, properties);
            }
        );
}