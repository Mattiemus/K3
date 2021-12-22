#pragma once

#include <vector>
#include <span>
#include <initializer_list>

#include "graphics/vertex_element.hpp"

namespace openworld
{
    class vertex_layout final
    {
    public:
        vertex_layout(std::initializer_list<const vertex_element> elements);
        vertex_layout(std::span<const vertex_element> elements);
        vertex_layout(size_t vertex_stride, const std::span<const vertex_element>& elements);

        static size_t calculate_offsets_and_get_vertex_stride(const std::span<vertex_element>& elements);
        static void validate_vertex_elements(size_t vertex_stride, const std::span<const vertex_element>& elements);

        const std::vector<vertex_element>& vertex_elements() const
        {
            return m_elements;
        }

        constexpr size_t vertex_stride() const
        {
            return m_vertex_stride;
        }

    private:
        std::vector<vertex_element> m_elements;
        size_t m_vertex_stride;
    };
}