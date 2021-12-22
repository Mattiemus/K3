#include "graphics_gl.hpp"

using namespace openworld;

gl_shader_group::gl_shader_group(const std::vector<std::reference_wrapper<gl_shader>>& stages) :
    m_program_id(0)
{
    m_program_id = glCreateProgram();

    for (const auto& stage : stages)
    {
        glAttachShader(m_program_id, stage.get().id());
    }

    glLinkProgram(m_program_id);

    for (const auto& stage : stages)
    {
        glDetachShader(m_program_id, stage.get().id());
    }

    auto success = GL_FALSE;
    glGetProgramiv(m_program_id, GL_LINK_STATUS, &success);

    if (success == GL_FALSE)
    {
        auto error_log_size = 0;
        glGetProgramiv(m_program_id, GL_INFO_LOG_LENGTH, &error_log_size);

        std::vector<char> error_log_buffer(error_log_size);
        glGetProgramInfoLog(m_program_id, error_log_size, &error_log_size, error_log_buffer.data());

        glDeleteShader(m_program_id);
        throw gl_shader_link_error(error_log_buffer.data());
    }

    glValidateProgram(m_program_id);

    auto validation_success = GL_FALSE;
    glGetProgramiv(m_program_id, GL_VALIDATE_STATUS, &validation_success);

    if (validation_success == GL_FALSE)
    {
        glDeleteShader(m_program_id);
        throw gl_shader_validate_error("Could not validate shader program");
    }
}

gl_shader_group::gl_shader_group(gl_shader_group&& other) noexcept :
    m_program_id(other.m_program_id)
{
    other.m_program_id = 0;
}

gl_shader_group::~gl_shader_group()
{
    glDeleteProgram(m_program_id);
}

bool gl_shader_group::contains_shader(shader_stage stage)
{
    // TODO
    return false;
}

void gl_shader_group::apply(render_context& ctx)
{
    // TODO: Ensure ctx is gl_render_context
    glUseProgram(m_program_id);
}