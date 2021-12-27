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

        constexpr vertex_buffer_binding(vertex_buffer& buffer) noexcept :
            buffer(buffer),
            vertex_offset(0),
            instance_frequency(0)
        {
        }

        constexpr vertex_buffer_binding(
            vertex_buffer& buffer,
            size_t vertex_offset) noexcept :
            buffer(buffer),
            vertex_offset(vertex_offset),
            instance_frequency(0)
        {
        }

        constexpr vertex_buffer_binding(
            vertex_buffer& buffer,
            size_t vertex_offset,
            size_t instance_frequency) noexcept :
            buffer(buffer),
            vertex_offset(vertex_offset),
            instance_frequency(instance_frequency)
        {
        }
	};

    constexpr bool operator ==(
        const vertex_buffer_binding& lhs,
        const vertex_buffer_binding& rhs) noexcept
    {
        return (lhs.buffer == rhs.buffer) &&
            (lhs.vertex_offset == rhs.vertex_offset) &&
            (lhs.instance_frequency == rhs.instance_frequency);
    }

    constexpr bool operator !=(
        const vertex_buffer_binding& lhs,
        const vertex_buffer_binding& rhs) noexcept
    {
        return (lhs.buffer != rhs.buffer) ||
            (lhs.vertex_offset != rhs.vertex_offset) ||
            (lhs.instance_frequency != rhs.instance_frequency);
    }
}