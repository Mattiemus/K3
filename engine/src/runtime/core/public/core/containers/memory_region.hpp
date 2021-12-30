#pragma once

namespace openworld
{
    class memory_region
    {
    public:
        using element_type = std::byte;
        using value_type = std::remove_cv_t<std::byte>;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using pointer = std::byte*;
        using const_pointer = const std::byte*;
        using reference = std::byte&;
        using const_reference = const std::byte&;
        using iterator = std::byte*;
        using reverse_iterator = std::reverse_iterator<iterator>;

        constexpr memory_region() noexcept :
            m_element_size(0),
            m_element_count(0),
            m_data(nullptr)
        {}

        template <typename T>
        constexpr memory_region(T* data, size_type size) noexcept :
            m_element_size(sizeof(T)),
            m_element_count(size),
            m_data(reinterpret_cast<pointer>(data))
        {}

        constexpr memory_region(pointer data, size_type size_bytes, size_type element_size) noexcept :
            m_element_size(element_size),
            m_element_count(size_bytes / element_size),
            m_data(data)
        {}

        template <typename T>
        constexpr memory_region(std::vector<T>& data) noexcept :
            m_element_size(sizeof(T)),
            m_element_count(data.size()),
            m_data(reinterpret_cast<pointer>(data.data()))
        {}

        constexpr memory_region(const memory_region& other) noexcept = default;

        constexpr memory_region& operator=(const memory_region& other) noexcept = default;

        constexpr size_type size() const noexcept
        {
            return m_element_count;
        }

        constexpr size_type size_bytes() const noexcept
        {
            return m_element_count * m_element_size;
        }

        constexpr size_type size_element() const noexcept
        {
            return m_element_size;
        }

        constexpr pointer data() const noexcept
        {
            return m_data;
        }

        constexpr bool is_empty() const noexcept
        {
            return m_element_count == 0;
        }

        constexpr iterator begin() const noexcept
        {
            return m_data;
        }

        constexpr iterator end() const noexcept
        {
            return m_data + size_bytes();
        }

    protected:
        size_type m_element_size;
        size_type m_element_count;
        pointer m_data;
    };
}