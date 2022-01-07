#pragma once

namespace openworld
{
    class render_system;
    class render_context;

    template <>
    class graphics_resource_traits<class occlusion_query>
    {
    public:
        using impl = occlusion_query_impl;
        using impl_factory = occlusion_query_impl_factory;

        static constexpr graphics_resource_type resource_type = graphics_resource_type::occlusion_query;
    };

    class occlusion_query final :
        public graphics_resource
    {
        OPENWORLD_DELETE_COPY_OPERATORS(occlusion_query);

    public:
        occlusion_query(openworld::render_system& render_sys);

        virtual ~occlusion_query() {}

        openworld::occlusion_query_impl& occlusion_query_impl() const
        {
            return static_cast<openworld::occlusion_query_impl&>(impl());
        }

        bool is_complete() const
        {
            return occlusion_query_impl().is_complete();
        }

        size_t pixel_count() const
        {
            return occlusion_query_impl().pixel_count();
        }

        void begin()
        {
            occlusion_query_impl().begin();
        }

        void end()
        {
            occlusion_query_impl().end();
        }
    };
}