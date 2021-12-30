#pragma once

namespace openworld
{
    class service_locator final
    {
    public:
        service_locator()
        {}

        void clear()
        {
            m_instances.clear();
        }

        template<typename Service>
        void add_service(const std::shared_ptr<Service>& service)
        {
            std::type_index type_idx = typeid(Service);

            if (m_instances.find(type_idx) == m_instances.end())
            {
                m_instances.emplace(type_idx, service);
            }
        }

        template<typename Service, typename Implementation, typename... Args>
        void make_service(Args&&... args)
        {
            std::type_index type_idx = typeid(Service);

            if (m_instances.find(type_idx) == m_instances.end())
            {
                m_instances.emplace(type_idx, std::make_shared<Implementation>(args...));
            }
        }

        template<typename Service>
        std::shared_ptr<Service> get_service() const
        {
            std::type_index type_idx = typeid(Service);

            auto itr1 = m_instances.find(type_idx);
            if (itr1 != m_instances.end())
            {
                return std::static_pointer_cast<Service>(itr1->second);
            }

            throw service_not_found();
        }

    private:
        std::unordered_map<std::type_index, std::shared_ptr<void>> m_instances;
    };
}