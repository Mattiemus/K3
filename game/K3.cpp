#include "core.hpp"
#include "math.hpp"
#include "graphics_gl.hpp"

using namespace openworld;

int main()
{
    engine::initialize();
    engine::services().make_service<platform_system, win32_platform_system>();
    engine::services().make_service<render_system, gl_render_system>();

    application_host app_host{};
    auto win = app_host.create_window(true);

    auto render_sys = engine::services().get_service<render_system>();
    auto& ctx = render_sys->immediate_context();


    gl_swap_chain swap_chain{ win };


    shader vertex_shader(
        shader_language::glsl_source,
        shader_stage::vertex_shader,
        "#version 400\n"
        "layout(location = 0) in vec3 vertex_position;\n"
        "layout(location = 1) in vec4 vertex_colour;\n"
        "out vec4 colour;\n"
        "void main() {\n"
        "    colour = vertex_colour;\n"
        "    gl_Position = vec4(vertex_position, 1.0);\n"
        "}\n");

    shader frag_shader(
        shader_language::glsl_source,
        shader_stage::pixel_shader,
        "#version 400\n"
        "in vec4 colour;\n"
        "out vec4 frag_colour;\n"
        "void main() {\n"
        "  frag_colour = colour;\n"
        "}\n");

    gl_shader_group shader_group({ vertex_shader, frag_shader });




    std::vector<vertex_position_color> vertices{
        { { -0.5f,  0.5f,  0.0f }, { 255, 0,  0, 255 } },
        { { 0.5f, -0.5f,  0.0f }, { 0, 255,  0, 255 } },
        { { -0.5f, -0.5f,  0.0f }, { 0, 0,  255, 255 } },
        { { 0.5f,  0.5f,  0.0f }, { 255, 0,  0, 255 } },
    };
    const auto& vertices_layout = vertex_position_color::vertex_layout;

    std::vector<unsigned short> indices{
        0, 1, 2,
        0, 3, 1
    };

    vertex_buffer vertex_buff(*render_sys, vertices_layout, memory_region(vertices));
    index_buffer index_buff(*render_sys, index_format::ushort, memory_region(indices));

    return app_host.run(
        [&]()
        {
            ctx.clear(color::green());

            ctx.set_vertex_buffer(vertex_buffer_binding(vertex_buff));
            ctx.set_index_buffer(index_buff);

            shader_group.apply(ctx);
            ctx.draw_indexed(primitive_type::triangle_list, 6, 0, 0);

            swap_chain.present();
        });
}
