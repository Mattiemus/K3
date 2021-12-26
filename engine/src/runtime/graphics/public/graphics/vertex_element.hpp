#pragma once

#include "graphics/enums.hpp"

namespace openworld
{
    class vertex_element final
    {
    public:
        static constexpr size_t append_aligned = -1;

        vertex_semantic semantic_name;
        size_t semantic_index;
        vertex_format format;
        size_t offset;

        constexpr vertex_element(
            vertex_semantic semantic,
            size_t semantic_index,
            vertex_format format,
            size_t offset) noexcept :
            semantic_name(semantic),
            semantic_index(semantic_index),
            format(format),
            offset(offset)
        {}

        constexpr vertex_element(
            vertex_semantic semantic,
            size_t semantic_index,
            vertex_format format) noexcept :
            semantic_name(semantic),
            semantic_index(semantic_index),
            format(format),
            offset(append_aligned)
        {}
    };

    constexpr bool operator ==(
        const vertex_element& lhs, 
        const vertex_element& rhs) noexcept
    {
        return (lhs.semantic_name == rhs.semantic_name) && 
            (lhs.semantic_index == rhs.semantic_index) && 
            (lhs.offset == rhs.offset) &&
            (lhs.format == rhs.format);
    }

    constexpr bool operator !=(
        const vertex_element& lhs,
        const vertex_element& rhs) noexcept
    {
        return (lhs.semantic_name != rhs.semantic_name) ||
            (lhs.semantic_index != rhs.semantic_index) ||
            (lhs.offset != rhs.offset) ||
            (lhs.format != rhs.format);
    }
}