#pragma once

namespace openworld
{
    class half final
    {
    public:
        unsigned short packed_value = 0;

        constexpr half()
        {}

        constexpr half(unsigned short value) :
            packed_value(value)
        {}
    };

    static_assert(sizeof(half) == (sizeof(unsigned short)));

    constexpr bool operator ==(const half& lhs, const half& rhs)
    {
        return (lhs.packed_value == rhs.packed_value);
    }

    constexpr bool operator !=(const half& lhs, const half& rhs)
    {
        return (lhs.packed_value != rhs.packed_value);
    }
}