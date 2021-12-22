#pragma once

namespace openworld
{
	class component_registry final
	{
    public:
        template <typename Component>
        static component_id get_component_id()
        {
            const auto& component_type = typeid(Component);

            auto it = s_component_ids.find(component_type);
            if (it == s_component_ids.end())
            {
                auto id = register_component_type<Component>();
                return id;
            }

            return it->second;
        }

        template <typename Component>
        static component_mask get_component_mask()
        {
            auto id = get_component_id<Component>();

            component_mask mask;
            mask.set(id, true);

            return mask;
        }

        template <typename Component1, typename Component2, typename... Components>
        static component_mask get_component_mask()
        {
            auto first_mask = get_component_mask<Component1>();
            auto next_masks = get_component_mask<Component2, Components...>();

            return first_mask | next_masks;
        }

    private:
        static std::unordered_map<std::type_index, component_id> s_component_ids;
        static component_id s_next_component_id;

        template <typename Component>
        static component_id register_component_type()
        {
            const auto& component_type = typeid(Component);

            auto it = s_component_ids.find(component_type);
            if (it != s_component_ids.end())
            {
                return it->second;
            }

            auto id = s_next_component_id;
            s_component_ids.insert({ component_type, id });

            s_next_component_id++;

            return id;
        }
	};









}