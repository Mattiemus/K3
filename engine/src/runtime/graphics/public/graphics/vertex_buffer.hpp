#pragma once

#include <span>

#include "graphics/enums.hpp"
#include "graphics/vertex_layout.hpp"

namespace openworld
{
	class vertex_buffer final
	{
	public:
        vertex_buffer(const vertex_layout& layout, size_t vertex_count);
        vertex_buffer(const vertex_layout& layout, size_t vertex_count, resource_usage usage);
        vertex_buffer(const vertex_layout& layout, const std::span<const std::byte>& data);
        vertex_buffer(const vertex_layout& layout, const std::span<const std::byte>& data, resource_usage usage);
        vertex_buffer(const vertex_layout& layout, const std::span<const std::span<const std::byte>>& data);
        vertex_buffer(const vertex_layout& layout, const std::span<const std::span<const std::byte>>& data, resource_usage usage);
        vertex_buffer(const vertex_buffer&) = delete;
        vertex_buffer(vertex_buffer&& other) noexcept :
            m_pimpl(other.m_pimpl),
            m_vertex_layout(std::move(other.m_vertex_layout)),
            m_vertex_count(other.m_vertex_count),
            m_resource_usage(other.m_resource_usage)
        {
            other.m_pimpl = nullptr;
        }
        ~vertex_buffer();

        vertex_buffer& operator =(const vertex_buffer&) = delete;
        vertex_buffer& operator =(vertex_buffer&& other) noexcept
        {
            m_pimpl = other.m_pimpl;
            other.m_pimpl = nullptr;
            return *this;
        }

        constexpr void* pimpl() const noexcept
        {
            return m_pimpl;
        }

        constexpr const vertex_layout& layout() const
        {
            return m_vertex_layout;
        }

        constexpr size_t vertex_count() const
        {
            return m_vertex_count;
        }

        constexpr resource_usage usage() const
        {
            return m_resource_usage;
        }

        void get_data(
            const std::span<std::byte>& data,
            size_t element_count,
            size_t element_size,
            size_t read_start_offset,
            size_t vertex_stride);

        template <typename Element>
        void get_data(
            const std::span<Element>& data,
            size_t vertex_stride)
        {
            get_data(
                std::as_bytes(data),
                data.size(),
                sizeof(Element),
                0,
                vertex_stride);
        }

        void set_data(
            render_context& render_ctx,
            const std::span<const std::byte>& data,
            size_t element_count,
            size_t element_size,
            size_t write_start_offset,
            size_t vertex_stride,
            data_write_options write_opts);

        template <typename Element>
        void set_data(
            render_context& render_ctx,
            const std::span<const Element>& data,
            size_t vertex_stride,
            data_write_options write_opts)
        {
            set_data(
                render_ctx,
                std::as_bytes(data),
                data.size(),
                sizeof(Element),
                0,
                vertex_stride,
                write_opts);
        }

    private:
        void* m_pimpl = nullptr;
        vertex_layout m_vertex_layout;
        size_t m_vertex_count;
        resource_usage m_resource_usage;
	};
}