#pragma once

#include "graphics.hpp"

namespace openworld
{
	class gl_render_system;

	class gl_vertex_buffer_impl final :
		public vertex_buffer_impl
	{
	public:
		gl_vertex_buffer_impl(
			openworld::gl_render_system& render_sys,
			const vertex_layout& layout,
			size_t vertex_count,
			resource_usage usage);

		gl_vertex_buffer_impl(
			openworld::gl_render_system& render_sys,
			const vertex_layout& layout,
			const memory_region& data,
			resource_usage usage);

		gl_vertex_buffer_impl(
			openworld::gl_render_system& render_sys,
			const vertex_layout& layout,
			const std::vector<memory_region>& data,
			resource_usage usage);

		virtual ~gl_vertex_buffer_impl();

		GLuint gl_buffer_id() const
		{
			return m_buffer_id;
		}

		openworld::gl_render_system& gl_render_system() const
		{
			return m_render_sys;
		}

		virtual size_t resource_id() const override
		{
			throw std::exception();
		}

		virtual openworld::render_system& render_system() const override;

		virtual const vertex_layout& layout() const override
		{
			return m_vertex_layout;
		}

		virtual size_t vertex_count() const override
		{
			return m_vertex_count;
		}

		virtual resource_usage usage() const override
		{
			return m_resource_usage;
		}

		virtual void get_interleaved_data(
			const std::vector<memory_region>& data) override;

		virtual void set_interleaved_data(
			render_context& render_ctx,
			const std::vector<memory_region>& data) override;

		virtual void get_data(
			const memory_region& data,
			size_t start_index,
			size_t element_count,
			size_t buffer_read_start_offset,
			size_t vertex_stride) override;

		virtual void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			size_t element_count,
			size_t buffer_write_start_offset,
			size_t vertex_stride,
			data_write_options write_opts) override;

	private:
		openworld::gl_render_system& m_render_sys;
		GLuint m_buffer_id;
		vertex_layout m_vertex_layout;
		size_t m_vertex_count;
		resource_usage m_resource_usage;
	};

	class gl_vertex_buffer_impl_factory final :
		public vertex_buffer_impl_factory
	{
	public:
		gl_vertex_buffer_impl_factory(gl_render_system& render_sys) :
			m_render_sys(render_sys)
		{
		}

		virtual ~gl_vertex_buffer_impl_factory() {}

		virtual openworld::render_system& render_system() const override
		{
			throw std::exception("not implemented");
			//return m_render_sys;
		}

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			size_t vertex_count,
			resource_usage usage) override
		{
			return std::make_unique<gl_vertex_buffer_impl>(
				m_render_sys,
				layout,
				vertex_count,
				usage);
		}

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			const memory_region& data,
			resource_usage usage) override
		{
			return std::make_unique<gl_vertex_buffer_impl>(
				m_render_sys,
				layout,
				data,
				usage);
		}

		virtual std::unique_ptr<vertex_buffer_impl> create_impl(
			const vertex_layout& layout,
			const std::vector<memory_region>& data,
			resource_usage usage) override
		{
			return std::make_unique<gl_vertex_buffer_impl>(
				m_render_sys,
				layout,
				data,
				usage);
		}

	private:
		gl_render_system& m_render_sys;
	};
}