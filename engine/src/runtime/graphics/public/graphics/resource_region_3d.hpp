#pragma once

namespace openworld
{
	class resource_region_3d final
	{
	public:
		size_t left = 0;
		size_t right = 0;
		size_t top = 0;
		size_t bottom = 0;
		size_t front = 0;
		size_t back = 0;

		constexpr resource_region_3d()
		{}

		constexpr resource_region_3d(
			size_t left,
			size_t right,
			size_t top,
			size_t bottom,
			size_t front,
			size_t back) :
			left(left),
			right(right),
			top(top),
			bottom(bottom),
			front(front),
			back(back)
		{}

		constexpr size_t width() const
		{
			return right - left;
		}

		constexpr size_t height() const
		{
			return bottom - top;
		}

		constexpr size_t depth() const
		{
			return back - front;
		}

		constexpr size_t element_count() const
		{
			return width() * height() * depth();
		}

		void validate_region(size_t& width, size_t& height, size_t& depth)
		{
			if (right <= 0 || bottom <= 0 || back <= 0)
			{
				throw graphics_exception("Region is invalid");
			}

			if (left > width || right > width || left == right ||
				top > height || bottom > height || top == bottom ||
				front > depth || back > depth || front == back)
			{
				throw graphics_exception("Region is invalid");
			}

			width = right - left;
			height = bottom - top;
			depth = back - front;
		}
	};
}