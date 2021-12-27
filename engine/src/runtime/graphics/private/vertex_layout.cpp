#include "graphics.hpp"

using namespace openworld;

vertex_layout::vertex_layout(std::initializer_list<const vertex_element> elements) :
    m_vertex_stride(0)
{
    if (elements.begin() == elements.end())
    {
        throw graphics_exception("Vertex elements list cannot be empty");
    }

    m_elements.insert(m_elements.end(), elements.begin(), elements.end());
    m_vertex_stride = calculate_offsets_and_get_vertex_stride(m_elements);

    try
    {
        validate_vertex_elements(m_vertex_stride, m_elements);
    }
    catch (...)
    {
        throw graphics_exception("Failed to validate vertex declaration");
    }
}

vertex_layout::vertex_layout(std::span<const vertex_element> elements) :
    m_vertex_stride(0)
{
    if (elements.empty())
    {
        throw graphics_exception("Vertex elements list cannot be empty");
    }

    m_elements.insert(m_elements.end(), elements.begin(), elements.end());
    m_vertex_stride = calculate_offsets_and_get_vertex_stride(m_elements);

    try
    {
        validate_vertex_elements(m_vertex_stride, m_elements);
    }
    catch (...)
    {
        throw graphics_exception("Failed to validate vertex declaration");
    }
}

vertex_layout::vertex_layout(size_t vertex_stride, const std::span<const vertex_element>& elements) :
    m_vertex_stride(vertex_stride)
{
    if (elements.empty())
    {
        throw graphics_exception("Vertex elements list cannot be empty");
    }

    m_elements.insert(m_elements.end(), elements.begin(), elements.end());

    try
    {
        validate_vertex_elements(m_vertex_stride, m_elements);
    }
    catch (...)
    {
        throw graphics_exception("Failed to validate vertex declaration");
    }
}

size_t vertex_layout::calculate_offsets_and_get_vertex_stride(const std::span<vertex_element>& elements)
{
    size_t stride = 0;

    if (elements.empty())
    {
        return stride;
    }

    for (size_t i = 0; i < elements.size(); i++)
    {
        auto& elem = elements[i];
        if (elem.offset == vertex_element::append_aligned)
        {
            elem.offset = stride;
            elements[i] = elem;
        }
        else
        {
            stride = elem.offset;
        }

        stride += format_size(elem.format);
    }

    return stride;
}

void vertex_layout::validate_vertex_elements(size_t vertex_stride, const std::span<const vertex_element>& elements)
{
    if (elements.empty())
    {
        throw graphics_exception("Vertex elements list cannot be empty");
    }

    if (vertex_stride <= 0)
    {
        throw graphics_exception("Vertex stride must be positive and non-zero");
    }

    // Ensure stride is a multiple of four
    if ((vertex_stride & 3) != 0)
    {
        throw graphics_exception("Vertex stride must be multiple of 4");
    }

    size_t expected_stride = 0;
    for (size_t i = 0; i < elements.size(); i++)
    {
        const auto& elem = elements[i];
        size_t offset = elem.offset;
        size_t elem_size = format_size(elem.format);

        // Ensure offset is a multiple of four
        if ((offset & 3) != 0)
        {
            throw graphics_exception("Vertex offset must be multiple of 4");
        }

        // Make sure the offset in the element doesnt put us out of range
        for (size_t j = 0; j < i; j++)
        {
            const auto& prev = elements[j];
            if (prev.semantic_name == elem.semantic_name && prev.semantic_index == elem.semantic_index)
            {
                throw graphics_exception("Duplicate vertex semantic");
            }
        }

        // Check for overlap between this element and the previous
        if ((expected_stride + elem_size) != (offset + elem_size))
        {
            throw graphics_exception("Vertex elements cannot overlap");
        }

        expected_stride = offset + elem_size;
    }
}