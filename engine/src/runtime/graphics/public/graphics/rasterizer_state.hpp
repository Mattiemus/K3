#pragma once

namespace openworld
{
	class render_system;
	class render_context;

	template <>
	class graphics_resource_traits<class rasterizer_state>
	{
	public:
		using impl = rasterizer_state_impl;
		using impl_factory = rasterizer_state_impl_factory;

		static constexpr graphics_resource_type resource_type = graphics_resource_type::rasterizer_state;
	};

	class rasterizer_state final :
		public render_state
	{
	public:
		rasterizer_state(openworld::render_system& render_sys);
		virtual ~rasterizer_state() {}

		virtual graphics_resource_impl* impl() const noexcept override
		{
			return m_impl.get();
		}

		virtual openworld::render_state_impl* render_state_impl() const noexcept override
		{
			return m_impl.get();
		}

		openworld::rasterizer_state_impl* rasterizer_state_impl() const noexcept
		{
			return m_impl.get();
		}

		virtual render_state_type state_type() const override
		{
			return render_state_type::rasterizer_state;
		}

		bool is_antialiased_line_option_supported() const
		{
			return m_impl->is_antialiased_line_option_supported();
		}

		bool is_depth_clip_option_supported() const
		{
			return m_impl->is_depth_clip_option_supported();
		}

		cull_mode cull() const
		{
			return m_impl->cull();
		}

		void cull(cull_mode mode)
		{
			m_impl->cull(mode);
		}

		openworld::vertex_winding vertex_winding() const
		{
			return m_impl->vertex_winding();
		}

		void vertex_winding(openworld::vertex_winding winding)
		{
			m_impl->vertex_winding(winding);
		}

		fill_mode fill() const
		{
			return m_impl->fill();
		}

		void fill(fill_mode fill)
		{
			m_impl->fill(fill);
		}

		size_t depth_bias() const
		{
			return m_impl->depth_bias();
		}

		void depth_bias(size_t bias)
		{
			m_impl->depth_bias(bias);
		}

		float depth_bias_clamp() const
		{
			return m_impl->depth_bias_clamp();
		}

		void depth_bias_clamp(float bias)
		{
			m_impl->depth_bias_clamp(bias);
		}

		float slope_scaled_depth_bias() const
		{
			return m_impl->slope_scaled_depth_bias();
		}

		void slope_scaled_depth_bias(float bias)
		{
			m_impl->slope_scaled_depth_bias(bias);
		}

		bool depth_clip_enable() const
		{
			return m_impl->depth_clip_enable();
		}

		void depth_clip_enable(bool enable)
		{
			m_impl->depth_clip_enable(enable);
		}

		bool multi_sample_enable() const
		{
			return m_impl->multi_sample_enable();
		}

		void multi_sample_enable(bool enable)
		{
			m_impl->multi_sample_enable(enable);
		}

		bool antialiased_line_enable() const
		{
			return m_impl->antialiased_line_enable();
		}

		void antialiased_line_enable(bool enable)
		{
			m_impl->antialiased_line_enable(enable);
		}

		bool scissor_test_enable() const
		{
			return m_impl->scissor_test_enable();
		}

		void scissor_test_enable(bool enable)
		{
			m_impl->scissor_test_enable(enable);
		}

	private:
		std::unique_ptr<openworld::rasterizer_state_impl> m_impl;

		virtual void set_defaults() override;
		virtual render_state_key compute_render_state_key() const override;
	};
}

template<>
struct std::hash<openworld::rasterizer_state>
{
	size_t operator()(const openworld::rasterizer_state& s) const noexcept
	{
		size_t hash = 0;
		openworld::hash_combine(hash, openworld::render_state_type::rasterizer_state);
		openworld::hash_combine(hash, s.cull());
		openworld::hash_combine(hash, s.vertex_winding());
		openworld::hash_combine(hash, s.fill());
		openworld::hash_combine(hash, s.depth_bias());
		openworld::hash_combine(hash, s.depth_bias_clamp());
		openworld::hash_combine(hash, s.slope_scaled_depth_bias());
		openworld::hash_combine(hash, s.depth_clip_enable());
		openworld::hash_combine(hash, s.multi_sample_enable());
		openworld::hash_combine(hash, s.antialiased_line_enable());
		openworld::hash_combine(hash, s.scissor_test_enable());
		return hash;
	}
};