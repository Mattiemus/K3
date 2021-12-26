#include "graphics_gl.hpp"
#include "gl_helpers.hpp"

#include "graphics/render_system.hpp"
#include "graphics/render_context.hpp"

using namespace openworld;

render_system::render_system()
{
    auto* impl = new gl_render_system_impl{};
    m_pimpl = to_pimpl(impl);
}

render_system::~render_system()
{
    auto* impl = from_pimpl<gl_render_system_impl>(m_pimpl);

    delete impl;
    m_pimpl = nullptr;
}

std::string render_system::platform()
{
	return "opengl";
}

render_context& render_system::immediate_context()
{
    auto* impl = from_pimpl<gl_render_system_impl>(m_pimpl);
    return impl->immediate_ctx;
}