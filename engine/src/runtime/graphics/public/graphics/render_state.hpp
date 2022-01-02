#pragma once

namespace openworld
{
	class render_state :
		public graphics_resource,
		public standard_library_content
	{
	public:
		virtual ~render_state() = 0 {}

		virtual std::string standard_content_name() override
		{
			return m_predefined_state_name;
		}

		virtual bool is_standard_content() override
		{
			return m_predefined_state_name.empty();
		}

		virtual bool is_bound() const = 0;
		virtual render_state_type state_type() const = 0;
		virtual render_state_key state_key() const = 0;

		virtual void bind_render_state() = 0;

	protected:
		std::string m_predefined_state_name;
	};
}

template<>
struct std::hash<openworld::render_state>
{
	size_t operator()(const openworld::render_state& s) const noexcept
	{
		return s.state_key().hash();
	}
};