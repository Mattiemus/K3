#pragma once

namespace openworld
{
	class render_context;

	class index_buffer_impl :
		public graphics_resource_impl
	{
	public:
		index_buffer_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			index_format format,
			size_t index_count,
			resource_usage usage);

		index_buffer_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			index_format format,
			const memory_region& data,
			resource_usage usage);

		virtual ~index_buffer_impl() = 0 {}

		constexpr size_t index_count() const
		{
			return m_index_count;
		}

		constexpr index_format format() const
		{
			return m_index_format;
		}

		constexpr resource_usage usage() const
		{
			return m_usage;
		}

		virtual void get_data(
			const memory_region& data,
			size_t start_index,
			size_t element_count,
			size_t buffer_read_start_offset) = 0;

		virtual void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			size_t element_count,
			size_t buffer_write_start_offset,
			data_write_options write_opts) = 0;

	private:
		size_t m_index_count;
		index_format m_index_format;
		resource_usage m_usage;
	};

	class index_buffer_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		index_buffer_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~index_buffer_impl_factory() = 0 {}

		virtual std::unique_ptr<index_buffer_impl> create_impl(
			index_format format,
			size_t index_count,
			resource_usage usage) = 0;

		virtual std::unique_ptr<index_buffer_impl> create_impl(
			index_format format,
			const memory_region& data,
			resource_usage usage) = 0;
	};
}
