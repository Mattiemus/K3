#pragma once

namespace openworld
{
	class render_system;
	class graphics_resource_impl;

	template <typename Resource>
	class graphics_resource_traits;

	class graphics_resource
	{
		OPENWORLD_DELETE_COPY_OPERATORS(graphics_resource);

	public:
		graphics_resource() :
			m_name("<no name>"), m_tag(nullptr)
		{}

		virtual ~graphics_resource() = 0;

		graphics_resource_impl& impl() const
		{
			return *m_impl;
		}

		const std::string& name() const
		{
			return m_name;
		}

		void name(const std::string& new_name)
		{
			m_name = new_name;
		}

		void* tag() const
		{
			return m_tag;
		}

		void tag(void* new_tag)
		{
			m_tag = new_tag;
		}

		size_t resource_id() const
		{
			return impl().resource_id();
		}

		openworld::render_system& render_system() const
		{
			return impl().render_system();
		}

	protected:
		void bind_impl(std::unique_ptr<graphics_resource_impl>&& impl)
		{
			m_impl = std::move(impl);
		}

	private:
		std::unique_ptr<graphics_resource_impl> m_impl;
		std::string m_name;
		void* m_tag;
	};
}