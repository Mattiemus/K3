#pragma once

#include "core/engine/service_locator.hpp"

namespace openworld
{
    class engine final
    {
    public:
        static service_locator& services()
        {
            return s_services;
        }

        static constexpr bool is_initialised()
        {
            return s_is_initialised;
        }

        static void initialize();

    private:
        static bool s_is_initialised;
        static service_locator s_services;

        engine() = delete;
        engine(const engine&) = delete;
        engine(engine&&) = delete;
    };
}