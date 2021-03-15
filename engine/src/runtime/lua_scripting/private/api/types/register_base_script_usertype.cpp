#include "data_model/elements/base_script.hpp"
#include "lua_scripting/api/types/instance_usertypes.hpp"
#include "lua_scripting/data_model/make_instance_as_lua.hpp"

using namespace openworld;

void openworld::register_base_script_usertype(std::shared_ptr<lua_execution_context> execution_context)
{
    auto& lua = execution_context->state();

    auto lua_usertype = lua.new_usertype<base_script>(base_script::ClassName);

    lua_usertype[sol::base_classes] =
        sol::bases<instance>();

    lua_usertype[sol::meta_function::construct] = sol::no_constructor;

    lua_usertype["Language"] =
        sol::property(
            &base_script::get_language,
            &base_script::set_language);

    lua_usertype["Source"] =
        sol::property(
            &base_script::get_source,
            &base_script::set_source);
}