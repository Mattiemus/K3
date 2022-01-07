#pragma once

namespace openworld
{
	class render_system;

	class graphics_resource_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(graphics_resource_impl);

	public:
		graphics_resource_impl(size_t resource_id, openworld::render_system& render_system) :
			m_resource_id(resource_id), m_render_system(render_system)
		{}

		virtual ~graphics_resource_impl() = 0 {}

		constexpr size_t resource_id() const
		{
			return m_resource_id;
		}

		openworld::render_system& render_system() const
		{
			return m_render_system;
		}

	private:
		size_t m_resource_id;
		openworld::render_system& m_render_system;
	};

	class graphics_resource_impl_factory
	{
	public:
		graphics_resource_impl_factory(openworld::render_system& render_system) :
			m_render_system(render_system)
		{}

		virtual ~graphics_resource_impl_factory() = 0 {}

		openworld::render_system& render_system() const
		{
			return m_render_system;
		}

	private:
		openworld::render_system& m_render_system;
	};
}