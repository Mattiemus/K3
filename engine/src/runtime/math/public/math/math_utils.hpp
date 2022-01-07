#pragma once

namespace openworld
{
	constexpr float ZERO_TOLERANCE = 1E-06f;

	inline bool is_equal(float a, float b, float tolerance = ZERO_TOLERANCE)
	{
		return std::abs(a - b) <= tolerance;
	}

    constexpr bool is_power_of_two(size_t num)
    {
        return (num != 0) && ((num & (num - 1)) == 0);
    }

    constexpr size_t next_power_of_two(size_t v)
    {
        size_t p = 1;
        while (v > p)
        {
            p += p;
        }

        return p;
    }

    constexpr size_t previous_power_of_two(size_t v)
    {
        return next_power_of_two(v + 1) / 2;
    }

    constexpr size_t nearest_power_of_two(size_t v)
    {
        auto np2 = next_power_of_two(v);
        auto pp2 = previous_power_of_two(v);

        if (np2 - v <= v - pp2)
        {
            return np2;
        }

        return pp2;
    }
}