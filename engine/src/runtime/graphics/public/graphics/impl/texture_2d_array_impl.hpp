#pragma once

namespace openworld
{
	class render_context;

	class texture_2d_array_impl :
		public texture_2d_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(texture_2d_array_impl);

	public:
		texture_2d_array_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			size_t width,
			size_t height,
			size_t array_count,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage);

		texture_2d_array_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			size_t width,
			size_t height,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage,
			const std::vector<memory_region>& data);

		virtual ~texture_2d_array_impl() = 0;

		constexpr size_t array_count() const
		{
			return m_array_count;
		}
		
		using texture_2d_impl::get_data;
		using texture_2d_impl::set_data;

		virtual void get_data(
			const memory_region& data,
			size_t start_index,
			size_t array_slice,
			size_t mip_level,
			const std::optional<resource_region_2d>& subimage) = 0;

		virtual void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			size_t array_slice,
			size_t mip_level,
			const std::optional<resource_region_2d>& subimage,
			data_write_options write_opts) = 0;

		virtual shader_resource& get_sub_texture(size_t array_index) = 0;

	private:
		size_t m_array_count;
	};

	class texture_2d_array_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		texture_2d_array_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~texture_2d_array_impl_factory() = 0;

		virtual std::unique_ptr<texture_2d_array_impl> create_impl(
			size_t width,
			size_t height,
			size_t array_count,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage) = 0;

		virtual std::unique_ptr<texture_2d_array_impl> create_impl(
			size_t width,
			size_t height,
			size_t array_count,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage,
			const std::vector<memory_region>& data) = 0;
	};
}
