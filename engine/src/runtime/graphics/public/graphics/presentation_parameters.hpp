#pragma once

namespace openworld
{
	class presentation_parameters final
	{
	public:
        surface_format back_buffer_format = surface_format::color;
        depth_format depth_stencil_format = depth_format::depth24_stencil8;
        size_t back_buffer_width = 0;
        size_t back_buffer_height = 0;
        size_t multi_sample_count = 0;
        size_t multi_sample_quality = 0;
        bool is_full_screen = false;
        openworld::present_interval present_interval = openworld::present_interval::one;
        openworld::render_target_usage render_target_usage = openworld::render_target_usage::platform_default;
        openworld::display_orientation display_orientation = openworld::display_orientation::_default;

        constexpr presentation_parameters(
            surface_format surface_fmt,
            depth_format depth_fmt,
            size_t width,
            size_t height,
            bool is_full_screen = false) :
            back_buffer_format(surface_fmt),
            depth_stencil_format(depth_fmt),
            back_buffer_width(width),
            back_buffer_height(height),
            is_full_screen(is_full_screen)
        {}

        constexpr int_rectangle bounds() const
        {
            return int_rectangle(0, 0, back_buffer_width, back_buffer_height);
        }
	};
}