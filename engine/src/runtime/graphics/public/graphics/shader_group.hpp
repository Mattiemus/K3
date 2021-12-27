#pragma once

namespace openworld
{
    class render_context;

    class shader_group
    {
    public:
        virtual ~shader_group() = 0 {};

        virtual bool contains_shader(shader_stage stage) = 0;
        virtual void apply(render_context& ctx) = 0;
    };
}