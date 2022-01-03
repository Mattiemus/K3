#pragma once

namespace openworld
{
    class color final
    {
    public:
        static const color transparent_black;
        static const color black;
        static const color white;
        static const color red;
        static const color green;
        static const color blue;

        union {
            struct {
                uint8_t r;
                uint8_t g;
                uint8_t b;
                uint8_t a;
            };
            uint32_t packed_value = 0;
        };

        constexpr color()
        {}

        constexpr color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) :
            r(r),
            g(g),
            b(b),
            a(a)
        {}
    };

    static_assert(sizeof(color) == sizeof(uint32_t));

    constexpr bool operator ==(const color& lhs, const color& rhs)
    {
        return lhs.packed_value == rhs.packed_value;
    }

    constexpr bool operator !=(const color& lhs, const color& rhs)
    {
        return lhs.packed_value != rhs.packed_value;
    }
}

OPENWORLD_DEFINE_STD_HASH(::openworld::color, x.packed_value)