#pragma once

namespace openworld
{
	class render_context;

	class render_state_impl :
		public graphics_resource_impl
	{
	public:
		render_state_impl(size_t resource_id, openworld::render_system& render_system) :
			graphics_resource_impl(resource_id, render_system)
		{}

		virtual ~render_state_impl() = 0 {}

		constexpr bool is_bound() const noexcept
		{
			return m_is_bound;
		}

		void bind_state()
		{
			if (!m_is_bound)
			{
				create_native_state();
				m_is_bound = true;
			}
		}

	protected:
		virtual void create_native_state() = 0;

		void throw_if_bound() const
		{
			if (m_is_bound)
			{
				throw graphics_exception("Render state has been bound");
			}
		}

	private:
		bool m_is_bound = false;
	};
}
