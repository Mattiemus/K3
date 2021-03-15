#include "lua_scripting/api/register_api.hpp"
#include "lua_scripting/api/enums/instance_enums.hpp"
#include "lua_scripting/api/types/instance_usertypes.hpp"
#include "lua_scripting/context/lua_execution_context.hpp"

using namespace openworld;

void openworld::register_api(std::shared_ptr<lua_execution_context> execution_context)
{
    auto& lua = execution_context->state();
    lua.open_libraries(sol::lib::base);

    register_script_language_enum(execution_context);

    register_base_script_usertype(execution_context);
    register_data_model_usertype(execution_context);
    register_folder_usertype(execution_context);
    register_instance_usertype(execution_context);
    register_service_provider_usertype(execution_context);
}