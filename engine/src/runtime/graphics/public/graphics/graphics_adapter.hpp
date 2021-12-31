#pragma once

namespace openworld
{
    class graphics_adapter
    {
    public:
        virtual ~graphics_adapter() = 0 {}

        virtual std::vector<display_mode> supported_display_modes() = 0;
        virtual std::vector<output> outputs() = 0;
        virtual std::string description() = 0;

        virtual int device_id() = 0;
        virtual int revision() = 0;
        virtual int sub_system_id() = 0;
        virtual int vendor_id() = 0;

        virtual bool is_default_adapter() = 0;
        virtual size_t adapter_index() = 0;

        virtual size_t maximum_texture_1d_size() = 0;
        virtual size_t maximum_texture_1d_array_count() = 0;
        virtual size_t maximum_texture_2d_size() = 0;
        virtual size_t maximum_texture_2d_array_count() = 0;
        virtual size_t maximum_texture_3d_size() = 0;
        virtual size_t maximum_texture_cube_size() = 0;
        virtual size_t maximum_texture_cube_array_count() = 0;
        virtual size_t maximum_texture_resource_size() = 0;
        virtual size_t maximum_multi_render_targets() = 0;
        virtual size_t maximum_vertex_streams() = 0;
        virtual size_t maximum_stream_output_targets() = 0;
        virtual size_t dedicated_system_memory() = 0;
        virtual size_t dedicated_video_memory() = 0;
        virtual size_t shared_system_memory() = 0;

        virtual bool check_texture_format(surface_format format, texture_dimension tex_type) = 0;
        virtual bool check_render_target_format(surface_format format, depth_format depth_fmt, size_t multi_sample_count) = 0;
        virtual bool check_back_buffer_format(surface_format format, depth_format depth_fmt, size_t multi_sample_count) = 0;
        virtual bool is_multisample_resolvable(surface_format format) = 0;
        virtual bool is_shader_stage_supported(shader_stage stage) = 0;
        virtual size_t check_multisample_quality_levels(surface_format format, size_t multi_sample_count) = 0;
    };
}