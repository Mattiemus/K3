#include "graphics_gl.hpp"
#include "gl_helpers.hpp"

using namespace openworld;

gl_shader::gl_shader(const std::string& source, shader_stage stage) :
    m_shader_id(0),
    m_shader_stage(stage)
{
    auto shader_type = to_gl_enum(stage);
    m_shader_id = glCreateShader(shader_type);

    auto source_buffer = source.c_str();
    auto source_size = static_cast<int>(source.size());

    glShaderSource(m_shader_id, 1, &source_buffer, &source_size);
    glCompileShader(m_shader_id);

    auto success = GL_FALSE;
    glGetShaderiv(m_shader_id, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        auto error_log_size = 0;
        glGetShaderiv(m_shader_id, GL_INFO_LOG_LENGTH, &error_log_size);

        std::vector<char> error_log_buffer(error_log_size);
        glGetShaderInfoLog(m_shader_id, error_log_size, &error_log_size, error_log_buffer.data());

        glDeleteShader(m_shader_id);
        throw gl_shader_compile_error(error_log_buffer.data());
    }
}

gl_shader::gl_shader(gl_shader&& other) noexcept :
    m_shader_id(other.m_shader_id),
    m_shader_stage(other.m_shader_stage)
{
    other.m_shader_id = 0;
}

gl_shader::~gl_shader()
{
    glDeleteShader(m_shader_id);
}