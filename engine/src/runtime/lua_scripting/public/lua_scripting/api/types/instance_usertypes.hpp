#pragma once

#include "lua_scripting/context/lua_execution_context.hpp"

namespace openworld
{
    void register_base_script_usertype(std::shared_ptr<lua_execution_context> execution_context);
    void register_data_model_usertype(std::shared_ptr<lua_execution_context> execution_context);
    void register_folder_usertype(std::shared_ptr<lua_execution_context> execution_context);
    void register_instance_usertype(std::shared_ptr<lua_execution_context> execution_context);
    void register_service_provider_usertype(std::shared_ptr<lua_execution_context> execution_context);
}