#pragma once

#include "graphics/shader_group.hpp"

namespace openworld
{
    class gl_shader_group final :
        public shader_group
    {
    public:
        gl_shader_group(const std::vector<std::reference_wrapper<shader>>& stages);
        gl_shader_group(const gl_shader_group&) = delete;
        gl_shader_group(gl_shader_group&& other) noexcept;

        virtual ~gl_shader_group();

        GLuint id() const
        {
            return m_program_id;
        }

        virtual bool contains_shader(shader_stage stage) override;
        virtual void apply(render_context& ctx) override;

    private:
        GLuint m_program_id;
    };
}