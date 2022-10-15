#pragma once

namespace openworld
{
	class render_context;

	class texture_3d_impl :
		public texture_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(texture_3d_impl);

	public:
		texture_3d_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			size_t width,
			size_t height,
			size_t depth,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage);

		texture_3d_impl(
			size_t resource_id,
			openworld::render_system& render_system,
			size_t width,
			size_t height,
			size_t depth,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage,
			const std::vector<memory_region>& data);

		virtual ~texture_3d_impl() = 0;

		constexpr size_t width() const
		{
			return m_width;
		}

		constexpr size_t height() const
		{
			return m_height;
		}

		constexpr size_t depth() const
		{
			return m_depth;
		}

		virtual void get_data(
			const memory_region& data,
			size_t start_index,
			size_t mip_level,
			const std::optional<resource_region_3d>& subimage) = 0;

		virtual void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			size_t mip_level,
			const std::optional<resource_region_3d>& subimage,
			data_write_options write_opts) = 0;

	private:
		size_t m_width;
		size_t m_height;
		size_t m_depth;
	};

	class texture_3d_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		texture_3d_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~texture_3d_impl_factory() = 0;

		virtual std::unique_ptr<texture_3d_impl> create_impl(
			size_t width,
			size_t height,
			size_t depth,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage) = 0;

		virtual std::unique_ptr<texture_3d_impl> create_impl(
			size_t width,
			size_t height,
			size_t depth,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage,
			const std::vector<memory_region>& data) = 0;
	};
}
