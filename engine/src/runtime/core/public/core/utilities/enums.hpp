#pragma once

#include <type_traits>

#define OPENWORLD_DEFINE_ENUM_FLAG_OPERATORS(ENUM) \
    constexpr ENUM operator|(ENUM lhs, ENUM rhs) \
    { \
        return static_cast<ENUM>(static_cast<std::underlying_type_t<ENUM>>(lhs) | static_cast<std::underlying_type_t<ENUM>>(rhs)); \
    } \
    constexpr ENUM operator&(ENUM lhs, ENUM rhs) \
    { \
        return static_cast<ENUM>(static_cast<std::underlying_type_t<ENUM>>(lhs) & static_cast<std::underlying_type_t<ENUM>>(rhs)); \
    } \
    constexpr bool has_flag(ENUM value, ENUM flag) { return (value & flag) == flag; }
