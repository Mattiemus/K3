#include "data_model/elements/base_script.hpp"
#include "lua_scripting/api/enums/instance_enums.hpp"

void openworld::register_script_language_enum(std::shared_ptr<openworld::lua_execution_context> execution_context)
{
    auto& lua = execution_context->state();

    lua.new_enum<openworld::script_language>(
        "ScriptLanguage",
        {
            { "Lua", openworld::script_language::lua }
        });
}