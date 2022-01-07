#pragma once

namespace openworld
{
	class render_context;

	class swap_chain_impl :
		public graphics_resource_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(swap_chain_impl);

	public:
		swap_chain_impl(size_t resource_id, openworld::render_system& render_system) :
			graphics_resource_impl(resource_id, render_system)
		{}

		virtual ~swap_chain_impl() = 0 {}

        virtual const openworld::presentation_parameters& presentation_parameters() const = 0;
        virtual const display_mode& current_display_mode() const = 0;
        virtual void* window_handle() const = 0;
        virtual void* monitor_handle() const = 0;
        virtual bool is_full_screen() const = 0;
        virtual bool is_wide_screen() const = 0;

		virtual void clear(
			render_context& render_ctx,
			clear_options options,
			const color& clear_color,
			float depth,
			int stencil) = 0;

		virtual void get_back_buffer_data(
			const memory_region& data,
			const std::optional<resource_region_2d>& subimage,
			size_t start_index) = 0;

		virtual void present() = 0; 

		virtual void reset(
			void* window_handle,
			const openworld::presentation_parameters& presentation_params) = 0;

		virtual void resize(size_t width, size_t height) = 0;

		virtual bool toggle_full_screen() = 0;
	};

	class swap_chain_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		swap_chain_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~swap_chain_impl_factory() = 0 {}

		virtual std::unique_ptr<swap_chain_impl> create_impl(
			void* window_handle, 
			const presentation_parameters& presentation_params) = 0;
	};
}