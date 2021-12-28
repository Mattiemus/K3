#pragma once

namespace openworld
{
	constexpr float ZERO_TOLERANCE = 1E-06f;

	inline bool is_equal(float a, float b, float tolerance = ZERO_TOLERANCE) noexcept
	{
		return std::abs(a - b) <= tolerance;
	}
}