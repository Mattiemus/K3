#pragma once

namespace openworld
{
	class int_rectangle final
	{
	public:
		int x = 0;
		int y = 0;
		size_t width = 0;
		size_t height = 0;

		constexpr int_rectangle() noexcept
		{}

		constexpr int_rectangle(int x, int y, size_t width, size_t height) noexcept :
			x(x),
			y(y),
			width(width),
			height(height)
		{}

		constexpr int_rectangle(const int2 & top_left, size_t width, size_t height) noexcept :
			x(top_left.x),
			y(top_left.y),
			width(width),
			height(height)
		{}

		constexpr int_rectangle(const int2& top_left, const int2& width_height) noexcept :
			x(top_left.x),
			y(top_left.y),
			width(width_height.x),
			height(width_height.y)
		{}
	};
}