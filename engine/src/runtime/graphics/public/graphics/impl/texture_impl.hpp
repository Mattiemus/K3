#pragma once

namespace openworld
{
	class render_context;

	class texture_impl :
		public graphics_resource_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(texture_impl);

	public:
		texture_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			surface_format format,
			resource_usage usage) :
			graphics_resource_impl(resource_id, render_system),
			m_mip_count(0),
			m_format(format),
			m_resource_usage(usage)
		{}

		virtual ~texture_impl() = 0;

		constexpr size_t mip_count() const
		{
			return m_mip_count;
		}

		constexpr surface_format format() const
		{
			return m_format;
		}

		constexpr resource_usage usage() const
		{
			return m_resource_usage;
		}

	protected:
		size_t m_mip_count;
		surface_format m_format;
		resource_usage m_resource_usage;
	};
}
