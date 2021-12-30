#pragma once

#include "graphics.hpp"

namespace openworld
{
	class gl_render_system;

	class gl_index_buffer_impl final :
		public index_buffer_impl
	{
	public:
		gl_index_buffer_impl(
			openworld::gl_render_system& render_sys,
			index_format format,
			size_t index_count,
			resource_usage usage);

		gl_index_buffer_impl(
			openworld::gl_render_system& render_sys,
			index_format format,
			const memory_region& data,
			resource_usage usage);

		virtual ~gl_index_buffer_impl();

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

		virtual size_t index_count() const override
		{
			return m_index_count;
		}

		virtual index_format format() const override
		{
			return m_index_format;
		}

		virtual resource_usage usage() const override
		{
			return m_resource_usage;
		}

		virtual void get_data(
			const memory_region& data,
			size_t start_index,
			size_t element_count,
			size_t buffer_read_start_offset) override;

		virtual void set_data(
			render_context& render_ctx,
			const memory_region& data,
			size_t start_index,
			size_t element_count,
			size_t buffer_write_start_offset,
			data_write_options write_opts) override;

	private:
		openworld::gl_render_system& m_render_sys;
		GLuint m_buffer_id;
		size_t m_index_count;
		index_format m_index_format;
		resource_usage m_resource_usage;
	};

	class gl_index_buffer_impl_factory final :
		public index_buffer_impl_factory
	{
	public:
		gl_index_buffer_impl_factory(gl_render_system& render_sys) :
			m_render_sys(render_sys)
		{
		}

		virtual ~gl_index_buffer_impl_factory() {}

		virtual openworld::render_system& render_system() const override
		{
			throw std::exception("not implemented");
			//return m_render_sys;
		}

		virtual std::unique_ptr<index_buffer_impl> create_impl(
			index_format format,
			size_t index_count,
			resource_usage usage) override
		{
			return std::make_unique<gl_index_buffer_impl>(
				m_render_sys,
				format,
				index_count,
				usage);
		}

		virtual std::unique_ptr<index_buffer_impl> create_impl(
			index_format format,
			const memory_region& data,
			resource_usage usage) override
		{
			return std::make_unique<gl_index_buffer_impl>(
				m_render_sys,
				format,
				data,
				usage);
		}

	private:
		gl_render_system& m_render_sys;
	};
}