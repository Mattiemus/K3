#include "ecs.hpp"

#include "core/engine/engine.hpp"
#include "core/math/float3.hpp"
#include "core/platform/platform_service.hpp"
#include "core/platform/application_host.hpp"
#include "core/platform/window.hpp"
#include "core/platform/win32/win32_platform_service.hpp"
#include "graphics/vertex_structures.hpp"

#include "graphics_gl.hpp"

using namespace openworld;

class test_component1
{
public:
    float3 f;
};

class test_component2
{
public:
    float x;
};

int main()
{
    entity_pool pool;

    entity e1 = pool.create_entity();
    pool.set_component<test_component1>(e1, { float3(1,2,3) });
    pool.set_component<test_component2>(e1, { 1 });

    entity e2 = pool.create_entity();
    pool.set_component<test_component2>(e2, { 5 });
    
    auto m = matcher::all_of<test_component1, test_component2>();

    for (auto it = pool.begin(m); it != pool.end(); ++it)
    {
        auto e = *it;
        int x = 5;
    }

    for (auto it = pool.begin(); it != pool.end(); ++it)
    {
        auto e = *it;
        int x = 5;
    }






    auto hinst = GetModuleHandle(NULL);

    engine::initialize();
    engine::services().make_service<platform_service, win32_platform_service>(hinst);
    engine::services().make_service<render_system, gl_render_system>();

    auto host = std::make_shared<application_host>();
    auto win = host->create_window(true);

    gl_swap_chain swap_chain{ win };

    auto render_sys = engine::services().get_service<render_system>();
    auto& gl_ctx = render_sys->immediate_context();

    gl_shader vertex_shader(
        "#version 400\n"
        "layout(location = 0) in vec3 vertex_position;\n"
        "layout(location = 1) in vec3 vertex_colour;\n"
        "out vec3 colour;\n"
        "void main() {\n"
        "    colour = vertex_colour;\n"
        "    gl_Position = vec4(vertex_position, 1.0);\n"
        "}\n",
        shader_stage::vertex_shader);

    gl_shader frag_shader(
        "#version 400\n"
        "in vec3 colour;\n"
        "out vec4 frag_colour;\n"
        "void main() {\n"
        "  frag_colour = vec4(colour, 1.0);\n"
        "}\n",
        shader_stage::pixel_shader);

    gl_shader_group shader_group({ vertex_shader, frag_shader });

    std::vector<vertex_position_color> vertices{
        { { 0.0f,  0.5f,  0.0f }, { 1.0f, 0.0f,  0.0f } },
        { { 0.5f, -0.5f,  0.0f }, { 0.0f, 1.0f,  0.0f } },
        { { -0.5f, -0.5f,  0.0f }, { 0.0f, 0.0f,  1.0f } },
    };
    const auto& vertices_layout = vertex_position_color::vertex_layout;

    gl_vertex_buffer vertex_buffer;
    vertex_buffer.set_data(
        gl_ctx,
        std::as_bytes(std::span(vertices)),
        vertices.size(),
        sizeof(vertex_position_color),
        0,
        vertices_layout.vertex_stride(),
        data_write_options::none);

    gl_ctx.set_vertex_buffer(vertex_buffer_binding(vertex_buffer));

    return host->run(
        [&]()
        {
            gl_ctx.clear(color::green());

            shader_group.apply(gl_ctx);
            gl_ctx.draw(primitive_type::triangle_list, 3, 0);

            swap_chain.present();
        });
}
