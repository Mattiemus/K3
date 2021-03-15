#include "data_model/elements/data_model.hpp"
#include "lua_scripting/api/types/instance_usertypes.hpp"
#include "lua_scripting/data_model/make_instance_as_lua.hpp"

using namespace openworld;

void openworld::register_data_model_usertype(std::shared_ptr<lua_execution_context> execution_context)
{
    auto& lua = execution_context->state();

    auto lua_usertype = lua.new_usertype<data_model>(data_model::ClassName);

    lua_usertype[sol::base_classes] =
        sol::bases<service_provider, instance>();

    lua_usertype[sol::meta_function::construct] = sol::no_constructor;
}