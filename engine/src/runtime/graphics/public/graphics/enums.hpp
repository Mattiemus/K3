#pragma once

namespace openworld
{
    enum class index_format
    {
        ushort,
        uint
    };

    constexpr size_t format_size(index_format format) noexcept
    {
        switch (format)
        {
        case index_format::ushort:
            return sizeof(unsigned short);
        case index_format::uint:
            return sizeof(unsigned int);
        default:
            return 0;
        }
    }

    enum class surface_format
    {
        color = 0,
        bgr_color = 1,
        bgr565 = 2,
        bgra5551 = 3,
        dxt1 = 4,
        dxt3 = 5,
        dxt5 = 6,
        rgba1010102 = 7,
        rg32 = 8,
        rgba64 = 9,
        alpha8 = 10,
        _float = 11,
        float2 = 12,
        float3 = 13,
        float4 = 14
    };

    enum class graphics_resource_type
    {
        vertex_buffer,
        index_buffer,
        swap_chain
    };

    enum class resource_usage
    {
        static_usage = 0,
        dynamic_usage = 1,
        immutable = 2
    };

    enum class shader_language
    {
        glsl_source
    };

    enum class shader_stage
    {
        vertex_shader,
        hull_shader,
        domain_shader,
        geometry_shader,
        pixel_shader,
        compute_shader
    };

    enum class clear_options
    {
        depth = 1,
        stencil = 2,
        target = 4,
        all = target | depth | stencil
    };
    OPENWORLD_DEFINE_ENUM_FLAG_OPERATORS(clear_options);

    enum class primitive_type
    {
        triangle_list = 0,
        triangle_strip = 1,
        line_list = 2,
        line_strip = 3,
        point_list = 4
    };

    enum class vertex_semantic
    {
        position = 0,
        color = 1,
        texture_coordinate = 2,
        normal = 3,
        tangent = 4,
        bitangent = 5,
        blend_indices = 6,
        blend_weight = 7,
        user_defined = 8
    };

    enum class vertex_format
    {
        color = 0,

        ushort = 1,
        ushort2 = 2,
        ushort4 = 3,

        normalized_ushort = 4,
        normalized_ushort2 = 5,
        normalized_ushort4 = 6,

        short_ = 7,
        short2 = 8,
        short4 = 9,

        normalized_short = 10,
        normalized_short2 = 11,
        normalized_short4 = 12,

        uint = 13,
        uint2 = 14,
        uint3 = 15,
        uint4 = 16,

        int_ = 17,
        int2 = 18,
        int3 = 19,
        int4 = 20,

        half = 21,
        half2 = 22,
        half4 = 23,

        float_ = 24,
        float2 = 25,
        float3 = 26,
        float4 = 27
    };

    constexpr size_t format_size(vertex_format format) noexcept
    {
        switch (format)
        {
        case vertex_format::color:
            return sizeof(color);
        case vertex_format::ushort:
        case vertex_format::normalized_ushort:
            return sizeof(unsigned short);
        case vertex_format::short_:
        case vertex_format::normalized_short:
            return sizeof(short);
        case vertex_format::ushort2:
        case vertex_format::normalized_ushort2:
            return sizeof(ushort2);
        case vertex_format::short2:
        case vertex_format::normalized_short2:
            return sizeof(short2);
        case vertex_format::ushort4:
        case vertex_format::normalized_ushort4:
            return sizeof(ushort4);
        case vertex_format::short4:
        case vertex_format::normalized_short4:
            return sizeof(short4);
        case vertex_format::uint:
            return sizeof(unsigned int);
        case vertex_format::int_:
            return sizeof(int);
        case vertex_format::uint2:
            return sizeof(uint2);
        case vertex_format::int2:
            return sizeof(int2);
        case vertex_format::uint3:
            return sizeof(uint3);
        case vertex_format::int3:
            return sizeof(int3);
        case vertex_format::uint4:
            return sizeof(uint4);
        case vertex_format::int4:
            return sizeof(int4);
        case vertex_format::half:
            return sizeof(half);
        case vertex_format::half2:
            return sizeof(half2);
        case vertex_format::half4:
            return sizeof(half4);
        case vertex_format::float_:
            return sizeof(float);
        case vertex_format::float2:
            return sizeof(float2);
        case vertex_format::float3:
            return sizeof(float3);
        case vertex_format::float4:
            return sizeof(float4);
        default:
            return 0;
        }
    }

    enum class data_write_options
    {
        none,
        discard,
        no_overwrite
    };

    enum class depth_format
    {
        none = 0,
        depth16 = 1,
        depth24_stencil8 = 2,
        depth32 = 3,
        depth32_stencil8 = 4
    };

    enum class present_interval
    {
        immediate = 0,
        one = 1,
        two = 2
    };

    enum class render_target_usage
    {
        discard_contents = 0,
        preserve_contents = 1,
        platform_default = 2
    };

    enum class display_orientation
    {
        _default = 0,
        landscape_left = 1,
        landscape_right = 2,
        Portrait = 4
    };
    OPENWORLD_DEFINE_ENUM_FLAG_OPERATORS(display_orientation);
}