#pragma once

template<typename T>
struct CRTPEnumBase
{
    constexpr CRTPEnumBase() = default;

    template<typename W, typename X>
    friend struct CRTPFlagEnumUnaryOperators;

    template<typename W, typename X, typename Y, typename ... Z>
    friend struct CRTPFlagEnumBinaryOperators;

    template<typename W, typename X>
    friend struct CRTPIndexEnumUnaryOperators;

    template<typename W, typename X, typename Y, typename ... Z>
    friend struct CRTPIndexEnumBinaryOperators;

protected:
    T _value;
};


template<class C, typename T>
struct CRTPIndexEnumUnaryOperators : CRTPEnumBase<T>
{
    constexpr T operator + () const
    {
        return this->_value;
    }

    constexpr const C operator ++ ()
    {
        this->_value = this->_value + 1;
        return C(this->_value);
    }
    constexpr const C operator ++ (int)
    {
        C result = C(*this);
        ++(*this);
        return result;
    }

    constexpr const C operator -- ()
    {
        this->_value = static_cast<T>(static_cast<typename std::underlying_type<T>::type>(this->_value) - 1);
        return C(this->_value);
    }
    constexpr const C operator -- (int)
    {
        C result = C(*this);
        --(*this);
        return result;
    }
};


template<class C, typename T, typename T2, typename ... Types>
struct CRTPIndexEnumBinaryOperators : CRTPIndexEnumBinaryOperators<C, T, Types ...>
{
    constexpr CRTPIndexEnumBinaryOperators() = default;

    // So we don't hide any of our ancestor's operators
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator=;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator+;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator-;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator+=;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator-=;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator>;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator<;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator>=;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator<=;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator==;
    using CRTPIndexEnumBinaryOperators<C, T, Types ...>::operator!=;

    constexpr const C operator = (const typename T2::Type& other)
    {
        this->_value = other._value;
        return C(this->_value);
    }

    constexpr C operator + (const typename T2::Type& other) const
    {
        return C(this->_value + other._value);
    }

    constexpr C operator - (const typename T2::Type& other) const
    {
        return C(this->_value - other._value);
    }

    constexpr const C operator += (const typename T2::Type& other)
    {
        this->_value += other._value;
        return C(this->_value);
    }

    constexpr const C operator -= (const typename T2::Type& other)
    {
        this->_value -= other._value;
        return C(this->_value);
    }

    constexpr bool operator > (const typename T2::Type& other) const
    {
        return this->_value > other._value;
    }

    constexpr bool operator < (const typename T2::Type& other) const
    {
        return this->_value < other._value;
    }

    constexpr bool operator >= (const typename T2::Type& other) const
    {
        return this->_value >= other._value;
    }

    constexpr bool operator <= (const typename T2::Type& other) const
    {
        return this->_value <= other._value;
    }

    constexpr bool operator == (const typename T2::Type& other) const
    {
        return this->_value == other._value;
    }

    constexpr bool operator != (const typename T2::Type& other) const
    {
        return this->_value != other._value;
    }
};
template<class C, typename T, typename T2>
struct CRTPIndexEnumBinaryOperators<C, T, T2> : CRTPIndexEnumUnaryOperators<C, T>
{
    constexpr CRTPIndexEnumBinaryOperators() = default;

    // So we don't hide any of our ancestor's operators
    using CRTPIndexEnumUnaryOperators<C, T>::operator+;

    constexpr const C operator = (const typename T2::Type& other)
    {
        this->_value = other._value;
        return C(this->_value);
    }

    constexpr C operator + (const typename T2::Type& other) const
    {
        return C(this->_value + other._value);
    }

    constexpr C operator - (const typename T2::Type& other) const
    {
        return C(this->_value - other._value);
    }

    constexpr const C operator += (const typename T2::Type& other)
    {
        this->_value += other._value;
        return C(this->_value);
    }

