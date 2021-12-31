#pragma once

namespace openworld
{
	class render_system;
	class graphics_resource_impl;

	template <typename Resource>
	class graphics_resource_traits;

	class graphics_resource
	{
	public:
		constexpr graphics_resource() :
			m_name("<no name>"), m_tag(nullptr)
		{}

		virtual ~graphics_resource() = 0 {}

		virtual graphics_resource_impl* impl() const noexcept = 0;

		const std::string& name() const noexcept
		{
			return m_name;
		}

		void name(const std::string& new_name)
		{
			m_name = new_name;
		}

		void* tag() const noexcept
		{
			return m_tag;
		}

		void tag(void* new_tag) noexcept
		{
			m_tag = new_tag;
		}

		size_t resource_id() const
		{
			return impl()->resource_id();
		}

		openworld::render_system& render_system() const
		{
			return impl()->render_system();
		}

	private:
		std::string m_name;
		void* m_tag;
	};
}