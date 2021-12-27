#pragma once

#include "graphics_gl.hpp"

namespace openworld
{
    inline void* to_pimpl(GLuint value)
    {
        auto ptr_value = static_cast<uintptr_t>(value);
        auto ptr = reinterpret_cast<void*>(ptr_value);
        return ptr;
    }

    inline GLuint from_pimpl(void* pimpl)
    {
        auto pimpl_value = reinterpret_cast<uintptr_t>(pimpl);
        auto value = static_cast<GLuint>(pimpl_value);
        return value;
    }




    inline GLuint to_gl_vertex_buffer_id(const vertex_buffer& vb)
    {
        auto gl_impl = dynamic_cast<gl_vertex_buffer_impl*>(vb.impl());
        if (gl_impl == nullptr)
        {
            throw std::exception("invalid impl type");
        }

        return gl_impl->gl_buffer_id();
    }

    inline GLuint to_gl_index_buffer_id(const index_buffer& ib)
    {
        auto gl_impl = dynamic_cast<gl_index_buffer_impl*>(ib.impl());
        if (gl_impl == nullptr)
        {
            throw std::exception("invalid impl type");
        }

        return gl_impl->gl_buffer_id();
    }















    constexpr GLenum to_gl_enum(shader_stage stage)
    {
        switch (stage)
        {
        case shader_stage::vertex_shader:
            return GL_VERTEX_SHADER;
        case shader_stage::pixel_shader:
            return GL_FRAGMENT_SHADER;
        }

        throw std::runtime_error("Unknown shader stage");
    }

    constexpr GLenum to_gl_enum(primitive_type prim_type)
    {
        switch (prim_type)
        {
        case primitive_type::triangle_list:
            return GL_TRIANGLES;
        case primitive_type::triangle_strip:
            return GL_TRIANGLE_STRIP;
        case primitive_type::line_list:
            return GL_LINES;
        case primitive_type::line_strip:
            return GL_LINE_STRIP;
        case primitive_type::point_list:
            return GL_POINTS;
        }

        throw std::runtime_error("Unknown primitive type");
    }

    constexpr GLbitfield to_gl_bitfield(clear_options options)
    {
        GLbitfield value = 0;

        if (has_flag(options, clear_options::target))
        {
            value |= GL_COLOR_BUFFER_BIT;
        }

        if (has_flag(options, clear_options::depth))
        {
            value |= GL_DEPTH_BUFFER_BIT;
        }

        if (has_flag(options, clear_options::stencil))
        {
            value |= GL_STENCIL_BUFFER_BIT;
        }

        return value;
    }

    constexpr void to_gl_vertex_format(
        const vertex_element& elem,
        GLint& elem_count,
        GLenum& element_type,
        GLboolean& elem_normalized)
    {
        switch (elem.format)
        {
        case vertex_format::color:
            elem_count = 4;
            element_type = GL_UNSIGNED_BYTE;
            elem_normalized = GL_TRUE;
            return;

        case vertex_format::ushort:
            elem_count = 1;
            element_type = GL_UNSIGNED_SHORT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::ushort2:
            elem_count = 2;
            element_type = GL_UNSIGNED_SHORT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::ushort4:
            elem_count = 4;
            element_type = GL_UNSIGNED_SHORT;
            elem_normalized = GL_FALSE;
            return;

        case vertex_format::normalized_ushort:
            elem_count = 1;
            element_type = GL_UNSIGNED_SHORT;
            elem_normalized = GL_TRUE;
            return;
        case vertex_format::normalized_ushort2:
            elem_count = 2;
            element_type = GL_UNSIGNED_SHORT;
            elem_normalized = GL_TRUE;
            return;
        case vertex_format::normalized_ushort4:
            elem_count = 4;
            element_type = GL_UNSIGNED_SHORT;
            elem_normalized = GL_TRUE;
            return;

        case vertex_format::short_:
            elem_count = 1;
            element_type = GL_SHORT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::short2:
            elem_count = 2;
            element_type = GL_SHORT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::short4:
            elem_count = 4;
            element_type = GL_SHORT;
            elem_normalized = GL_FALSE;
            return;

        case vertex_format::normalized_short:
            elem_count = 1;
            element_type = GL_SHORT;
            elem_normalized = GL_TRUE;
            return;
        case vertex_format::normalized_short2:
            elem_count = 2;
            element_type = GL_SHORT;
            elem_normalized = GL_TRUE;
            return;
        case vertex_format::normalized_short4:
            elem_count = 4;
            element_type = GL_SHORT;
            elem_normalized = GL_TRUE;
            return;

        case vertex_format::uint:
            elem_count = 1;
            element_type = GL_UNSIGNED_INT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::uint2:
            elem_count = 2;
            element_type = GL_UNSIGNED_INT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::uint3:
            elem_count = 3;
            element_type = GL_UNSIGNED_INT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::uint4:
            elem_count = 4;
            element_type = GL_UNSIGNED_INT;
            elem_normalized = GL_FALSE;
            return;

        case vertex_format::int_:
            elem_count = 1;
            element_type = GL_INT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::int2:
            elem_count = 2;
            element_type = GL_INT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::int3:
            elem_count = 3;
            element_type = GL_INT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::int4:
            elem_count = 1;
            element_type = GL_INT;
            elem_normalized = GL_FALSE;
            return;

        case vertex_format::half:
            elem_count = 1;
            element_type = GL_HALF_FLOAT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::half2:
            elem_count = 2;
            element_type = GL_HALF_FLOAT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::half4:
            elem_count = 4;
            element_type = GL_HALF_FLOAT;
            elem_normalized = GL_FALSE;
            return;

        case vertex_format::float_:
            elem_count = 1;
            element_type = GL_FLOAT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::float2:
            elem_count = 2;
            element_type = GL_FLOAT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::float3:
            elem_count = 3;
            element_type = GL_FLOAT;
            elem_normalized = GL_FALSE;
            return;
        case vertex_format::float4:
            elem_count = 4;
            element_type = GL_FLOAT;
            elem_normalized = GL_FALSE;
            return;
        }

        throw std::runtime_error("Unknown element format");
    }
}