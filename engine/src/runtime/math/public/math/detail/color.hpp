#pragma once

namespace openworld
{
    constexpr float4 to_vector4(const color& c) noexcept
    {
        return float4(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
    }
}