#pragma once

namespace openworld
{
	class shader_resource
	{
		OPENWORLD_DELETE_COPY_OPERATORS(shader_resource);

	public:
		shader_resource() {}
		virtual ~shader_resource() = 0;

		virtual shader_resource_type resource_type() const = 0;
	};
}