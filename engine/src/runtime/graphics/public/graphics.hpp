#pragma once

#include <vector>
#include <span>
#include <initializer_list>
#include <string>
#include <stdexcept>
#include <memory>

#include "math.hpp"

#include "core/utilities/enums.hpp"

#include "graphics/enums.hpp"
#include "graphics/exceptions.hpp"
#include "graphics/graphics_resource.hpp"
#include "graphics/vertex_element.hpp"
#include "graphics/vertex_layout.hpp"
#include "graphics/vertex_structures.hpp"

#include "graphics/impl/graphics_resource_impl.hpp"
#include "graphics/impl/vertex_buffer_impl.hpp"
#include "graphics/impl/index_buffer_impl.hpp"

#include "graphics/vertex_buffer.hpp"
#include "graphics/vertex_buffer_binding.hpp"
#include "graphics/index_buffer.hpp"
#include "graphics/shader.hpp"
#include "graphics/shader_group.hpp"
#include "graphics/render_context.hpp"
#include "graphics/render_system.hpp"
