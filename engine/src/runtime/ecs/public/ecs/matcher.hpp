#pragma once

namespace openworld
{
	class matcher final
	{
	public:
		template <typename Component, typename... Components>
		static matcher all_of()
		{
			auto mask = component_registry::get_component_mask<Component, Components...>();

			matcher m{};
			m.m_all_of = mask;

			return m;
		}

		template <typename Component, typename... Components>
		static matcher any_of()
		{
			auto mask = component_registry::get_component_mask<Component, Components...>();

			matcher m{};
			m.m_any_of = mask;

			return m;
		}

		template <typename Component, typename... Components>
		static matcher none_of()
		{
			auto mask = component_registry::get_component_mask<Component, Components...>();

			matcher m{};
			m.m_none_of = mask;

			return m;
		}

		bool empty() const
		{
			return m_all_of.none() && m_any_of.none() && m_none_of.none();
		}

		bool matches(const component_mask& mask) const
		{
			auto has_all = (m_all_of & mask) == m_all_of;
			auto has_any = (m_any_of & mask).any();
			auto has_none = (m_none_of & mask).none();

			return false;
		}

	private:
		component_mask m_all_of;
		component_mask m_any_of;
		component_mask m_none_of;
	};
}