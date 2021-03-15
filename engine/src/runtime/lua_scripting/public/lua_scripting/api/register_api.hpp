#pragma once

#include <memory>

namespace openworld
{
    class lua_execution_context;

    void register_api(std::shared_ptr<lua_execution_context> execution_context);
}