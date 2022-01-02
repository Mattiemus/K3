#pragma once

namespace openworld
{
	class shader_resource
	{
	public:
		virtual ~shader_resource() = 0 {}

		virtual shader_resource_type resource_type() = 0;
	};
}