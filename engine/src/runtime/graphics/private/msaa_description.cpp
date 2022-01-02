#include "graphics.hpp"

using namespace openworld;

const msaa_description msaa_description::default_description = msaa_description(1, 0, false);

bool msaa_description::check_msaa_configuration(
    graphics_adapter& adapter,
    surface_format format,
    msaa_description& preferred_msaa)
{
    if (preferred_msaa.resolve_shader_resource && !adapter.is_multisample_resolvable(format))
    {
        preferred_msaa.resolve_shader_resource = false;
    }

    auto max_quality_levels = adapter.check_multisample_quality_levels(format, preferred_msaa.count);

    if (max_quality_levels == 0)
    {
        auto count = std::max(1ULL, preferred_msaa.count);
        auto quality = preferred_msaa.quality_level;

        preferred_msaa.count = 1;
        preferred_msaa.quality_level = 0;

        while (count > 1)
        {
            count--;
            max_quality_levels = adapter.check_multisample_quality_levels(format, count);

            if (quality > 0)
            {
                preferred_msaa.count = count;
                preferred_msaa.quality_level = std::clamp(quality, 0ULL, max_quality_levels - 1);
                break;
            }
        }
    }
    else
    {
        preferred_msaa.quality_level = std::clamp(preferred_msaa.quality_level, 0ULL, max_quality_levels - 1);
    }

    return true;
}