#pragma once

namespace openworld
{
	class render_context;

	class rasterizer_state_impl :
		public render_state_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(rasterizer_state_impl);

	public:
		rasterizer_state_impl(size_t resource_id, openworld::render_system& render_system) :
			render_state_impl(resource_id, render_system)
		{}

		virtual ~rasterizer_state_impl() = 0 {}

		virtual bool is_antialiased_line_option_supported() const = 0;
		virtual bool is_depth_clip_option_supported() const = 0;

		constexpr cull_mode cull() const
		{
			return m_cull;
		}

		void cull(cull_mode mode)
		{
			throw_if_bound();
			m_cull = mode;
		}

		constexpr openworld::vertex_winding vertex_winding() const
		{
			return m_vertex_winding;
		}

		void vertex_winding(openworld::vertex_winding winding)
		{
			throw_if_bound();
			m_vertex_winding = winding;
		}

		constexpr fill_mode fill() const
		{
			return m_fill;
		}

		void fill(fill_mode fill)
		{
			throw_if_bound();
			m_fill = fill;
		}

		constexpr size_t depth_bias() const
		{
			return m_depth_bias;
		}

		void depth_bias(size_t bias)
		{
			throw_if_bound();
			m_depth_bias = bias;
		}

		constexpr float depth_bias_clamp() const
		{
			return m_depth_bias_clamp;
		}

		void depth_bias_clamp(float bias)
		{
			throw_if_bound();
			m_depth_bias_clamp = bias;
		}

		constexpr float slope_scaled_depth_bias() const
		{
			return m_slope_scaled_depth_bias;
		}

		void slope_scaled_depth_bias(float bias)
		{
			throw_if_bound();
			m_slope_scaled_depth_bias = bias;
		}

		constexpr bool depth_clip_enable() const
		{
			return m_depth_clip_enable;
		}

		void depth_clip_enable(bool enable)
		{
			throw_if_bound();
			m_depth_clip_enable = enable;
		}

		constexpr bool multi_sample_enable() const
		{
			return m_multi_sample_enable;
		}

		void multi_sample_enable(bool enable)
		{
			throw_if_bound();
			m_multi_sample_enable = enable;
		}

		constexpr bool antialiased_line_enable() const
		{
			return m_antialiased_line_enable;
		}

		void antialiased_line_enable(bool enable)
		{
			throw_if_bound();
			m_antialiased_line_enable = enable;
		}

		constexpr bool scissor_test_enable() const
		{
			return m_scissor_test_enable;
		}

		void scissor_test_enable(bool enable)
		{
			throw_if_bound();
			m_scissor_test_enable = enable;
		}

	private:
		cull_mode m_cull = cull_mode::none;
		openworld::vertex_winding m_vertex_winding = openworld::vertex_winding::clockwise;
		fill_mode m_fill = fill_mode::solid;
		size_t m_depth_bias = 0;
		float m_depth_bias_clamp = 0.0f;
		float m_slope_scaled_depth_bias = 0.0f;
		bool m_depth_clip_enable = false;
		bool m_multi_sample_enable = false;
		bool m_antialiased_line_enable = false;
		bool m_scissor_test_enable = false;
	};

	class rasterizer_state_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		rasterizer_state_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~rasterizer_state_impl_factory() = 0 {}

		virtual std::unique_ptr<rasterizer_state_impl> create_impl() = 0;
	};
}
