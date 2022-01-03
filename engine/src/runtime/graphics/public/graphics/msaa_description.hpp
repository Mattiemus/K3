#pragma once

namespace openworld
{
    class msaa_description final
    {
    public:
        static const msaa_description default_description;

        size_t count = 1;
        size_t quality_level = 0;
        bool resolve_shader_resource = false;

        constexpr msaa_description(size_t count) :
            count(std::max(1ULL, count)),
            quality_level(0),
            resolve_shader_resource(false)
        {}

        constexpr msaa_description(size_t count, size_t quality_level) :
            count(std::max(1ULL, count)),
            quality_level(quality_level),
            resolve_shader_resource(false)
        {}

        constexpr msaa_description(size_t count, size_t quality_level, bool resolve_shader_resource) :
            count(std::max(1ULL, count)),
            quality_level(quality_level),
            resolve_shader_resource(resolve_shader_resource)
        {}

        static bool check_msaa_configuration(
            graphics_adapter & adapter,
            surface_format format,
            msaa_description & preferred_msaa);

        constexpr bool is_multisampled() const
        {
            return count > 1;
        }
    };
}