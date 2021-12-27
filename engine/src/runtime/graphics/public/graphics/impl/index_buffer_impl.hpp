#pragma once

namespace openworld
{
	class render_context;

	class index_buffer_impl :
		public graphics_resource_impl
	{
	public:
		virtual ~index_buffer_impl() = 0 {}

		virtual size_t index_count() const = 0;
		virtual index_format format() const = 0;
		virtual resource_usage usage() const = 0;

		virtual void get_data(
			const std::span<std::byte>& data,
			size_t element_count,
			size_t element_size,
			size_t read_start_offset) = 0;

		virtual void set_data(
			render_context& render_ctx,
			const std::span<const std::byte>& data,
			size_t element_count,
			size_t element_size,
			size_t write_start_offset,
			data_write_options write_opts) = 0;
	};

	class index_buffer_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		virtual ~index_buffer_impl_factory() = 0 {}

		virtual std::unique_ptr<index_buffer_impl> create_impl(
			index_format format,
			size_t index_count,
			resource_usage usage) = 0;

		virtual std::unique_ptr<index_buffer_impl> create_impl(
			index_format format,
			const std::span<const std::byte>& data,
			resource_usage usage) = 0;
	};
}