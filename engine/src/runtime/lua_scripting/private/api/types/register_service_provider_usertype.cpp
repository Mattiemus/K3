#include "data_model/elements/service_provider.hpp"
#include "lua_scripting/api/types/instance_usertypes.hpp"
#include "lua_scripting/data_model/make_instance_as_lua.hpp"

using namespace openworld;

void openworld::register_service_provider_usertype(std::shared_ptr<lua_execution_context> execution_context)
{
    auto& lua = execution_context->state();

    auto lua_usertype = lua.new_usertype<service_provider>(service_provider::ClassName);

    lua_usertype[sol::base_classes] =
        sol::bases<instance>();

    lua_usertype[sol::meta_function::construct] = sol::no_constructor;
}