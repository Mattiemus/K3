#pragma once

#include <cstdint>

#include "core/math/float4.hpp"

namespace openworld
{
    class color final
    {
    public:
        union {
            struct {
                uint8_t r;
                uint8_t g;
                uint8_t b;
                uint8_t a;
            };
            uint32_t packed;
        };

        constexpr color() :
            packed(0)
        {}

        constexpr color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
            r(r),
            g(g),
            b(b),
            a(a)
        {}


        static constexpr color black()
        {
            return color(static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
        }

        static constexpr color white()
        {
            return color(static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255));
        }

        static constexpr color red()
        {
            return color(static_cast<uint8_t>(255), static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
        }

        static constexpr color green()
        {
            return color(static_cast<uint8_t>(0), static_cast<uint8_t>(255), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
        }

        static constexpr color blue()
        {
            return color(static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255), static_cast<uint8_t>(255));
        }
    };

    static_assert(sizeof(color) == sizeof(uint32_t));

    constexpr float4 to_vector4(const color& c)
    {
        return float4(c.r / 255.0f, c.g / 255.0f, c.b / 255.0f, c.a / 255.0f);
    }
}