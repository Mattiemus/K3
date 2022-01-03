#pragma once

namespace openworld
{
    class shader final
    {
    public:
        shader(shader_language language, shader_stage stage, const std::string& source);
        shader(const shader&) = delete;
        shader(shader&& other) :
            m_pimpl(other.m_pimpl), m_shader_lang(other.m_shader_lang), m_shader_stage(other.m_shader_stage)
        {
            other.m_pimpl = nullptr;
        }
        ~shader();

        shader& operator =(const shader&) = delete;
        shader& operator =(shader&& other)
        {
            m_pimpl = other.m_pimpl;
            m_shader_lang = other.m_shader_lang;
            m_shader_stage = other.m_shader_stage;
            other.m_pimpl = nullptr;
            return *this;
        }

        constexpr void* pimpl() const
        {
            return m_pimpl;
        }

        constexpr shader_language language() const
        {
            return m_shader_lang;
        }

        constexpr shader_stage stage() const
        {
            return m_shader_stage;
        }

    private:
        void* m_pimpl = nullptr;
        shader_language m_shader_lang;
        shader_stage m_shader_stage;
    };
}