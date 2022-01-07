#pragma once

namespace openworld
{
	class render_system;
	class render_context;

	template <>
	class graphics_resource_traits<class texture_1d>
	{
	public:
		using impl = texture_1d_impl;
		using impl_factory = texture_1d_impl_factory;

		static constexpr graphics_resource_type resource_type = graphics_resource_type::texture_1d;
	};

	class texture_1d :
		public texture
	{
		OPENWORLD_DELETE_COPY_OPERATORS(texture_1d);

	public:
		texture_1d(
			openworld::render_system& render_sys,
			size_t width,
			resource_usage usage = resource_usage::static_usage);

		texture_1d(
			openworld::render_system& render_sys,
			size_t width,
			bool gen_mip_maps,
			surface_format format,
			resource_usage usage = resource_usage::static_usage);

		texture_1d(
			openworld::render_system& render_sys,
			size_t width,
			bool gen_mip_maps,
			surface_format format,
			const memory_region& data,
			resource_usage usage = resource_usage::static_usage);

		texture_1d(
			openworld::render_system& render_sys,
			size_t width,
			bool gen_mip_maps,
			surface_format format,
			const std::vector<memory_region>& data,
			resource_usage usage = resource_usage::static_usage);

		virtual ~texture_1d() {}

		openworld::texture_1d_impl& texture_1d_impl() const
		{
			return static_cast<openworld::texture_1d_impl&>(impl());
		}

		virtual size_t mip_count() const override
		{
			return texture_1d_impl().mip_count();
		}

		size_t width() const
		{
			return texture_1d_impl().width();
		}

		virtual surface_format format() const override
		{
			return texture_1d_impl().format();
		}

		virtual resource_usage usage() const override
		{
			return texture_1d_impl().usage();
		}

		virtual texture_dimension dimension() const override
		{
			return texture_dimension::one;
		}

		virtual shader_resource_type resource_type() const override
		{
			return shader_resource_type::texture_1d;
		}

		void get_data(
			const memory_region& data,
			size_t start_index,
			size_t mip_level,
			const std::optional<resource_region_1d>& subimage)
		{
			return texture_1d_impl().get_data(
				data,
				start_index,
				mip_level,
				subimage);
		}

		void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			size_t mip_level,
			const std::optional<resource_region_1d>& subimage,
			data_write_options write_opts)
		{
			return texture_1d_impl().set_data(
				render_ctx,
				data,
				start_index,
				mip_level,
				subimage,
				write_opts);
		}

	protected:
		texture_1d() {}
	};
}