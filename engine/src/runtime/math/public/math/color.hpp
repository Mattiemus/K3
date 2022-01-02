#pragma once

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
            uint32_t packed_value = 0;
        };

        constexpr color() noexcept
        {}

        constexpr color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) noexcept :
            r(r),
            g(g),
            b(b),
            a(a)
        {}

        static constexpr color transparent_black() noexcept
        {
            return color(static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(0));
        }

        static constexpr color black() noexcept
        {
            return color(static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
        }

        static constexpr color white() noexcept
        {
            return color(static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255), static_cast<uint8_t>(255));
        }

        static constexpr color red() noexcept
        {
            return color(static_cast<uint8_t>(255), static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
        }

        static constexpr color green() noexcept
        {
            return color(static_cast<uint8_t>(0), static_cast<uint8_t>(255), static_cast<uint8_t>(0), static_cast<uint8_t>(255));
        }

        static constexpr color blue() noexcept
        {
            return color(static_cast<uint8_t>(0), static_cast<uint8_t>(0), static_cast<uint8_t>(255), static_cast<uint8_t>(255));
        }
    };

    static_assert(sizeof(color) == sizeof(uint32_t));

    constexpr bool operator ==(const color& lhs, const color& rhs) noexcept
    {
        return lhs.packed_value == rhs.packed_value;
    }

    constexpr bool operator !=(const color& lhs, const color& rhs) noexcept
    {
        return lhs.packed_value != rhs.packed_value;
    }
}

OPENWORLD_DEFINE_STD_HASH(::openworld::color, x.packed_value)