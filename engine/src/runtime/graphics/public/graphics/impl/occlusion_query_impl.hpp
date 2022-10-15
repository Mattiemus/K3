#pragma once

namespace openworld
{
	class render_context;

	class occlusion_query_impl :
		public graphics_resource_impl
	{
		OPENWORLD_DELETE_COPY_OPERATORS(occlusion_query_impl);

	public:
		occlusion_query_impl(size_t resource_id, openworld::render_system& render_system) :
			graphics_resource_impl(resource_id, render_system)
		{}

		virtual ~occlusion_query_impl() = 0;

		virtual bool is_complete() const = 0;
		virtual size_t pixel_count() const = 0;

		virtual void begin() = 0;
		virtual void end() = 0;
	};

	class occlusion_query_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		occlusion_query_impl_factory(openworld::render_system& render_system) :
			graphics_resource_impl_factory(render_system)
		{}

		virtual ~occlusion_query_impl_factory() = 0;

		virtual std::unique_ptr<occlusion_query_impl> create_impl() = 0;
	};
}
