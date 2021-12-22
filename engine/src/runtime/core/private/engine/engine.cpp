#include <stdexcept>

#include "core/engine/engine.hpp"

using namespace openworld;

bool engine::s_is_initialised = false;
service_locator engine::s_services;

void engine::initialize()
{
    if (s_is_initialised)
    {
        throw std::runtime_error("Engine is already initialised");
    }

    // TOOD
}