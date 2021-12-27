#pragma once

namespace openworld
{
	class render_system;

	class graphics_resource_impl
	{
	public:
		virtual ~graphics_resource_impl() = 0 {}

		virtual size_t resource_id() const = 0;
		virtual openworld::render_system& render_system() const = 0;
	};

	class graphics_resource_impl_factory
	{
	public:
		virtual ~graphics_resource_impl_factory() = 0 {}

		virtual openworld::render_system& render_system() const = 0;
	};
}