#pragma once

namespace openworld
{
    class gl_shader_compile_error final :
        public std::runtime_error
    {
    public:
        gl_shader_compile_error(const std::string& error) :
            std::runtime_error(error)
        {
        }
    };

    class gl_shader_link_error final :
        public std::runtime_error
    {
    public:
        gl_shader_link_error(const std::string& error) :
            std::runtime_error(error)
        {
        }
    };

    class gl_shader_validate_error final :
        public std::runtime_error
    {
    public:
        gl_shader_validate_error(const std::string& error) :
            std::runtime_error(error)
        {
        }
    };
}