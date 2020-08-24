#pragma once

#include <type_traits>

// Uses Curiously Recurring Template Pattern
// https://en.wikipedia.org/wiki/Curiously_recurring_template_pattern

template<typename T>
struct CRTPEnumBase
{
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
    {
        this->_value = 0;
    };
    constexpr CRTPIndexEnum(const typename C::Type& other)
    {
        this->_value = other._value;
    };
    constexpr CRTPIndexEnum(volatile const typename C::Type& other)
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
    {
        this->_value = value;
    }
};


template<class C, typename T>
struct CRTPFlagEnumUnaryOperators : CRTPEnumBase<T>
{
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
    {
        this->_value = 0;
    };
    constexpr CRTPFlagEnum(const typename C::Type& other)
    {
        this->_value = other._value;
    };
    constexpr CRTPFlagEnum(volatile const typename C::Type& other)
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
    {
        this->_value = value;
    }
};