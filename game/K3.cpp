#include <utility>
#include <any>

#include "data_model/utilities/make_instance.hpp"
#include "lua_scripting/api/register_api.hpp"
#include "lua_scripting/context/lua_execution_context.hpp"
#include "lua_scripting/data_model/make_instance_as_lua.hpp"

// TODO: Add instance_metadata class 
// TODO: Use metadata to prevent creation of blocked classes

int main()
{
    auto instance_manager = std::make_shared<openworld::instance_manager>();

    auto execution_context = openworld::make_lua_execution_context(openworld::lua_security_level::none, instance_manager);
    auto& lua = execution_context->state();
    sol::environment env { execution_context->state(), sol::create, execution_context->state().globals() };

    auto app = openworld::make_instance<openworld::data_model>(instance_manager);
    lua["app"] = app;

    lua["world"] = openworld::make_instance<openworld::data_model>(instance_manager);

    lua["script"] = openworld::make_instance<openworld::data_model>(instance_manager);

    try
    {
        auto res = lua.safe_script(
            "a = Folder.new();"
            "a.Parent = app;"
            ,
            env);
    }
    catch (const sol::error& e)
    {
        auto fdgfd = 5;
    }

    return 0;
}
