#pragma once

namespace openworld
{
    class render_system;
    class render_context;

    template <>
    class graphics_resource_traits<class blend_state>
    {
    public:
        using impl = blend_state_impl;
        using impl_factory = blend_state_impl_factory;

        static constexpr graphics_resource_type resource_type = graphics_resource_type::blend_state;
    };

	class blend_state final :
        public render_state
	{
		OPENWORLD_DELETE_COPY_OPERATORS(blend_state);

    public:
		blend_state(openworld::render_system& render_sys);
		virtual ~blend_state() {}

		openworld::blend_state_impl& blend_state_impl() const
		{
			return static_cast<openworld::blend_state_impl&>(impl());
		}

        virtual render_state_type state_type() const override
        {
            return render_state_type::blend_state;
        }

		size_t render_target_blend_count() const
		{
			return blend_state_impl().render_target_blend_count();
		}

		bool is_alpha_to_coverage_supported() const
		{
			return blend_state_impl().is_alpha_to_coverage_supported();
		}

		bool is_independent_blend_supported() const
		{
			return blend_state_impl().is_independent_blend_supported();
		}

		bool alpha_to_coverage_enable() const
		{
			return blend_state_impl().alpha_to_coverage_enable();
		}

		void alpha_to_coverage_enable(bool enable)
		{
			blend_state_impl().alpha_to_coverage_enable(enable);
		}

		bool independent_blend_enable() const
		{
			return blend_state_impl().independent_blend_enable();
		}

		void independent_blend_enable(bool enable)
		{
			blend_state_impl().independent_blend_enable(enable);
		}

		color blend_factor() const
		{
			return blend_state_impl().blend_factor();
		}

		void blend_factor(const color& factor)
		{
			blend_state_impl().blend_factor(factor);
		}

		size_t multi_sample_mask() const
		{
			return blend_state_impl().multi_sample_mask();
		}

		void multi_sample_mask(size_t mask)
		{
			blend_state_impl().multi_sample_mask(mask);
		}

		render_target_blend_description get_render_target_blend_description(
			size_t render_target_index) const
		{
			return blend_state_impl().get_render_target_blend_description(render_target_index);
		}

		void set_render_target_blend_description(
			size_t render_target_index,
			const render_target_blend_description& desc)
		{
			blend_state_impl().set_render_target_blend_description(
				render_target_index,
				desc);
		}

    private:
		virtual void set_defaults() override;
		virtual render_state_key compute_render_state_key() const override;
	};
}

template<>
struct std::hash<openworld::blend_state>
{
	size_t operator()(const openworld::blend_state& s) const
	{
		size_t hash = 0;
		openworld::hash_combine(hash, openworld::render_state_type::blend_state);
		openworld::hash_combine(hash, s.alpha_to_coverage_enable());
		openworld::hash_combine(hash, s.independent_blend_enable());
		openworld::hash_combine(hash, s.blend_factor());
		openworld::hash_combine(hash, s.multi_sample_mask());

		for (size_t i = 0; i < s.render_target_blend_count(); i++)
		{
			const auto& desc = s.get_render_target_blend_description(i);
			openworld::hash_combine(hash, desc);
		}

		return hash;
	}
};