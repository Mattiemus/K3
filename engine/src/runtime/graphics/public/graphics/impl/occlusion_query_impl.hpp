#pragma once

namespace openworld
{
	class render_context;

	class occlusion_query_impl :
		public graphics_resource_impl
	{
	public:
		virtual ~occlusion_query_impl() = 0 {}

		virtual bool is_complete() = 0;
		virtual size_t pixel_count() = 0;

		virtual void begin() = 0;
		virtual void end() = 0;
	};

	class occlusion_query_impl_factory :
		public graphics_resource_impl_factory
	{
	public:
		virtual ~occlusion_query_impl_factory() = 0 {}

		virtual std::unique_ptr<occlusion_query_impl> create_impl() = 0;
	};
}
