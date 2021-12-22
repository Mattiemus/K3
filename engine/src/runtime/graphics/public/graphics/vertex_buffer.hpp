#pragma once

#include <span>

#include "graphics/enums.hpp"

namespace openworld
{
    class render_context;
    enum class data_write_options;

	class vertex_buffer
	{
	public:
        virtual ~vertex_buffer() = 0 {};

        virtual void get_data(
            const std::span<std::byte>& data,
            size_t element_count,
            size_t element_size,
            size_t read_start_offset,
            size_t vertex_stride) = 0;

        virtual void set_data(
            render_context& render_ctx,
            const std::span<const std::byte>& data,
            size_t element_count,
            size_t element_size,
            size_t write_start_offset,
            size_t vertex_stride,
            data_write_options write_opts) = 0;
	};
}