#pragma once

#include "core.hpp"
#include "math.hpp"



class standard_library_content
{
public:
	virtual ~standard_library_content() = 0;

	virtual std::string standard_content_name() = 0;
	virtual bool is_standard_content() = 0;
};





#include "graphics/exceptions.hpp"
#include "graphics/enums.hpp"
#include "graphics/shader_resource.hpp"
#include "graphics/resource_region_1d.hpp"
#include "graphics/resource_region_2d.hpp"
#include "graphics/resource_region_3d.hpp"
#include "graphics/display_mode.hpp"
#include "graphics/output.hpp"
#include "graphics/presentation_parameters.hpp"
#include "graphics/vertex_element.hpp"
#include "graphics/vertex_layout.hpp"
#include "graphics/vertex_structures.hpp"
#include "graphics/graphics_adapter.hpp"
#include "graphics/msaa_description.hpp"
#include "graphics/render_state_key.hpp"
#include "graphics/render_target_blend_description.hpp"

#include "graphics/impl/graphics_resource_impl.hpp"
#include "graphics/impl/render_state_impl.hpp"
#include "graphics/graphics_resource.hpp"
#include "graphics/render_state.hpp"

#include "graphics/impl/vertex_buffer_impl.hpp"
#include "graphics/impl/index_buffer_impl.hpp"
#include "graphics/impl/swap_chain_impl.hpp"
#include "graphics/impl/occlusion_query_impl.hpp"
#include "graphics/impl/blend_state_impl.hpp"
#include "graphics/impl/depth_stencil_state_impl.hpp"
#include "graphics/impl/sampler_state_impl.hpp"
#include "graphics/impl/rasterizer_state_impl.hpp"
#include "graphics/impl/texture_impl.hpp"
#include "graphics/impl/texture_1d_impl.hpp"
#include "graphics/impl/texture_1d_array_impl.hpp"
#include "graphics/impl/texture_2d_impl.hpp"
#include "graphics/impl/texture_2d_array_impl.hpp"
#include "graphics/impl/texture_3d_impl.hpp"
#include "graphics/impl/texture_cube_impl.hpp"

#include "graphics/swap_chain.hpp"
#include "graphics/occlusion_query.hpp"
#include "graphics/vertex_buffer.hpp"
#include "graphics/vertex_buffer_binding.hpp"
#include "graphics/index_buffer.hpp"
#include "graphics/blend_state.hpp"
#include "graphics/depth_stencil_state.hpp"
#include "graphics/sampler_state.hpp"
#include "graphics/rasterizer_state.hpp"
#include "graphics/texture.hpp"
#include "graphics/texture_1d.hpp"
#include "graphics/texture_1d_array.hpp"
#include "graphics/shader.hpp"
#include "graphics/shader_group.hpp"
#include "graphics/shader_pipeline_stage.hpp"
#include "graphics/render_context.hpp"
#include "graphics/render_system.hpp"
