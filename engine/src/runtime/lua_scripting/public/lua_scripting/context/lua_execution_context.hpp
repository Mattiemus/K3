#pragma once

#include "sol/sol.hpp"

#include "data_model/management/instance_manager.hpp"
#include "lua_scripting/api/register_api.hpp"

namespace openworld
{
    enum class lua_security_level
    {
        none,
        trusted
    };

    class lua_execution_context final
    {
    public:
        lua_execution_context::lua_execution_context(lua_security_level security_level,
                                                     std::shared_ptr<openworld::instance_manager> instance_manager) :
            m_security_level(security_level),
            m_instance_manager(instance_manager)
        {
        }

        lua_security_level security_level() const
        {
            return m_security_level;
        }

        std::shared_ptr<openworld::instance_manager> instance_manager() const
        {
            return m_instance_manager;
        }

        sol::state& state()
        {
            return m_state;
        }

    private:
        lua_security_level m_security_level;
        std::shared_ptr<openworld::instance_manager> m_instance_manager;
        sol::state m_state;
    };

    inline std::shared_ptr<lua_execution_context> make_lua_execution_context(lua_security_level security_level,
                                                                             std::shared_ptr<openworld::instance_manager> instance_manager)
    {
        auto execution_context = std::make_shared<lua_execution_context>(security_level, instance_manager);
        openworld::register_api(execution_context);
        return execution_context;
    }
}