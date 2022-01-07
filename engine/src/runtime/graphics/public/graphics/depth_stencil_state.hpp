#pragma once

namespace openworld
{
	class render_system;
	class render_context;

	template <>
	class graphics_resource_traits<class depth_stencil_state>
	{
	public:
		using impl = depth_stencil_state_impl;
		using impl_factory = depth_stencil_state_impl_factory;

		static constexpr graphics_resource_type resource_type = graphics_resource_type::depth_stencil_state;
	};

	class depth_stencil_state final :
		public render_state
	{
		OPENWORLD_DELETE_COPY_OPERATORS(depth_stencil_state);

	public:
		depth_stencil_state(openworld::render_system& render_sys);
		virtual ~depth_stencil_state() {}

		openworld::depth_stencil_state_impl& depth_stencil_state_impl() const
		{
			return static_cast<openworld::depth_stencil_state_impl&>(impl());
		}

		virtual render_state_type state_type() const override
		{
			return render_state_type::depth_stencil_state;
		}

		bool depth_enable() const
		{
			return depth_stencil_state_impl().depth_enable();
		}

		void depth_enable(bool enable)
		{
			depth_stencil_state_impl().depth_enable(enable);
		}

		bool depth_write_enable() const
		{
			return depth_stencil_state_impl().depth_write_enable();
		}

		void depth_write_enable(bool enable)
		{
			depth_stencil_state_impl().depth_write_enable(enable);
		}

		comparison_function depth_function() const
		{
			return depth_stencil_state_impl().depth_function();
		}

		void depth_function(comparison_function fn)
		{
			depth_stencil_state_impl().depth_function(fn);
		}

		bool stencil_enable() const
		{
			return depth_stencil_state_impl().stencil_enable();
		}

		void stencil_enable(bool enable)
		{
			depth_stencil_state_impl().stencil_enable(enable);
		}

		int reference_stencil() const
		{
			return depth_stencil_state_impl().reference_stencil();
		}

		void reference_stencil(int value)
		{
			depth_stencil_state_impl().reference_stencil(value);
		}

		size_t stencil_read_mask() const
		{
			return depth_stencil_state_impl().stencil_read_mask();
		}

		void stencil_read_mask(size_t mask)
		{
			depth_stencil_state_impl().stencil_read_mask(mask);
		}

		size_t stencil_write_mask() const
		{
			return depth_stencil_state_impl().stencil_write_mask();
		}

		void stencil_write_mask(size_t mask)
		{
			depth_stencil_state_impl().stencil_write_mask(mask);
		}

		bool two_sided_stencil_enable() const
		{
			return depth_stencil_state_impl().two_sided_stencil_enable();
		}

		void two_sided_stencil_enable(bool enable)
		{
			depth_stencil_state_impl().two_sided_stencil_enable(enable);
		}

		comparison_function stencil_function() const
		{
			return depth_stencil_state_impl().stencil_function();
		}

		void stencil_function(comparison_function fn)
		{
			depth_stencil_state_impl().stencil_function(fn);
		}

		stencil_operation stencil_depth_fail() const
		{
			return depth_stencil_state_impl().stencil_depth_fail();
		}

		void stencil_depth_fail(stencil_operation op)
		{
			depth_stencil_state_impl().stencil_depth_fail(op);
		}

		stencil_operation stencil_fail() const
		{
			return depth_stencil_state_impl().stencil_fail();
		}

		void stencil_fail(stencil_operation op)
		{
			depth_stencil_state_impl().stencil_fail(op);
		}

		stencil_operation stencil_pass() const
		{
			return depth_stencil_state_impl().stencil_pass();
		}

		void stencil_pass(stencil_operation op)
		{
			depth_stencil_state_impl().stencil_pass(op);
		}

		comparison_function back_face_stencil_function() const
		{
			return depth_stencil_state_impl().back_face_stencil_function();
		}

		void back_face_stencil_function(comparison_function fn)
		{
			depth_stencil_state_impl().back_face_stencil_function(fn);
		}

		stencil_operation back_face_stencil_depth_fail() const
		{
			return depth_stencil_state_impl().back_face_stencil_depth_fail();
		}

		void back_face_stencil_depth_fail(stencil_operation op)
		{
			depth_stencil_state_impl().back_face_stencil_depth_fail(op);
		}

		stencil_operation back_face_stencil_fail() const
		{
			return depth_stencil_state_impl().back_face_stencil_fail();
		}

		void back_face_stencil_fail(stencil_operation op)
		{
			depth_stencil_state_impl().back_face_stencil_fail(op);
		}

		stencil_operation back_face_stencil_pass() const
		{
			return depth_stencil_state_impl().back_face_stencil_pass();
		}

		void back_face_stencil_pass(stencil_operation op)
		{
			depth_stencil_state_impl().back_face_stencil_pass(op);
		}

	private:
		virtual void set_defaults() override;
		virtual render_state_key compute_render_state_key() const override;
	};
}

template<>
struct std::hash<openworld::depth_stencil_state>
{
	size_t operator()(const openworld::depth_stencil_state& s) const
	{
		size_t hash = 0;
		openworld::hash_combine(hash, openworld::render_state_type::depth_stencil_state);
		openworld::hash_combine(hash, s.depth_enable());
		openworld::hash_combine(hash, s.depth_write_enable());
		openworld::hash_combine(hash, s.depth_function());
		openworld::hash_combine(hash, s.stencil_enable());
		openworld::hash_combine(hash, s.two_sided_stencil_enable());
		openworld::hash_combine(hash, s.reference_stencil());
		openworld::hash_combine(hash, s.stencil_function());
		openworld::hash_combine(hash, s.stencil_depth_fail());
		openworld::hash_combine(hash, s.stencil_fail());
		openworld::hash_combine(hash, s.stencil_pass());
		openworld::hash_combine(hash, s.back_face_stencil_function());
		openworld::hash_combine(hash, s.back_face_stencil_depth_fail());
		openworld::hash_combine(hash, s.back_face_stencil_fail());
		openworld::hash_combine(hash, s.back_face_stencil_pass());
		openworld::hash_combine(hash, s.stencil_write_mask());
		openworld::hash_combine(hash, s.stencil_read_mask());

		return hash;
	}
};