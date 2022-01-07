#pragma once

namespace openworld
{
	class render_system;
	class render_context;

	template <>
	class graphics_resource_traits<class sampler_state>
	{
	public:
		using impl = sampler_state_impl;
		using impl_factory = sampler_state_impl_factory;

		static constexpr graphics_resource_type resource_type = graphics_resource_type::sampler_state;
	};

	class sampler_state final :
		public render_state,
		public shader_resource
	{
		OPENWORLD_DELETE_COPY_OPERATORS(sampler_state);

	public:
		sampler_state(openworld::render_system& render_sys);
		virtual ~sampler_state() {}

		openworld::sampler_state_impl& sampler_state_impl() const
		{
			return static_cast<openworld::sampler_state_impl&>(impl());
		}

		virtual shader_resource_type resource_type()
		{
			return shader_resource_type::sampler_state;
		}

		virtual render_state_type state_type() const override
		{
			return render_state_type::sampler_state;
		}

		size_t supported_anisotropy_levels() const
		{
			return sampler_state_impl().supported_anisotropy_levels();
		}

		constexpr texture_address_mode address_u() const
		{
			return sampler_state_impl().address_u();
		}

		void address_u(texture_address_mode mode)
		{
			sampler_state_impl().address_u(mode);
		}

		constexpr texture_address_mode address_v() const
		{
			return sampler_state_impl().address_v();
		}

		void address_v(texture_address_mode mode)
		{
			sampler_state_impl().address_v(mode);
		}

		constexpr texture_address_mode address_w() const
		{
			return sampler_state_impl().address_w();
		}

		void address_w(texture_address_mode mode)
		{
			sampler_state_impl().address_w(mode);
		}

		constexpr texture_filter filter() const
		{
			return sampler_state_impl().filter();
		}

		void filter(texture_filter f)
		{
			sampler_state_impl().filter(f);
		}

		constexpr size_t max_anisotropy() const
		{
			return sampler_state_impl().max_anisotropy();
		}

		void max_anisotropy(size_t x)
		{
			sampler_state_impl().max_anisotropy(x);
		}

		constexpr float mip_map_level_of_detail_bias() const
		{
			return sampler_state_impl().mip_map_level_of_detail_bias();
		}

		void mip_map_level_of_detail_bias(float bias)
		{
			sampler_state_impl().mip_map_level_of_detail_bias(bias);
		}

		constexpr size_t min_mip_map_level() const
		{
			return sampler_state_impl().min_mip_map_level();
		}

		void min_mip_map_level(size_t level)
		{
			sampler_state_impl().min_mip_map_level(level);
		}

		constexpr size_t max_mip_map_level() const
		{
			return sampler_state_impl().max_mip_map_level();
		}

		void max_mip_map_level(size_t level)
		{
			sampler_state_impl().max_mip_map_level(level);
		}

		constexpr color border_color() const
		{
			return sampler_state_impl().border_color();
		}

		void border_color(const color& c)
		{
			sampler_state_impl().border_color(c);
		}

		constexpr comparison_function compare_function() const
		{
			return sampler_state_impl().compare_function();
		}

		void compare_function(comparison_function fn)
		{
			sampler_state_impl().compare_function(fn);
		}

		bool is_addressing_mode_supported(texture_address_mode mode)
		{
			return sampler_state_impl().is_addressing_mode_supported(mode);
		}

	private:
		virtual void set_defaults() override;
		virtual render_state_key compute_render_state_key() const override;
	};
}

template<>
struct std::hash<openworld::sampler_state>
{
	size_t operator()(const openworld::sampler_state& s) const
	{
		size_t hash = 0;
		openworld::hash_combine(hash, openworld::render_state_type::sampler_state);
		openworld::hash_combine(hash, s.address_u());
		openworld::hash_combine(hash, s.address_v());
		openworld::hash_combine(hash, s.address_w());
		openworld::hash_combine(hash, s.filter());
		openworld::hash_combine(hash, s.max_anisotropy());
		openworld::hash_combine(hash, s.min_mip_map_level());
		openworld::hash_combine(hash, s.max_mip_map_level());
		openworld::hash_combine(hash, s.mip_map_level_of_detail_bias());
		openworld::hash_combine(hash, s.border_color());
		openworld::hash_combine(hash, s.compare_function());
		return hash;
	}
};