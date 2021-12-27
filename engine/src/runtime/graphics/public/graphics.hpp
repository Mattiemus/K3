#pragma once

#include <vector>
#include <span>
#include <initializer_list>
#include <string>
#include <stdexcept>
#include <memory>

#include "core/math/color.hpp"
#include "core/math/float2.hpp"
#include "core/math/float3.hpp"
#include "core/math/float4.hpp"
#include "core/math/short2.hpp"
#include "core/math/short4.hpp"
#include "core/math/ushort2.hpp"
#include "core/math/ushort4.hpp"
#include "core/math/int2.hpp"
#include "core/math/int3.hpp"
#include "core/math/int4.hpp"
#include "core/math/uint2.hpp"
#include "core/math/uint3.hpp"
#include "core/math/uint4.hpp"
#include "core/math/half.hpp"
#include "core/math/half2.hpp"
#include "core/math/half4.hpp"

#include "core/utilities/enums.hpp"

#include "graphics/enums.hpp"
#include "graphics/exceptions.hpp"
#include "graphics/graphics_resource.hpp"
#include "graphics/vertex_element.hpp"
#include "graphics/vertex_layout.hpp"
#include "graphics/vertex_structures.hpp"

#include "graphics/impl/graphics_resource_impl.hpp"
#include "graphics/impl/vertex_buffer_impl.hpp"

#include "graphics/vertex_buffer.hpp"
#include "graphics/vertex_buffer_binding.hpp"
#include "graphics/shader.hpp"
#include "graphics/shader_group.hpp"
#include "graphics/render_context.hpp"
#include "graphics/render_system.hpp"
