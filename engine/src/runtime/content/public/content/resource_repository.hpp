#pragma once

#include <string>
#include <memory>
#include <chrono>

#include "content/enums.hpp"

namespace openworld
{
    class resource_file;

    class resource_repository
    {
    public:
        virtual ~resource_repository() = 0;

        virtual std::string root_path() = 0;
        virtual bool is_open() = 0;
        virtual bool exists() = 0;
        virtual bool is_read_only() = 0;
        virtual std::chrono::system_clock::time_point creation_time() = 0;
        virtual std::chrono::system_clock::time_point last_access_time() = 0;

        void open_connection()
        {
            open_connection(resource_file_mode::open, resource_file_share::read);
        }

        void open_connection(resource_file_mode mode)
        {
            open_connection(mode, resource_file_share::none);
        }

        virtual void open_connection(resource_file_mode mode, resource_file_share share_mode) = 0;

        virtual void close_connection() = 0;

        virtual std::shared_ptr<resource_file> get_resource_file(const std::string& resource_name) = 0;
        virtual std::shared_ptr<resource_file> get_resource_file_relative_to(const std::string& resource_name, std::shared_ptr<resource_file> resource) = 0;

        virtual bool contains_resource(const std::string& resource_name) = 0;

        virtual std::string get_full_path(const std::string& resource_name) = 0;
        virtual std::string get_full_path_relative_to(const std::string& resource_name, std::shared_ptr<resource_file> resource) = 0;

        virtual void refresh() = 0;
    };
}