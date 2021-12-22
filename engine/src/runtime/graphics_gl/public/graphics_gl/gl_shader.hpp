#pragma once

#include "graphics/enums.hpp"

namespace openworld
{
    class gl_shader final
    {
    public:
        gl_shader(const std::string& source, shader_stage stage);
        gl_shader(const gl_shader&) = delete;
        gl_shader(gl_shader&& other) noexcept;

        ~gl_shader();

        GLuint id() const
        {
            return m_shader_id;
        }

        shader_stage stage() const
        {
            return m_shader_stage;
        }

    private:
        GLuint m_shader_id;
        shader_stage m_shader_stage;
    };
}