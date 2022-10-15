#pragma once

#include "graphics.hpp"

namespace openworld
{
	class gl_render_system;

	class gl_swap_chain_impl final :
		public swap_chain_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(gl_swap_chain_impl);

	public:
		gl_swap_chain_impl(
			size_t resource_id, 
			openworld::render_system& render_system,
			void* window_handle,
			const presentation_parameters& presentation_params);

		virtual ~gl_swap_chain_impl();

		virtual const openworld::presentation_parameters& presentation_parameters() const override;
		virtual const display_mode& current_display_mode() const override;
		virtual void* window_handle() const override;
		virtual void* monitor_handle() const override;
		virtual bool is_full_screen() const override;
		virtual bool is_wide_screen() const override;

		virtual void clear(
			render_context& render_ctx,
			clear_options options,
			const color& clear_color,
			float depth,
			int stencil) override;

		virtual void get_back_buffer_data(
			const memory_region& data,
			const std::optional<resource_region_2d>& subimage,
			size_t start_index) override;

		virtual void present() override;

		virtual void reset(
			void* window_handle,
			const openworld::presentation_parameters& presentation_params) override;

		virtual void resize(size_t width, size_t height) override;

		virtual bool toggle_full_screen() override;
	};

	class gl_swap_chain_impl_factory final :
		public swap_chain_impl_factory
	{
	public:
		gl_swap_chain_impl_factory(openworld::render_system& render_system);
		virtual ~swap_chain_impl_factory();

		virtual std::unique_ptr<swap_chain_impl> create_impl(
			void* window_handle,
			const presentation_parameters& presentation_params) override;
	};
}