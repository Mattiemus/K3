#pragma once

namespace openworld
{
	class display_mode final
	{
	public:
		constexpr display_mode(
			size_t width,
			size_t height,
			float refresh_rate,
			surface_format format) :
			m_width(width),
			m_height(height),
			m_refresh_rate(refresh_rate),
			m_format(format)
		{}

		constexpr size_t width() const
		{
			return m_width;
		}

		constexpr size_t height() const
		{
			return m_height;
		}

		constexpr float aspect_ratio() const
		{
			if (m_width != 0 && m_height != 0)
			{
				return static_cast<float>(m_width) / static_cast<float>(m_height);
			}

			return 0.0f;
		}

		constexpr float refresh_rate() const
		{
			return m_refresh_rate;
		}

		constexpr surface_format format() const
		{
			return m_format;
		}

	private:
		size_t m_width;
		size_t m_height;
		float m_refresh_rate;
		surface_format m_format;
	};

	constexpr bool operator ==(const display_mode& lhs, const display_mode& rhs)
	{
		return (lhs.width() == rhs.width()) && 
			(lhs.height() == rhs.height()) && 
			is_equal(lhs.refresh_rate(), rhs.refresh_rate()) && 
			(lhs.format() == rhs.format());
	}

	constexpr bool operator !=(const display_mode& lhs, const display_mode& rhs)
	{
		return (lhs.width() != rhs.width()) ||
			(lhs.height() != rhs.height()) ||
			!is_equal(lhs.refresh_rate(), rhs.refresh_rate()) ||
			(lhs.format() != rhs.format());
	}
}