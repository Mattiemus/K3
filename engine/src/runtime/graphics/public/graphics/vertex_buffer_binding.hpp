#pragma once

namespace openworld
{
    class vertex_buffer;

	class vertex_buffer_binding final
	{
	public:
		vertex_buffer& buffer;
		size_t vertex_offset;
		size_t instance_frequency;

        constexpr explicit vertex_buffer_binding(vertex_buffer& buffer) :
            buffer(buffer),
            vertex_offset(0),
            instance_frequency(0)
        {
        }

        constexpr vertex_buffer_binding(
            vertex_buffer& buffer,
            size_t vertex_offset) :
            buffer(buffer),
            vertex_offset(vertex_offset),
            instance_frequency(0)
        {
        }

        constexpr vertex_buffer_binding(
            vertex_buffer& buffer,
            size_t vertex_offset,
            size_t instance_frequency) :
            buffer(buffer),
            vertex_offset(vertex_offset),
            instance_frequency(instance_frequency)
        {
        }
	};

    constexpr bool operator ==(
        const vertex_buffer_binding& lhs,
        const vertex_buffer_binding& rhs)
    {
        return (std::addressof(lhs.buffer) == std::addressof(rhs.buffer)) &&
            (lhs.vertex_offset == rhs.vertex_offset) &&
            (lhs.instance_frequency == rhs.instance_frequency);
    }

    constexpr bool operator !=(
        const vertex_buffer_binding& lhs,
        const vertex_buffer_binding& rhs)
    {
        return (std::addressof(lhs.buffer) != std::addressof(rhs.buffer)) ||
            (lhs.vertex_offset != rhs.vertex_offset) ||
            (lhs.instance_frequency != rhs.instance_frequency);
    }
}