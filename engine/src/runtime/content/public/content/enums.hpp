#pragma once

namespace openworld
{
    enum class resource_file_mode
    {
        create_new = 1,
        create = 2,
        open = 3,
        open_or_create = 4
    };

    enum class resource_file_access
    {
        read = 1,
        write = 2,
        read_write = 3
    };

    enum class resource_file_share
    {
        none = 0,
        read = 1,
        write = 2,
        read_write = 3,
        destroy = 4
    };
}