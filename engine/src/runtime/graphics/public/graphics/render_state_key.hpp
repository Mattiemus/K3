#pragma once

namespace openworld
{
	class render_state_key final
	{
	public:
		constexpr render_state_key() noexcept = default;
		constexpr render_state_key(render_state_type state_type, size_t hash) noexcept :
			m_state_type(state_type),
			m_hash(hash)
		{}

		constexpr render_state_type state_type() const noexcept
		{
			return m_state_type;
		}

		constexpr size_t hash() const noexcept
		{
			return m_hash;
		}

	private:
		render_state_type m_state_type = render_state_type::blend_state;
		size_t m_hash = 0;
	};

	constexpr bool operator ==(const render_state_key& lhs, const render_state_key& rhs) noexcept
	{
		return (lhs.state_type() == rhs.state_type()) && (lhs.hash() == rhs.hash());
	}

	constexpr bool operator !=(const render_state_key& lhs, const render_state_key& rhs) noexcept
	{
		return (lhs.state_type() != rhs.state_type()) || (lhs.hash() != rhs.hash());
	}
}