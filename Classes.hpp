#pragma once

#include "Enums.hpp"

template<class C, typename T>
struct ClassEnum
{
protected:
    T _value;

    constexpr ClassEnum() = default;
};

template<class C, typename T>
struct FlagEnum : ClassEnum<C, T>
{
protected:
    friend C;
    constexpr FlagEnum(const T& value) : ClassEnum<C, T>()
    {
        this->_value = value;
    };

public:
    constexpr FlagEnum(const FlagEnum<C, T>& other) : ClassEnum<C, T>()
    {
        this->_value = other._value;
    };
    constexpr FlagEnum(volatile const FlagEnum<C, T>& other) : ClassEnum<C, T>()
    {
        this->_value = other._value;
    };


    constexpr FlagEnum<C, T>& operator = (const FlagEnum<C, T>& rhs)
    {
        this->_value = rhs._value;
        return *this;
    }

    constexpr FlagEnum<C, T> operator | (const FlagEnum<C, T>& rhs) const
    {
        return FlagEnum<C, T>( this->_value | rhs._value );
    }

    constexpr FlagEnum<C, T> operator & (const FlagEnum<C, T>& rhs) const
    {
        return FlagEnum<C, T>(this->_value & rhs._value);
    }

    constexpr FlagEnum<C, T> operator ^ (const FlagEnum<C, T>& rhs) const
    {
        return FlagEnum<C, T>(this->_value ^ rhs._value);
    }

    constexpr bool operator == (const FlagEnum<C, T>& rhs) const
    {
        return this->_value == rhs._value;
    }

    constexpr bool operator != (const FlagEnum<C, T>& rhs) const
    {
        return this->_value != rhs._value;
    }

    constexpr FlagEnum<C, T> operator << (const uint8_t rhs) const
    {
        return FlagEnum<C, T>(this->_value << rhs);
    }
    constexpr FlagEnum<C, T> operator >> (const uint8_t rhs) const
    {
        return FlagEnum<C, T>(this->_value >> rhs);
    }

    constexpr FlagEnum<C, T>& operator |= (const FlagEnum<C, T> rhs)
    {
        this->_value = this->_value | rhs._value;
        return *this;
    }

    constexpr FlagEnum<C, T>& operator &= (const FlagEnum<C, T> rhs)
    {
        this->_value = this->_value & rhs._value;
        return *this;
    }

    constexpr FlagEnum<C, T>& operator ^= (const FlagEnum<C, T> rhs)
    {
        this->_value = this->_value ^ rhs._value;
        return *this;
    }

    constexpr T operator + () const
    {
        return this->_value;
    }

    constexpr FlagEnum<C, T> operator ~ () const
    {
        return FlagEnum<C, T>(~this->_value);
    }

    constexpr bool operator ! () const
    {
        return this->_value == 0;
    }
};


template<class C, typename T>
struct IndexEnum : ClassEnum<C, T>
{
protected:
    friend C;
    constexpr IndexEnum(const T& value) : ClassEnum<C, T>()
    {
        this->_value = value;
    };

public:
    constexpr IndexEnum(const IndexEnum<C, T>& other) : ClassEnum<C, T>()
    {
        this->_value = other._value;
    };
    constexpr IndexEnum(volatile const IndexEnum<C, T>& other) : ClassEnum<C, T>()
    {
        this->_value = other._value;
    };


    constexpr IndexEnum<C, T>& operator = (const IndexEnum<C, T>& rhs)
    {
        this->_value = rhs._value;
        return *this;
    }

    constexpr IndexEnum<C, T>& operator = (volatile const IndexEnum<C, T>& rhs)
    {
        this->_value = rhs;
        return *this;
    }

    constexpr IndexEnum<C, T> operator + (const IndexEnum<C, T>& rhs) const
    {
        return IndexEnum<C, T>(this->_value + rhs._value);
    }

    constexpr IndexEnum<C, T> operator - (const IndexEnum<C, T>& rhs) const
    {
        return IndexEnum<C, T>(this->_value - rhs._value);
    }

    constexpr bool operator == (const IndexEnum<C, T>& rhs) const
    {
        return this->_value == rhs._value;
    }

