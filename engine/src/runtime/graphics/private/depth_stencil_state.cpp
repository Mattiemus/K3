#include "graphics.hpp"

using namespace openworld;

depth_stencil_state::depth_stencil_state(openworld::render_system& render_sys)
{
    m_impl = render_sys.make_impl<depth_stencil_state>();
    set_defaults();
}

void depth_stencil_state::set_defaults()
{
    m_impl->depth_enable(true);
    m_impl->depth_write_enable(true);
    m_impl->depth_function(comparison_function::less_equal);
    m_impl->stencil_enable(false);
    m_impl->reference_stencil(0);
    m_impl->back_face_stencil_function(comparison_function::always);
    m_impl->back_face_stencil_depth_fail(stencil_operation::keep);
    m_impl->back_face_stencil_fail(stencil_operation::keep);
    m_impl->back_face_stencil_pass(stencil_operation::keep);
    m_impl->stencil_function(comparison_function::always);
    m_impl->stencil_depth_fail(stencil_operation::keep);
    m_impl->stencil_fail(stencil_operation::keep);
    m_impl->stencil_pass(stencil_operation::keep);
    m_impl->two_sided_stencil_enable(false);
    m_impl->stencil_read_mask(std::numeric_limits<size_t>::max());
    m_impl->stencil_write_mask(std::numeric_limits<size_t>::max());
}

render_state_key depth_stencil_state::compute_render_state_key() const
{
    std::hash<depth_stencil_state> hasher{};

    auto hash = hasher(*this);
    return { render_state_type::depth_stencil_state, hash };
}