#pragma once

#include <memory>

namespace openworld
{
    template <typename Instance>
    class instance_ptr final
    {
    public:
        instance_ptr()
        {}

        instance_ptr(std::nullptr_t)
        {}

        explicit instance_ptr(std::shared_ptr<Instance> ptr) :
            m_ptr(ptr)
        {}

        ~instance_ptr()
        {
            if (m_ptr != nullptr)
            {
                auto no_parent_no_refs = m_ptr->get_parent() == nullptr && m_ptr.use_count() == 1;
                auto parent_no_other_refs = m_ptr->get_parent() != nullptr && m_ptr.use_count() == 2;

                if (no_parent_no_refs || parent_no_other_refs)
                {
                    m_ptr->set_parent(nullptr);
                    m_ptr->clear_all_children();
                }
            }
        }

        Instance* get() const
        {
            return m_ptr.get();
        }

        std::shared_ptr<Instance> get_shared_ptr() const
        {
            return m_ptr;
        }

        Instance& operator *() const
        {
            return *m_ptr;
        }

        Instance* operator ->() const
        {
            return m_ptr.get();
        }

    private:
        std::shared_ptr<Instance> m_ptr;
    };

    template<typename T, typename U>
    inline bool operator==(const instance_ptr<T>& lhs, const instance_ptr<U>& rhs)
    {
        return lhs.get() == rhs.get();
    }

    template<typename T, typename U>
    inline bool operator!=(const instance_ptr<T>& lhs, const instance_ptr<U>& rhs)
    {
        return lhs.get() != rhs.get();
    }

    template<typename T>
    inline bool operator==(const instance_ptr<T>& lhs, std::nullptr_t)
    {
        return lhs.get() == nullptr;
    }

    template<typename T>
    inline bool operator!=(const instance_ptr<T>& lhs, std::nullptr_t)
    {
        return lhs.get() != nullptr;
    }

    template<typename T, typename U>
    inline instance_ptr<T> static_instance_cast(const instance_ptr<U>& ptr)
    {
        return instance_ptr<T>(std::static_pointer_cast<T>(ptr.get_shared_ptr()));
    }
}