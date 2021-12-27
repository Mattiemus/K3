#pragma once

namespace openworld
{
	class render_context;

	class vertex_buffer_impl : 
		public graphics_resource_impl
	{
	public:
		virtual ~vertex_buffer_impl() = 0 {}

		virtual const vertex_layout& layout() const = 0;
		virtual size_t vertex_count() const = 0;
		virtual resource_usage usage() const = 0;

		virtual void get_interleaved_data(
			const std::span<const std::span<std::byte>>& data) = 0;

		virtual void set_interleaved_data(
			render_context& render_ctx,
			const std::span<const std::span<const std::byte>>& data) = 0;

		virtual void get_data(
			const std::span<std::byte>& data,
			size_t element_count,
			size_t element_size,
			size_t read_start_offset,
			size_t vertex_stride) = 0;

		virtual void set_data(
			render_context& render_ctx,
			const std::span<const std::byte>& data,
			size_t element_count,
			size_t element_size,
			size_t write_start_offset,
			size_t vertex_stride,
			data_write_options write_opts) = 0;
	};

	class vertex_buffer_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		virtual ~vertex_buffer_impl_factory() = 0 {}

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			size_t vertex_count,
			resource_usage usage) = 0;

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			const std::span<const std::byte>& data,
			resource_usage usage) = 0;

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			const std::span<const std::span<const std::byte>>& data,
			resource_usage usage) = 0;
	};
}