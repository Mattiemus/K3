#pragma once

#include <string>
#include <memory>
#include <chrono>

#include "content/enums.hpp"
#include "content/resource_stream.hpp"

namespace openworld
{
    class resource_repository;

    class resource_file
    {
    public:
        virtual ~resource_file() = 0;

        virtual std::string name() = 0;
        virtual std::string extension() = 0;
        virtual std::string full_name() = 0;
        virtual bool exists() = 0;
        virtual bool is_read_only() = 0;
        virtual std::chrono::system_clock::time_point creation_time() = 0;
        virtual std::chrono::system_clock::time_point last_access_time() = 0;
        virtual std::shared_ptr<resource_repository> repository() = 0;

        std::shared_ptr<resource_stream> open()
        {
            return open(resource_file_mode::open, resource_file_access::read, resource_file_share::read);
        }

        std::shared_ptr<resource_stream> open(resource_file_mode file_mode)
        {
            return open(file_mode, resource_file_access::read, resource_file_share::read);
        }

        std::shared_ptr<resource_stream> open(resource_file_mode file_mode, resource_file_access access_mode)
        {
            return open(file_mode, access_mode, resource_file_share::read);
        }

        virtual std::shared_ptr<resource_stream> open(resource_file_mode file_mode,
                                                      resource_file_access access_mode,
                                                      resource_file_share file_share) = 0;

        std::shared_ptr<resource_stream> open_write()
        {
            return open(resource_file_mode::create, resource_file_access::write, resource_file_share::none);
        }

        std::shared_ptr<resource_stream> open_read()
        {
            return open(resource_file_mode::open, resource_file_access::read, resource_file_share::read);
        }

        virtual std::shared_ptr<resource_stream> create() = 0;
        virtual void delete_file() = 0;
        virtual void refresh() = 0;
    };
}