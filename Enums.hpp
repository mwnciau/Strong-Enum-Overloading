#pragma once

#include "Classes.hpp"
#include "Macros.hpp"

template <typename ValueType, typename Enumeration>
class ConstClassEnumeratedArray
{
    const ValueType* _value;
public:
    ConstClassEnumeratedArray(const ValueType* value)
    {
        _value = value;
    }
    inline const ValueType& operator[] (const IndexEnum<Enumeration>& index) const
    {
        return _value[+index];
    }
    // Ideally, this wouldn't be used as it removes the type protection of using strong enums
    inline const ValueType& operator[] (const size_t index) const
    {
        return _value[index];
    }
};
template <typename ValueType, typename Enumeration>
class ConstEnumeratedArray
{
    const ValueType* _value;
public:
    ConstEnumeratedArray(const ValueType* value)
    {
        _value = value;
    }
    inline const ValueType& operator[] (const Enumeration& index) const
    {
        return _value[static_cast<size_t>(index)];
    }
    // Ideally, this wouldn't be used as it removes the type protection of using strong enums
    inline const ValueType& operator[] (const size_t index) const
    {
        return _value[index];
    }
};

template <typename ValueType, typename Enumeration>
class EnumeratedArray
{
    ValueType* _value;
public:
    EnumeratedArray(ValueType* value)
    {
        _value = value;
    }
    inline ValueType& operator[] (const Enumeration& index) const
    {
        return _value[static_cast<size_t>(index)];
    }
    // Ideally, this wouldn't be used as it removes the type protection of using strong enums
    inline ValueType& operator[] (const size_t index) const
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
#define ENABLE_ENUM_FLAG FlagExample
#define ENABLE_ENUM_FLAG_OTHER FlagExample2
#include "Enum.hxx"

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
#define ENABLE_ENUM_FLAG FlagExample2
#define ENABLE_ENUM_FLAG_OTHER uint32_t
#include "Enum.hxx"

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
#define ENABLE_ENUM_INDEX LowercaseLetterIndex
#define ENABLE_ENUM_INDEX_OTHER UppercaseLetterIndex
#include "Enum.hxx"

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
#define ENABLE_ENUM_INDEX UppercaseLetterIndex
#define ENABLE_ENUM_INDEX_OTHER uint32_t
#include "Enum.hxx"

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
const ConstEnumeratedArray<char, UppercaseLetterIndex> UppercaseLetters(_UppercaseLetters);

static char _LowercaseLettersNonConst[] = {
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
const EnumeratedArray<char, LowercaseLetterIndex> LowercaseLettersNonConst(_LowercaseLettersNonConst);

namespace ConstexprLowercaseLetterIndex
{
    constexpr uint32_t Init = 0;
    constexpr uint32_t LetterA = 0;
    constexpr uint32_t LetterB = 1;
    constexpr uint32_t LetterC = 2;
    constexpr uint32_t LetterD = 3;
    constexpr uint32_t LetterE = 4;
    constexpr uint32_t LetterF = 5;
    constexpr uint32_t LetterG = 6;
    constexpr uint32_t LetterH = 7;
    constexpr uint32_t LetterI = 8;
    constexpr uint32_t LetterJ = 9;
    constexpr uint32_t LetterK = 10;
    constexpr uint32_t LetterL = 11;
    constexpr uint32_t LetterM = 12;
    constexpr uint32_t LetterN = 13;
    constexpr uint32_t LetterO = 14;
    constexpr uint32_t LetterP = 15;
    constexpr uint32_t LetterQ = 16;
    constexpr uint32_t LetterR = 17;
    constexpr uint32_t LetterS = 18;
    constexpr uint32_t LetterT = 19;
    constexpr uint32_t LetterU = 20;
    constexpr uint32_t LetterV = 21;
    constexpr uint32_t LetterW = 22;
    constexpr uint32_t LetterX = 23;
    constexpr uint32_t LetterY = 24;
    constexpr uint32_t LetterZ = 25;
    constexpr uint32_t Count = 26;
};

enum class ClassFlagExample : uint32_t
{
    Null = 0,
    Flag1 = 1,
    Flag2 = 2,
    Flag4 = 4,
    Flag8 = 8,
    Flag16 = 16
};
using ClassFlagExample_t = FlagEnum<ClassFlagExample>;

enum class ClassUppercaseLetterIndex : uint32_t
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
using ClassUppercaseLetterIndex_t = IndexEnum<ClassUppercaseLetterIndex>;
const ConstClassEnumeratedArray<char, ClassUppercaseLetterIndex> ClassUppercaseLetters(_UppercaseLetters);