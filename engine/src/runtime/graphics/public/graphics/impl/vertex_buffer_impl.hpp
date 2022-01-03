#pragma once

namespace openworld
{
	class render_context;

	class vertex_buffer_impl : 
		public graphics_resource_impl
	{
	public:
		vertex_buffer_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			const vertex_layout& layout,
			size_t vertex_count,
			resource_usage usage);

		vertex_buffer_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			const vertex_layout& layout,
			const memory_region& data,
			resource_usage usage);

		vertex_buffer_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			const vertex_layout& layout,
			const std::vector<memory_region>& data,
			resource_usage usage);

		virtual ~vertex_buffer_impl() = 0 {}

		constexpr const vertex_layout& layout() const
		{
			return m_vertex_layout;
		}

		constexpr size_t vertex_count() const
		{
			return m_vertex_count;
		}

		constexpr resource_usage usage() const
		{
			return m_resource_usage;
		}

		virtual void get_interleaved_data(
			const std::vector<memory_region>& data) = 0;

		virtual void set_interleaved_data(
			render_context& render_ctx,
			const std::vector<memory_region>& data) = 0;

		virtual void get_data(
			const memory_region& data,
			size_t start_index,
			size_t element_count,
			size_t buffer_read_start_offset,
			size_t vertex_stride) = 0;

		virtual void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			size_t element_count,
			size_t buffer_write_start_offset,
			size_t vertex_stride,
			data_write_options write_opts) = 0;

	private:
		vertex_layout m_vertex_layout;
		size_t m_vertex_count;
		resource_usage m_resource_usage;
	};

	class vertex_buffer_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		vertex_buffer_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~vertex_buffer_impl_factory() = 0 {}

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			size_t vertex_count,
			resource_usage usage) = 0;

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			const memory_region& data,
			resource_usage usage) = 0;

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			const std::vector<memory_region>& data,
			resource_usage usage) = 0;
	};
}