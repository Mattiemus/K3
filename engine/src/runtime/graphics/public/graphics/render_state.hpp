#pragma once

namespace openworld
{
	class render_state :
		public graphics_resource,
		public standard_library_content
	{
		OPENWORLD_DELETE_COPY_OPERATORS(render_state);

	public:
		render_state() {}
		virtual ~render_state() = 0 {}

		openworld::render_state_impl& render_state_impl() const
		{
			return static_cast<openworld::render_state_impl&>(impl());
		}

		virtual std::string standard_content_name() override
		{
			return m_predefined_state_name;
		}

		virtual bool is_standard_content() override
		{
			return m_predefined_state_name.empty();
		}

		bool is_bound() const
		{
			return render_state_impl().is_bound();
		}

		virtual render_state_type state_type() const = 0;

		render_state_key state_key() const
		{
			if (!is_bound())
			{
				return compute_render_state_key();
			}

			return m_key;
		}

		virtual void set_defaults() = 0;

		void bind_render_state()
		{
			if (!is_bound())
			{
				render_state_impl().bind_render_state();
				m_key = compute_render_state_key();
			}
		}

	protected:
		std::string m_predefined_state_name;
		render_state_key m_key;

		virtual render_state_key compute_render_state_key() const = 0;
	};
}

template<>
struct std::hash<openworld::render_state>
{
	size_t operator()(const openworld::render_state& s) const
	{
		return s.state_key().hash();
	}
};