#pragma once

#include "Macros.hpp"

template <typename ValueType, typename Enumeration>
class EnumeratedArray
{
    const ValueType* _value;
public:
    EnumeratedArray(const ValueType* value)
    {
        _value = value;
    }
    inline const ValueType& operator[] (const Enumeration& index) const
    {
        return _value[static_cast<size_t>(index)];
    }
    inline const ValueType& operator[] (const size_t index) const
    {
        return _value[index];
    }
};

enum class FlagExample : uint32_t;
enum CEnumFlagExample : uint32_t;
enum class FlagExample2 : uint32_t;
enum class LowercaseLetterIndex : uint32_t;
enum CEnumLowercaseLetterIndex : uint32_t;
enum class UppercaseLetterIndex : uint32_t;

enum class FlagExample : uint32_t
{
    Null = 0,
    Flag1 = 1,
    Flag2 = 2,
    Flag4 = 4,
    Flag8 = 8,
    Flag16 = 16
};
ENABLE_ENUM_BITWISE_OPERATORS(FlagExample, uint32_t);
ENABLE_ENUM_BITWISE_COMPATIBILITY(FlagExample, FlagExample2, uint32_t);
ENABLE_ENUM_PLUS_SHORTCUT(FlagExample, uint32_t);

enum CEnumFlagExample : uint32_t
{
    Null = 0,
    Flag1 = 1,
    Flag2 = 2,
    Flag4 = 4,
    Flag8 = 8,
    Flag16 = 16
};

enum class FlagExample2 : uint32_t
{
    Null = 0,
    Flag1 = 1,
    Flag2 = 2,
    Flag4 = 4,
    Flag8 = 8,
    Flag16 = 16
};
ENABLE_ENUM_BITWISE_OPERATORS(FlagExample2, uint32_t);
ENABLE_ENUM_BITWISE_COMPATIBILITY(FlagExample2, uint32_t, uint32_t);
ENABLE_ENUM_PLUS_SHORTCUT(FlagExample2, uint32_t);

enum class LowercaseLetterIndex : uint32_t
{
    Init,
    LetterA = 0,
    LetterB,
    LetterC,
    LetterD,
    LetterE,
    LetterF,
    LetterG,
    LetterH,
    LetterI,
    LetterJ,
    LetterK,
    LetterL,
    LetterM,
    LetterN,
    LetterO,
    LetterP,
    LetterQ,
    LetterR,
    LetterS,
    LetterT,
    LetterU,
    LetterV,
    LetterW,
    LetterX,
    LetterY,
    LetterZ,
    Count
};
ENABLE_ENUM_ARITHMETIC_OPERATIONS(LowercaseLetterIndex, uint32_t);
ENABLE_ENUM_ARITHMETIC_COMPATIBILITY(LowercaseLetterIndex, UppercaseLetterIndex, uint32_t);
ENABLE_ENUM_PLUS_SHORTCUT(LowercaseLetterIndex, uint32_t);

enum CEnumLowercaseLetterIndex : uint32_t
{
    Init,
    LetterA = 0,
    LetterB,
    LetterC,
    LetterD,
    LetterE,
    LetterF,
    LetterG,
    LetterH,
    LetterI,
    LetterJ,
    LetterK,
    LetterL,
    LetterM,
    LetterN,
    LetterO,
    LetterP,
    LetterQ,
    LetterR,
    LetterS,
    LetterT,
    LetterU,
    LetterV,
    LetterW,
    LetterX,
    LetterY,
    LetterZ,
    Count
};

static constexpr const char LowercaseLetters[] = {
    'a',
    'b',
    'c',
    'd',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
};


enum class UppercaseLetterIndex : uint32_t
{
    Init,
    LetterA = 0,
    LetterB,
    LetterC,
    LetterD,
    LetterE,
    LetterF,
    LetterG,
    LetterH,
    LetterI,
    LetterJ,
    LetterK,
    LetterL,
    LetterM,
    LetterN,
    LetterO,
    LetterP,
    LetterQ,
    LetterR,
    LetterS,
    LetterT,
    LetterU,
    LetterV,
    LetterW,
    LetterX,
    LetterY,
    LetterZ,
    Count
};
ENABLE_ENUM_ARITHMETIC_OPERATIONS(UppercaseLetterIndex, uint32_t);
ENABLE_ENUM_ARITHMETIC_COMPATIBILITY(UppercaseLetterIndex, uint32_t, uint32_t);
ENABLE_ENUM_PLUS_SHORTCUT(UppercaseLetterIndex, uint32_t);

static constexpr const char _UppercaseLetters[] = {
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
};
const EnumeratedArray<char, UppercaseLetterIndex> UppercaseLetters(_UppercaseLetters);
