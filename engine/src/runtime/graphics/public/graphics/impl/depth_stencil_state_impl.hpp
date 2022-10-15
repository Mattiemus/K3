#pragma once

namespace openworld
{
	class render_context;

	class depth_stencil_state_impl :
		public render_state_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(depth_stencil_state_impl);

	public:
		depth_stencil_state_impl(size_t resource_id, openworld::render_system& render_system) :
			render_state_impl(resource_id, render_system)
		{}

		virtual ~depth_stencil_state_impl() = 0;

		constexpr bool depth_enable() const
		{
			return m_depth_enable;
		}

		void depth_enable(bool enable)
		{
			throw_if_bound();
			m_depth_enable = enable;
		}

		constexpr bool depth_write_enable() const
		{
			return m_depth_write_enable;
		}

		void depth_write_enable(bool enable)
		{
			throw_if_bound();
			m_depth_write_enable = enable;
		}

		constexpr comparison_function depth_function() const
		{
			return m_depth_function;
		}

		void depth_function(comparison_function fn)
		{
			throw_if_bound();
			m_depth_function = fn;
		}

		constexpr bool stencil_enable() const
		{
			return m_stencil_enable;
		}

		void stencil_enable(bool enable)
		{
			throw_if_bound();
			m_stencil_enable = enable;
		}

		constexpr int reference_stencil() const
		{
			return m_reference_stencil;
		}

		void reference_stencil(int value)
		{
			throw_if_bound();
			m_reference_stencil = value;
		}

		constexpr size_t stencil_read_mask() const
		{
			return m_stencil_read_mask;
		}

		void stencil_read_mask(size_t mask)
		{
			throw_if_bound();
			m_stencil_read_mask = mask;
		}

		constexpr size_t stencil_write_mask() const
		{
			return m_stencil_write_mask;
		}

		void stencil_write_mask(size_t mask)
		{
			throw_if_bound();
			m_stencil_write_mask = mask;
		}

		constexpr bool two_sided_stencil_enable() const
		{
			return m_two_sided_stencil_enable;
		}

		void two_sided_stencil_enable(bool enable)
		{
			throw_if_bound();
			m_two_sided_stencil_enable = enable;
		}

		constexpr comparison_function stencil_function() const
		{
			return m_stencil_function;
		}

		void stencil_function(comparison_function fn)
		{
			throw_if_bound();
			m_stencil_function = fn;
		}

		constexpr stencil_operation stencil_depth_fail() const
		{
			return m_stencil_depth_fail;
		}

		void stencil_depth_fail(stencil_operation op)
		{
			throw_if_bound();
			m_stencil_depth_fail = op;
		}

		constexpr stencil_operation stencil_fail() const
		{
			return m_stencil_fail;
		}

		void stencil_fail(stencil_operation op)
		{
			throw_if_bound();
			m_stencil_fail = op;
		}

		constexpr stencil_operation stencil_pass() const
		{
			return m_stencil_pass;
		}

		void stencil_pass(stencil_operation op)
		{
			throw_if_bound();
			m_stencil_pass = op;
		}

		constexpr comparison_function back_face_stencil_function() const
		{
			return m_back_face_stencil_function;
		}

		void back_face_stencil_function(comparison_function fn)
		{
			throw_if_bound();
			m_back_face_stencil_function = fn;
		}

		constexpr stencil_operation back_face_stencil_depth_fail() const
		{
			return m_back_face_stencil_depth_fail;
		}

		void back_face_stencil_depth_fail(stencil_operation op)
		{
			throw_if_bound();
			m_back_face_stencil_depth_fail = op;
		}

		constexpr stencil_operation back_face_stencil_fail() const
		{
			return m_back_face_stencil_fail;
		}

		void back_face_stencil_fail(stencil_operation op)
		{
			throw_if_bound();
			m_back_face_stencil_fail = op;
		}

		constexpr stencil_operation back_face_stencil_pass() const
		{
			return m_back_face_stencil_pass;
		}

		void back_face_stencil_pass(stencil_operation op)
		{
			throw_if_bound();
			m_back_face_stencil_pass = op;
		}

	private:
		bool m_depth_enable = false;
		bool m_depth_write_enable = false;
		comparison_function m_depth_function = comparison_function::always;
		bool m_stencil_enable = false;
		int m_reference_stencil = 0;
		size_t m_stencil_read_mask = 0;
		size_t m_stencil_write_mask = 0;
		bool m_two_sided_stencil_enable = false;
		comparison_function m_stencil_function = comparison_function::always;
		stencil_operation m_stencil_depth_fail = stencil_operation::keep;
		stencil_operation m_stencil_fail = stencil_operation::keep;
		stencil_operation m_stencil_pass = stencil_operation::keep;
		comparison_function m_back_face_stencil_function = comparison_function::always;
		stencil_operation m_back_face_stencil_depth_fail = stencil_operation::keep;
		stencil_operation m_back_face_stencil_fail = stencil_operation::keep;
		stencil_operation m_back_face_stencil_pass = stencil_operation::keep;
	};

	class depth_stencil_state_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		depth_stencil_state_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~depth_stencil_state_impl_factory() = 0;

		virtual std::unique_ptr<depth_stencil_state_impl> create_impl() = 0;
	};
}