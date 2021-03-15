#pragma once

#include "lua_scripting/context/lua_execution_context.hpp"

namespace openworld
{
    void register_script_language_enum(std::shared_ptr<lua_execution_context> execution_context);
}