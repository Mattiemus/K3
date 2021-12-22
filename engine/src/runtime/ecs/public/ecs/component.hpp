#pragma once

namespace openworld
{
	using component_id = int32_t;

	using component_mask = std::bitset<sizeof(component_id) * 8>;

	template <typename Component>
	class component_traits
	{
	public:
		typedef array_component_storage<Component, 32> storage;
	};
}