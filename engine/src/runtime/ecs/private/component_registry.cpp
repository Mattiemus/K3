#include "ecs.hpp"

using namespace openworld;

std::unordered_map<std::type_index, component_id> component_registry::s_component_ids;
component_id component_registry::s_next_component_id = 0;