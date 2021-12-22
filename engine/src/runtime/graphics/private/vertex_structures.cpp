#include "graphics/vertex_structures.hpp"

using namespace openworld;

const vertex_layout vertex_position_color::vertex_layout{
    vertex_element(vertex_semantic::position, 0, vertex_format::float3),
    vertex_element(vertex_semantic::color, 0, vertex_format::float3)
};