    constexpr const C operator -= (const typename T2::Type& other)
    {
        this->_value -= other._value;
        return C(this->_value);
    }

    constexpr bool operator > (const typename T2::Type& other) const
    {
        return this->_value > other._value;
    }

    constexpr bool operator < (const typename T2::Type& other) const
    {
        return this->_value < other._value;
    }

    constexpr bool operator >= (const typename T2::Type& other) const
    {
        return this->_value >= other._value;
    }

    constexpr bool operator <= (const typename T2::Type& other) const
    {
        return this->_value <= other._value;
    }

    constexpr bool operator == (const typename T2::Type& other) const
    {
        return this->_value == other._value;
    }

    constexpr bool operator != (const typename T2::Type& other) const
    {
        return this->_value != other._value;
    }
};

template<class C, typename T, typename ... Types>
struct CRTPIndexEnum : CRTPIndexEnumBinaryOperators<CRTPIndexEnum<C, T, Types...>, T, C, Types...>
{
    constexpr CRTPIndexEnum()
        : CRTPIndexEnumBinaryOperators<CRTPIndexEnum<C, T, Types...>, T, C, Types...>()
    {
        this->_value = 0;
    };
    constexpr CRTPIndexEnum(const typename C::Type& other)
        : CRTPIndexEnumBinaryOperators<CRTPIndexEnum<C, T, Types...>, T, C, Types...>()
    {
        this->_value = other._value;
    };
    constexpr CRTPIndexEnum(volatile const typename C::Type& other)
        : CRTPIndexEnumBinaryOperators<CRTPIndexEnum<C, T, Types...>, T, C, Types...>()
    {
        this->_value = other._value;
    };

protected:
    friend C;

    template<typename W, typename X>
    friend struct CRTPIndexEnumUnaryOperators;

    template<typename W, typename X, typename Y, typename ... Z>
    friend struct CRTPIndexEnumBinaryOperators;

    constexpr CRTPIndexEnum(const T& value)
        : CRTPIndexEnumBinaryOperators<CRTPIndexEnum<C, T, Types...>, T, C, Types...>()
    {
        this->_value = value;
    }
};


template<class C, typename T>
struct CRTPFlagEnumUnaryOperators : CRTPEnumBase<T>
{
    constexpr CRTPFlagEnumUnaryOperators() = default;

    constexpr T operator + () const
    {
        return this->_value;
    }
    constexpr C operator ~ () const
    {
        return C(~this->_value);
    }
    constexpr T operator ! () const
    {
        return this->_value == 0;
    }
    constexpr const C operator << (const uint8_t& other) const
    {
        return C(this->_value << other);
    }
    constexpr const C operator >> (const uint8_t& other) const
    {
        return C(this->_value >> other);
    }
};


template<class C, typename T, typename T2, typename ... Types>
struct CRTPFlagEnumBinaryOperators : CRTPFlagEnumBinaryOperators<C, T, Types...>
{
    constexpr CRTPFlagEnumBinaryOperators() = default;

    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator=;
    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator&;
    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator|;
    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator^;
    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator&=;
    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator|=;
    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator^=;
    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator==;
    using CRTPFlagEnumBinaryOperators<C, T, Types...>::operator!=;

    constexpr const C operator = (const typename T2::Type& other)
    {
        this->_value = other._value;
        return C(this->_value);
    }

    constexpr C operator & (const typename T2::Type& other) const
    {
        return C(this->_value & other._value);
    }

    constexpr C operator | (const typename T2::Type& other) const
    {
        return C(this->_value | other._value);
    }

    constexpr C operator ^ (const typename T2::Type& other) const
    {
        return C(this->_value ^ other._value);
    }

    constexpr const C operator &= (const typename T2::Type& other)
    {
        this->_value &= other._value;
        return C(this->_value);
    }

    constexpr const C operator |= (const typename T2::Type& other)
    {
        this->_value |= other._value;
        return C(this->_value);
    }

