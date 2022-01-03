#pragma once

namespace openworld
{
	class render_context;

	class sampler_state_impl :
		public render_state_impl
	{
	public:
		sampler_state_impl(size_t resource_id, openworld::render_system& render_system) :
			render_state_impl(resource_id, render_system)
		{}

		virtual ~sampler_state_impl() = 0 {}

		virtual size_t supported_anisotropy_levels() const = 0;

		constexpr texture_address_mode address_u() const
		{
			return m_address_u;
		}

		void address_u(texture_address_mode mode)
		{
			throw_if_bound();
			m_address_u = mode;
		}

		constexpr texture_address_mode address_v() const
		{
			return m_address_v;
		}

		void address_v(texture_address_mode mode)
		{
			throw_if_bound();
			m_address_v = mode;
		}

		constexpr texture_address_mode address_w() const
		{
			return m_address_w;
		}

		void address_w(texture_address_mode mode)
		{
			throw_if_bound();
			m_address_w = mode;
		}

		constexpr texture_filter filter() const
		{
			return m_filter;
		}

		void filter(texture_filter f)
		{
			throw_if_bound();
			m_filter = f;
		}

		constexpr size_t max_anisotropy() const
		{
			return m_max_anisotropy;
		}

		void max_anisotropy(size_t x)
		{
			throw_if_bound();
			m_max_anisotropy = std::clamp(x, 1ULL, supported_anisotropy_levels());
		}

		constexpr float mip_map_level_of_detail_bias() const
		{
			return m_mip_map_level_of_detail_bias;
		}

		void mip_map_level_of_detail_bias(float bias)
		{
			throw_if_bound();
			m_mip_map_level_of_detail_bias = bias;
		}

		constexpr size_t min_mip_map_level() const
		{
			return m_min_mip_map_level;
		}

		void min_mip_map_level(size_t level)
		{
			throw_if_bound();
			m_min_mip_map_level = level;
		}

		constexpr size_t max_mip_map_level() const
		{
			return m_max_mip_map_level;
		}

		void max_mip_map_level(size_t level)
		{
			throw_if_bound();
			m_max_mip_map_level = level;
		}

		constexpr color border_color() const
		{
			return m_border_color;
		}

		void border_color(const color& c)
		{
			throw_if_bound();
			m_border_color = c;
		}

		constexpr comparison_function compare_function() const
		{
			return m_compare_function;
		}

		void compare_function(comparison_function fn)
		{
			throw_if_bound();
			m_compare_function = fn;
		}

		virtual bool is_addressing_mode_supported(texture_address_mode mode) = 0;

	private:
		texture_address_mode m_address_u = texture_address_mode::wrap;
		texture_address_mode m_address_v = texture_address_mode::wrap;
		texture_address_mode m_address_w = texture_address_mode::wrap;
		texture_filter m_filter = texture_filter::point;
		size_t m_max_anisotropy = 0;
		float m_mip_map_level_of_detail_bias = 0.0f;
		size_t m_min_mip_map_level = 0;
		size_t m_max_mip_map_level = 0;
		color m_border_color = color::transparent_black;
		comparison_function m_compare_function = comparison_function::always;
	};

	class sampler_state_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		sampler_state_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~sampler_state_impl_factory() = 0 {}

		virtual std::unique_ptr<sampler_state_impl> create_impl() = 0;
	};
}
