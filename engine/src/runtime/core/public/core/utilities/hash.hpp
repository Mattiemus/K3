#pragma once

namespace openworld
{
    inline void hash_combine(std::size_t& seed)
    {}

    template <typename T, typename... Rest>
    inline void hash_combine(std::size_t& seed, const T& v, Rest... rest)
    {
        std::hash<T> hasher{};
        seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        hash_combine(seed, rest...);
    }
}

#define OPENWORLD_DEFINE_STD_HASH(TYPE, ...) \
    namespace std\
    {\
        template<>\
           struct hash<TYPE> {\
            std::size_t operator()(const TYPE& x) const {\
                std::size_t ret = 0;\
                ::openworld::hash_combine(ret, __VA_ARGS__);\
                return ret;\
            }\
        };\
    }