    constexpr bool operator != (const IndexEnum<C, T>& rhs) const
    {
        return this->_value != rhs._value;
    }

    constexpr IndexEnum<C, T>& operator += (const IndexEnum<C, T>& rhs)
    {
        this->_value = this->_value + rhs;
        return *this;
    }

    constexpr IndexEnum<C, T>& operator -= (const IndexEnum<C, T>& rhs)
    {
        this->_value = this->_value - rhs;
        return *this;
    }

    constexpr bool operator > (const IndexEnum<C, T>& rhs) const
    {
        return this->_value > rhs._value;
    }

    constexpr bool operator < (const IndexEnum<C, T>& rhs) const
    {
        return this->_value < rhs._value;
    }

    constexpr bool operator >= (const IndexEnum<C, T>& rhs) const
    {
        return this->_value >= rhs._value;
    }

    constexpr bool operator <= (const IndexEnum<C, T>& rhs) const
    {
        return this->_value <= rhs._value;
    }


    constexpr T operator + () const
    {
        return this->_value;
    }

    constexpr IndexEnum<C, T>& operator ++ ()
    {
        this->_value++;
        return *this;
    }

    constexpr IndexEnum<C, T> operator ++ (int)
    {
        IndexEnum<C, T> result = *this;
        ++(*this);
        return result;
    }

    constexpr IndexEnum<C, T>& operator -- ()
    {
        this->_value--;
        return *this;
    }

    constexpr IndexEnum<C, T> operator -- (int)
    {
        IndexEnum<C, T> result = *this;
        --(*this);
        return result;
    }
};

template <typename ValueType, typename Enumeration>
class ConstClassEnumeratedArray
{
    const ValueType* _value;
public:
    constexpr ConstClassEnumeratedArray(const ValueType* value)
    {
        _value = value;
    }
    constexpr const ValueType& operator[] (const Enumeration& index) const
    {
        return _value[+index];
    }
    // Ideally, this wouldn't be used as it removes the type protection of using strong enums
    constexpr const ValueType& operator[] (const size_t index) const
    {
        return _value[index];
    }
};


// Examples



struct ClassUppercaseLetterIndex
{
    using Type = IndexEnum< ClassUppercaseLetterIndex, uint32_t >;

    static constexpr Type Init = { 0 };
    static constexpr Type LetterA = { 0 };
    static constexpr Type LetterB = { 1 };
    static constexpr Type LetterC = { 2 };
    static constexpr Type LetterD = { 3 };
    static constexpr Type LetterE = { 4 };
    static constexpr Type LetterF = { 5 };
    static constexpr Type LetterG = { 6 };
    static constexpr Type LetterH = { 7 };
    static constexpr Type LetterI = { 8 };
    static constexpr Type LetterJ = { 9 };
    static constexpr Type LetterK = { 10 };
    static constexpr Type LetterL = { 11 };
    static constexpr Type LetterM = { 12 };
    static constexpr Type LetterN = { 13 };
    static constexpr Type LetterO = { 14 };
    static constexpr Type LetterP = { 15 };
    static constexpr Type LetterQ = { 16 };
    static constexpr Type LetterR = { 17 };
    static constexpr Type LetterS = { 18 };
    static constexpr Type LetterT = { 19 };
    static constexpr Type LetterU = { 20 };
    static constexpr Type LetterV = { 21 };
    static constexpr Type LetterW = { 22 };
    static constexpr Type LetterX = { 23 };
    static constexpr Type LetterY = { 24 };
    static constexpr Type LetterZ = { 25 };
    static constexpr Type Count = { 26 };
};

const ConstClassEnumeratedArray<char, ClassUppercaseLetterIndex::Type> ClassUppercaseLetters{ _UppercaseLetters };

struct ClassFlagExample
{
    using Type = FlagEnum<ClassFlagExample, uint32_t>;

    static constexpr Type Null = { 0 };
    static constexpr Type Flag1 = { 1 };
    static constexpr Type Flag2 = { 2 };
    static constexpr Type Flag4 = { 4 };
    static constexpr Type Flag8 = { 8 };
    static constexpr Type Flag16 = { 16 };
};