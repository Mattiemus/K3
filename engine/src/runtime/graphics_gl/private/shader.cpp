#include "graphics_gl.hpp"
#include "gl_helpers.hpp"

using namespace openworld;

shader::shader(shader_language language, shader_stage stage, const std::string& source) :
    m_shader_lang(language), m_shader_stage(stage)
{
    auto shader_type = to_gl_enum(stage);

    auto shader_id = glCreateShader(shader_type);
    m_pimpl = to_pimpl(shader_id);

    auto source_buffer = source.c_str();
    auto source_size = static_cast<GLint>(source.size());

    glShaderSource(shader_id, 1, &source_buffer, &source_size);
    glCompileShader(shader_id);

    auto success = GL_FALSE;
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);

    if (success == GL_FALSE)
    {
        auto error_log_size = 0;
        glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &error_log_size);

        std::vector<char> error_log_buffer(error_log_size);
        glGetShaderInfoLog(shader_id, error_log_size, &error_log_size, error_log_buffer.data());

        glDeleteShader(shader_id);

        throw gl_shader_compile_error(error_log_buffer.data());
    }
}

shader::~shader()
{
    auto shader_id = from_pimpl(m_pimpl);
    glDeleteShader(shader_id);
}