    constexpr const C operator ^= (const typename T2::Type& other)
    {
        this->_value ^= other._value;
        return C(this->_value);
    }

    constexpr bool operator == (const typename T2::Type& other) const
    {
        return this->_value == other._value;
    }

    constexpr bool operator != (const typename T2::Type& other) const
    {
        return this->_value != other._value;
    }
};
template<class C, typename T, typename T2>
struct CRTPFlagEnumBinaryOperators<C, T, T2> : CRTPFlagEnumUnaryOperators<C, T>
{
    constexpr CRTPFlagEnumBinaryOperators() = default;

    constexpr const C operator = (const typename T2::Type& other)
    {
        this->_value = other._value;
        return C(this->_value);
    }

    constexpr C operator & (const typename T2::Type& other) const
    {
        return C(this->_value & other._value);
    }

    constexpr C operator | (const typename T2::Type& other) const
    {
        return C(this->_value | other._value);
    }

    constexpr C operator ^ (const typename T2::Type& other) const
    {
        return C(this->_value ^ other._value);
    }

    constexpr const C operator &= (const typename T2::Type& other)
    {
        this->_value &= other._value;
        return C(this->_value);
    }

    constexpr const C operator |= (const typename T2::Type& other)
    {
        this->_value |= other._value;
        return C(this->_value);
    }

    constexpr const C operator ^= (const typename T2::Type& other)
    {
        this->_value ^= other._value;
        return C(this->_value);
    }

    constexpr bool operator == (const typename T2::Type& other) const
    {
        return this->_value == other._value;
    }

    constexpr bool operator != (const typename T2::Type& other) const
    {
        return this->_value != other._value;
    }
};

template<class C, typename T, typename ... Types>
struct CRTPFlagEnum : CRTPFlagEnumBinaryOperators<CRTPFlagEnum<C, T, Types...>, T, C, Types...>
{
    constexpr CRTPFlagEnum()
        : CRTPFlagEnumBinaryOperators<CRTPFlagEnum<C, T, Types...>, T, C, Types...>()
    {
        this->_value = 0;
    };
    constexpr CRTPFlagEnum(const typename C::Type& other)
        : CRTPFlagEnumBinaryOperators<CRTPFlagEnum<C, T, Types...>, T, C, Types...>()
    {
        this->_value = other._value;
    };
    constexpr CRTPFlagEnum(volatile const typename C::Type& other)
        : CRTPFlagEnumBinaryOperators<CRTPFlagEnum<C, T, Types...>, T, C, Types...>()
    {
        this->_value = other._value;
    };

protected:
    friend C;

    template<typename W, typename X>
    friend struct CRTPFlagEnumUnaryOperators;

    template<typename W, typename X, typename Y, typename ... Z>
    friend struct CRTPFlagEnumBinaryOperators;

    constexpr CRTPFlagEnum(const T& value)
        : CRTPFlagEnumBinaryOperators<CRTPFlagEnum<C, T, Types...>, T, C, Types...>()
    {
        this->_value = value;
    }
};


// Examples

struct CRTPUppercaseLetterIndex
{
    using Type = CRTPIndexEnum<CRTPUppercaseLetterIndex, uint32_t>;

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

    // This function can be defined if needed, but should be avoided to enforce type safety
    [[deprecated]] static constexpr Type FromUnderlying(volatile uint32_t _value)
    {
        uint32_t value = _value;
        return Type(value);
    }
};

struct CRTPFlagExample
{
    using Type = CRTPFlagEnum<CRTPFlagExample, uint32_t, CRTPUppercaseLetterIndex>;

    static constexpr Type Null = { 0 };
    static constexpr Type Flag1 = { 1 };
    static constexpr Type Flag2 = { 2 };
    static constexpr Type Flag4 = { 4 };
    static constexpr Type Flag8 = { 8 };
    static constexpr Type Flag16 = { 16 };

    static constexpr Type FromUnderlying(volatile uint32_t _value)
    {
        uint32_t value = _value;
        return Type(value);
    }
};
