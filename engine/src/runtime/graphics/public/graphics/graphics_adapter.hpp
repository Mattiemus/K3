#pragma once

namespace openworld
{
    class graphics_adapter
    {
        OPENWORLD_DELETE_COPY_OPERATORS(graphics_adapter);

    public:
        virtual ~graphics_adapter() = 0 {}

        virtual const std::vector<display_mode>& supported_display_modes() const = 0;
        virtual const std::vector<output>& outputs() const = 0;
        virtual const std::string& description() const = 0;

        virtual int device_id() const = 0;
        virtual int revision() const = 0;
        virtual int sub_system_id() const = 0;
        virtual int vendor_id() const = 0;

        virtual bool is_default_adapter() const = 0;
        virtual size_t adapter_index() const = 0;

        virtual size_t maximum_texture_1d_size() const = 0;
        virtual size_t maximum_texture_1d_array_count() const = 0;
        virtual size_t maximum_texture_2d_size() const = 0;
        virtual size_t maximum_texture_2d_array_count() const = 0;
        virtual size_t maximum_texture_3d_size() const = 0;
        virtual size_t maximum_texture_cube_size() const = 0;
        virtual size_t maximum_texture_cube_array_count() const = 0;
        virtual size_t maximum_texture_resource_size() const = 0;
        virtual size_t maximum_multi_render_targets() const = 0;
        virtual size_t maximum_vertex_streams() const = 0;
        virtual size_t maximum_stream_output_targets() const = 0;
        virtual size_t dedicated_system_memory() const = 0;
        virtual size_t dedicated_video_memory() const = 0;
        virtual size_t shared_system_memory() const = 0;

        virtual bool check_texture_format(surface_format format, texture_dimension tex_type) const = 0;
        virtual bool check_render_target_format(surface_format format, depth_format depth_fmt, size_t multi_sample_count) const = 0;
        virtual bool check_back_buffer_format(surface_format format, depth_format depth_fmt, size_t multi_sample_count) const = 0;
        virtual bool is_multisample_resolvable(surface_format format) const = 0;
        virtual bool is_shader_stage_supported(shader_stage stage) const = 0;
        virtual size_t check_multisample_quality_levels(surface_format format, size_t multi_sample_count) const = 0;
    };
}