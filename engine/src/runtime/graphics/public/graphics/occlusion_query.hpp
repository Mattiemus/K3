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
    public:
        occlusion_query(openworld::render_system& render_sys);

        virtual ~occlusion_query() {}

        virtual graphics_resource_impl* impl() const noexcept override
        {
            return m_impl.get();
        }

        openworld::occlusion_query_impl* occlusion_query_impl() const noexcept
        {
            return m_impl.get();
        }

        bool is_complete()
        {
            return m_impl->is_complete();
        }

        size_t pixel_count()
        {
            return m_impl->pixel_count();
        }

        void begin()
        {
            m_impl->begin();
        }

        void end()
        {
            m_impl->end();
        }

    private:
        std::unique_ptr<openworld::occlusion_query_impl> m_impl;
    };
}