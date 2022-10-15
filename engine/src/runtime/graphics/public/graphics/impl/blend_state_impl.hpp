#pragma once

namespace openworld
{
	class render_context;

	class blend_state_impl :
		public render_state_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(blend_state_impl);

	public:
		blend_state_impl(size_t resource_id, openworld::render_system& render_system) :
			render_state_impl(resource_id, render_system)
		{}

		virtual ~blend_state_impl() = 0;

		virtual size_t render_target_blend_count() const = 0;
		virtual bool is_alpha_to_coverage_supported() const = 0;
		virtual bool is_independent_blend_supported() const = 0;

		constexpr bool alpha_to_coverage_enable() const
		{
			return m_alpha_to_coverage_enable;
		}

		void alpha_to_coverage_enable(bool enable)
		{
			throw_if_bound();
			m_alpha_to_coverage_enable = enable;
		}

		constexpr bool independent_blend_enable() const
		{
			return m_independent_blend_enable;
		}

		void independent_blend_enable(bool enable)
		{
			throw_if_bound();
			m_independent_blend_enable = enable;
		}

		constexpr color blend_factor() const
		{
			return m_blend_factor;
		}

		void blend_factor(const color& factor)
		{
			throw_if_bound();
			m_blend_factor = factor;
		}

		constexpr size_t multi_sample_mask() const
		{
			return m_multi_sample_mask;
		}

		void multi_sample_mask(size_t mask)
		{
			throw_if_bound();
			m_multi_sample_mask = mask;
		}

		virtual render_target_blend_description get_render_target_blend_description(
			size_t render_target_index) const = 0;

		virtual void set_render_target_blend_description(
			size_t render_target_index,
			const render_target_blend_description& desc) = 0;

	private:
		bool m_alpha_to_coverage_enable = false;
		bool m_independent_blend_enable = false;
		color m_blend_factor = color::transparent_black;
		size_t m_multi_sample_mask = 0;
	};

	class blend_state_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		blend_state_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~blend_state_impl_factory() = 0;

		virtual std::unique_ptr<blend_state_impl> create_impl() = 0;
	};
}
