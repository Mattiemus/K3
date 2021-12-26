#include "graphics_gl.hpp"
#include "gl_helpers.hpp"

#include "graphics/render_context.hpp"
#include "graphics/vertex_structures.hpp"

using namespace openworld;

render_context::render_context()
{
    auto* impl = new gl_render_context_impl{ 0 };
    m_pimpl = to_pimpl(impl);
}

render_context::~render_context()
{
    auto* impl = from_pimpl<gl_render_context_impl>(m_pimpl);

    delete impl;
    m_pimpl = nullptr;
}

bool render_context::is_immediate_context()
{
    return true;
}

void render_context::set_vertex_buffer(const vertex_buffer_binding& vertex_buffer)
{
    auto* impl = from_pimpl<gl_render_context_impl>(m_pimpl);

    if (impl->vao == 0)
    {
        glGenVertexArrays(1, &impl->vao);
        glBindVertexArray(impl->vao);
    }

    auto& vertex_buff = vertex_buffer.buffer;
    const auto& vertex_layout = vertex_buff.layout();

    GLuint idx = 0;
    for (const auto& vertex_elem : vertex_layout.vertex_elements())
    {
        glEnableVertexAttribArray(idx);

        GLint elem_count{};
        GLenum element_type{};
        GLboolean elem_normalized{};

        to_gl_vertex_format(
            vertex_elem,
            elem_count,
            element_type,
            elem_normalized);

        glVertexAttribBinding(
            idx,
            idx);

        glVertexAttribFormat(
            idx,
            elem_count,
            element_type,
            elem_normalized,
            0);

        glBindVertexBuffer(
            idx,
            from_pimpl(vertex_buff.pimpl()),
            vertex_elem.offset,
            static_cast<GLsizei>(vertex_layout.vertex_stride()));

        idx++;
    }
}

void render_context::clear(const color& clear_color)
{
    clear(clear_options::all, clear_color, 1.0f, 0);
}

void render_context::clear(
    clear_options options,
    const color& clear_color,
    float depth,
    int stencil)
{
    if (has_flag(options, clear_options::target))
    {
        auto clear_color_v4 = to_vector4(clear_color);
        glClearColor(clear_color_v4.x, clear_color_v4.y, clear_color_v4.z, clear_color_v4.w);
    }

    if (has_flag(options, clear_options::depth))
    {
        glClearDepth(depth);
    }

    if (has_flag(options, clear_options::stencil))
    {
        glClearStencil(stencil);
    }

    auto clear_bits = to_gl_bitfield(options);
    glClear(clear_bits);
}

void render_context::draw(
    primitive_type prim_type,
    size_t vertex_count,
    size_t start_vertex_index)
{
    auto draw_mode = to_gl_enum(prim_type);

    glDrawArrays(
        draw_mode,
        static_cast<GLint>(start_vertex_index),
        static_cast<GLsizei>(vertex_count));
}

void render_context::draw_indexed(
    primitive_type prim_type,
    size_t index_count,
    size_t start_index,
    size_t base_vertex_offset)
{
    auto draw_mode = to_gl_enum(prim_type);
    GLenum index_type = GL_UNSIGNED_SHORT;

    glDrawElementsBaseVertex(
        draw_mode,
        static_cast<GLsizei>(index_count),
        index_type,
        reinterpret_cast<void*>(start_index),
        static_cast<GLint>(base_vertex_offset));
}

void render_context::draw_indexed_instanced(
    primitive_type prim_type,
    size_t index_count_per_instance,
    size_t instance_count,
    size_t start_index,
    size_t base_vertex_offset,
    size_t start_instance_offset)
{
    auto draw_mode = to_gl_enum(prim_type);
    GLenum index_type = GL_UNSIGNED_SHORT;

    glDrawElementsInstancedBaseVertex(
        draw_mode,
        static_cast<GLsizei>(index_count_per_instance),
        index_type,
        reinterpret_cast<void*>(start_index),
        static_cast<GLsizei>(instance_count),
        static_cast<GLuint>(base_vertex_offset));
}

void render_context::draw_instanced(
    primitive_type prim_type,
    size_t vertex_count_per_instance,
    size_t instance_count,
    size_t base_vertex_offset,
    size_t start_instance_offset)
{
    auto draw_mode = to_gl_enum(prim_type);

    glDrawArraysInstancedBaseInstance(
        draw_mode,
        static_cast<GLint>(base_vertex_offset),
        static_cast<GLsizei>(vertex_count_per_instance),
        static_cast<GLsizei>(instance_count),
        static_cast<GLuint>(start_instance_offset));
}

void render_context::draw_auto(primitive_type prim_type)
{
    auto draw_mode = to_gl_enum(prim_type);

    glDrawTransformFeedback(draw_mode, 0);
}

void render_context::flush()
{
    glFlush();
}