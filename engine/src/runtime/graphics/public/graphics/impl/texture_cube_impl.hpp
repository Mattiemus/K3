#pragma once

namespace openworld
{
	class render_context;

	class texture_cube_impl :
		public texture_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(texture_cube_impl);

	public:
		texture_cube_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			size_t size,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage);

		texture_cube_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			size_t size,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage,
			const std::vector<memory_region>& data);

		virtual ~texture_cube_impl() = 0;

		constexpr size_t size() const
		{
			return m_size;
		}

		virtual void get_data(
			const memory_region& data,
			size_t start_index,
			cube_map_face face,
			size_t mip_level,
			const std::optional<resource_region_2d>& subimage) = 0;

		virtual void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			cube_map_face face,
			size_t mip_level,
			const std::optional<resource_region_2d>& subimage,
			data_write_options write_opts) = 0;

	private:
		size_t m_size;
	};

	class texture_cube_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		texture_cube_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~texture_cube_impl_factory() = 0;

		virtual std::unique_ptr<texture_cube_impl> create_impl(
			size_t size,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage) = 0;

		virtual std::unique_ptr<texture_cube_impl> create_impl(
			size_t size,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage,
			const std::vector<memory_region>& data) = 0;
	};
}
