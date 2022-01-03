#pragma once

namespace openworld
{
	class resource_region_1d final
	{
	public:
		size_t left = 0;
		size_t right = 0;

		constexpr resource_region_1d()
		{}

		constexpr resource_region_1d(
			size_t left,
			size_t right) :
			left(left),
			right(right)
		{}

		constexpr size_t width() const
		{
			return right - left;
		}

		constexpr size_t element_count() const
		{
			return width();
		}

		void validate_region(size_t& width) const
		{
			if (right <= 0)
			{
				throw graphics_exception("Region is invalid");
			}

			if (left > width || right > width || left == right)
			{
				throw graphics_exception("Region is invalid");
			}

			width = right - left;
		}
	};
}