#pragma once

namespace openworld
{
	class render_system;
	class render_context;

	template <>
	class graphics_resource_traits<class texture_1d_array>
	{
	public:
		using impl = texture_1d_array_impl;
		using impl_factory = texture_1d_array_impl_factory;

		static constexpr graphics_resource_type resource_type = graphics_resource_type::texture_1d_array;
	};

	class texture_1d_array final :
		public texture_1d
	{
		OPENWORLD_DELETE_COPY_OPERATORS(texture_1d_array);

	public:
		texture_1d_array(
			openworld::render_system& render_sys,
			size_t width,
			size_t array_count,
			resource_usage usage = resource_usage::static_usage);

		texture_1d_array(
			openworld::render_system& render_sys,
			size_t width,
			size_t array_count,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage = resource_usage::static_usage);

		texture_1d_array(
			openworld::render_system& render_sys,
			size_t width,
			size_t array_count,
			bool gen_mip_maps,
			surface_format format,
			const memory_region& data,
			resource_usage usage = resource_usage::static_usage);

		texture_1d_array(
			openworld::render_system& render_sys,
			size_t width,
			size_t array_count,
			bool gen_mip_maps,
			surface_format format,
			const std::vector<memory_region>& data,
			resource_usage usage = resource_usage::static_usage);

		virtual ~texture_1d_array() {}

		openworld::texture_1d_array_impl& texture_1d_array_impl() const
		{
			return static_cast<openworld::texture_1d_array_impl&>(impl());
		}

		size_t array_count() const
		{
			return texture_1d_array_impl().array_count();
		}

		virtual shader_resource_type resource_type() const override
		{
			return shader_resource_type::texture_1d_array;
		}

		void get_data(
			const memory_region& data,
			size_t start_index,
			size_t array_slice,
			size_t mip_level,
			const std::optional<resource_region_1d>& subimage)
		{
			return texture_1d_array_impl().get_data(
				data,
				start_index,
				array_slice,
				mip_level,
				subimage);
		}

		void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			size_t array_slice,
			size_t mip_level,
			const std::optional<resource_region_1d>& subimage,
			data_write_options write_opts)
		{
			return texture_1d_array_impl().set_data(
				render_ctx,
				data,
				start_index,
				array_slice,
				mip_level,
				subimage,
				write_opts);
		}
	};
}