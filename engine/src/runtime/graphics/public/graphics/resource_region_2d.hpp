#pragma once

namespace openworld
{
	class resource_region_2d final
	{
	public:
		size_t left = 0;
		size_t right = 0;
		size_t top = 0;
		size_t bottom = 0;

		constexpr resource_region_2d()
		{}

		constexpr resource_region_2d(
			size_t left,
			size_t right,
			size_t top,
			size_t bottom) :
			left(left),
			right(right),
			top(top),
			bottom(bottom)
		{}

		constexpr size_t width() const
		{
			return right - left;
		}

		constexpr size_t height() const
		{
			return bottom - top;
		}

		constexpr size_t element_count() const
		{
			return width() * height();
		}

		void validate_region(size_t& width, size_t& height)
		{
			if (right <= 0 || bottom <= 0)
			{
				throw graphics_exception("Region is invalid");
			}

			if (left > width || right > width || left == right ||
				top > height || bottom > height || top == bottom)
			{
				throw graphics_exception("Region is invalid");
			}

			width = right - left;
			height = bottom - top;
		}
	};
}