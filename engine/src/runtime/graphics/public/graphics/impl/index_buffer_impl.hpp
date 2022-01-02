#pragma once

namespace openworld
{
	class render_context;

	class index_buffer_impl :
		public graphics_resource_impl
	{
	public:
		index_buffer_impl(size_t resource_id, openworld::render_system& render_system) :
			graphics_resource_impl(resource_id, render_system)
		{}

		virtual ~index_buffer_impl() = 0 {}

		virtual size_t index_count() const = 0;
		virtual index_format format() const = 0;
		virtual resource_usage usage() const = 0;

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
