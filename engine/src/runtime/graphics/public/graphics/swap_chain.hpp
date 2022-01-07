#pragma once

namespace openworld
{
    class render_system;
    class render_context;

    template <>
    class graphics_resource_traits<class swap_chain>
    {
    public:
        using impl = swap_chain_impl;
        using impl_factory = swap_chain_impl_factory;

        static constexpr graphics_resource_type resource_type = graphics_resource_type::swap_chain;
    };

    class swap_chain final :
        public graphics_resource
    {
        OPENWORLD_DELETE_COPY_OPERATORS(swap_chain);

    public:
        swap_chain(
            openworld::render_system& render_sys,
            void* window_handle,
            const presentation_parameters& presentation_params);

        virtual ~swap_chain() {}

        openworld::swap_chain_impl& swap_chain_impl() const
        {
            return static_cast<openworld::swap_chain_impl&>(impl());
        }

        const openworld::presentation_parameters& presentation_parameters() const
        {
            return swap_chain_impl().presentation_parameters();
        }

        const display_mode& current_display_mode() const
        {
            return swap_chain_impl().current_display_mode();
        }

        void* window_handle() const
        {
            return swap_chain_impl().window_handle();
        }

        void* monitor_handle() const
        {
            return swap_chain_impl().monitor_handle();
        }

        bool is_full_screen() const
        {
            return swap_chain_impl().is_full_screen();
        }

        bool is_wide_screen() const
        {
            return swap_chain_impl().is_wide_screen();
        }

        void clear(
            render_context& render_ctx,
            clear_options options,
            const color& clear_color,
            float depth,
            int stencil)
        {
            clear(
                render_ctx,
                options,
                clear_color,
                depth,
                stencil);
        }

        void get_back_buffer_data(
            const memory_region& data,
            const std::optional<resource_region_2d>& subimage,
            size_t start_index)
        {
            swap_chain_impl().get_back_buffer_data(
                data,
                subimage,
                start_index);
        }

        void present()
        {
            swap_chain_impl().present();
        }

        void reset(
            void* window_handle,
            const openworld::presentation_parameters& presentation_params)
        {
            swap_chain_impl().reset(window_handle, presentation_params);
        }

        void resize(size_t width, size_t height)
        {
            swap_chain_impl().resize(width, height);
        }

        bool toggle_full_screen()
        {
            return swap_chain_impl().toggle_full_screen();
        }
    };
}