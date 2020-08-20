#pragma once

#define ENABLE_ENUM_BITWISE_OPERATORS(E, T)                             \
inline E operator | (const E& lhs, const E& rhs)                        \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) | static_cast<T>(rhs));   \
}                                                                       \
inline E operator & (const E& lhs, const E& rhs)                        \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) & static_cast<T>(rhs));   \
}                                                                       \
inline E operator ^ (const E& lhs, const E& rhs)                        \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) ^ static_cast<T>(rhs));   \
}                                                                       \
inline E operator << (const E& lhs, const uint8_t& rhs)                 \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) << rhs);                  \
}                                                                       \
inline E operator >> (const E& lhs, const uint8_t& rhs)                 \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) >> rhs);                  \
}                                                                       \
inline E operator ~ (const E& lhs)                                      \
{                                                                       \
    return static_cast<E>(~static_cast<T>(lhs));                        \
}                                                                       \
inline bool operator ! (const E& lhs)                                   \
{                                                                       \
    return lhs == E::Null;                                              \
}                                                                       \
inline E& operator |= (E& lhs, const E rhs)                             \
{                                                                       \
    lhs = lhs | rhs;                                                    \
    return lhs;                                                         \
}                                                                       \
inline E& operator &= (E& lhs, const E rhs)                             \
{                                                                       \
    lhs = lhs & rhs;                                                    \
    return lhs;                                                         \
}                                                                       \
inline E& operator ^= (E& lhs, const E rhs)                             \
{                                                                       \
    lhs = lhs ^ rhs;                                                    \
    return lhs;                                                         \
}

#define ENABLE_ENUM_BITWISE_COMPATIBILITY(E, E2, T)                     \
inline E operator | (const E& lhs, const E2& rhs)                       \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) | static_cast<T>(rhs));   \
}                                                                       \
inline E operator & (const E& lhs, const E2& rhs)                       \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) & static_cast<T>(rhs));   \
}                                                                       \
inline E operator ^ (const E& lhs, const E2& rhs)                       \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) ^ static_cast<T>(rhs));   \
}                                                                       \
inline E operator == (const E& lhs, const E2& rhs)                      \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) == static_cast<T>(rhs));  \
}                                                                       \
inline E operator != (const E& lhs, const E2& rhs)                      \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) != static_cast<T>(rhs));  \
}                                                                       \
inline E& operator |= (E& lhs, const E2 rhs)                            \
{                                                                       \
    lhs = lhs | rhs;                                                    \
    return lhs;                                                         \
}                                                                       \
inline E& operator &= (E& lhs, const E2 rhs)                            \
{                                                                       \
    lhs = lhs & rhs;                                                    \
    return lhs;                                                         \
}                                                                       \
inline E& operator ^= (E& lhs, const E2 rhs)                            \
{                                                                       \
    lhs = lhs ^ rhs;                                                    \
    return lhs;                                                         \
}

#define ENABLE_ENUM_PLUS_SHORTCUT(E, T)                                 \
inline T operator + (const E& lhs)                                      \
{                                                                       \
    return static_cast<T>(lhs);                                         \
}

#define ENABLE_ENUM_ARITHMETIC_OPERATIONS(E, T)                         \
inline E operator + (const E& lhs, const E& rhs)                        \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) + static_cast<T>(rhs));   \
}                                                                       \
inline E operator - (const E& lhs, const E& rhs)                        \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) - static_cast<T>(rhs));   \
}                                                                       \
inline E& operator ++ (E& lhs)                                          \
{                                                                       \
    return lhs = static_cast<E>(static_cast<T>(lhs) + 1);               \
}                                                                       \
inline E operator ++ (E& lhs, int)                                      \
{                                                                       \
    E result = lhs;                                                     \
    ++result;                                                           \
    return result;                                                      \
}                                                                       \
inline E& operator -- (E& lhs)                                          \
{                                                                       \
    return lhs = static_cast<E>(static_cast<T>(lhs) - 1);               \
}                                                                       \
inline E operator -- (E& lhs, int)                                      \
{                                                                       \
    E result = lhs;                                                     \
    --result;                                                           \
    return result;                                                      \
}                                                                       \
inline E& operator += (E& lhs, const E rhs)                             \
{                                                                       \
    return lhs = lhs + rhs;                                             \
}                                                                       \
inline E& operator -= (E& lhs, const E rhs)                             \
{                                                                       \
    return lhs = lhs - rhs;                                             \
}

#define ENABLE_ENUM_ARITHMETIC_COMPATIBILITY(E, E2, T)                  \
inline E operator + (const E& lhs, const E2& rhs)                       \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) + static_cast<T>(rhs));   \
}                                                                       \
inline E operator - (const E& lhs, const E2& rhs)                       \
{                                                                       \
    return static_cast<E>(static_cast<T>(lhs) - static_cast<T>(rhs));   \
}                                                                       \
inline bool operator > (const E& lhs, const E2& rhs)                    \
{                                                                       \
    return static_cast<T>(lhs) > static_cast<T>(rhs);                   \
}                                                                       \
inline bool operator >= (const E& lhs, const E2& rhs)                   \
{                                                                       \
    return static_cast<T>(lhs) >= static_cast<T>(rhs);                  \
}                                                                       \
inline bool operator < (const E& lhs, const E2& rhs)                    \
{                                                                       \
    return static_cast<T>(lhs) < static_cast<T>(rhs);                   \
}                                                                       \
inline bool operator <= (const E& lhs, const E2& rhs)                   \
{                                                                       \
    return static_cast<T>(lhs) <= static_cast<T>(rhs);                  \
}                                                                       \
inline bool operator == (const E& lhs, const E2& rhs)                   \
{                                                                       \
    return static_cast<T>(lhs) == static_cast<T>(rhs);                  \
}                                                                       \
inline bool operator != (const E& lhs, const E2& rhs)                   \
{                                                                       \
    return static_cast<T>(lhs) != static_cast<T>(rhs);                  \
}                                                                       \
inline E& operator += (E& lhs, const E2 rhs)                            \
{                                                                       \
    return lhs = lhs + rhs;                                             \
}                                                                       \
inline E& operator -= (E& lhs, const E2 rhs)                            \
{                                                                       \
    return lhs = lhs - rhs;                                             \
}
