#pragma once

template<typename E>
struct Enum
{
protected:
    E _value;

    Enum(const Enum<E>& value) : _value(value._value) {};
    Enum(const E& value) : _value(value) {};
};

template<typename E>
struct FlagEnum : Enum<E>
{
    FlagEnum(const FlagEnum<E>& value) : Enum<E>{ value } {};
    FlagEnum(const E& value) : Enum<E>{ value } {};


    inline constexpr FlagEnum<E>& operator = (const FlagEnum<E>& rhs)
    {
        this->_value = rhs._value;
        return *this;
    }
    inline constexpr FlagEnum<E>& operator = (const E& rhs)
    {
        this->_value = rhs;
        return *this;
    }

    inline constexpr FlagEnum<E> operator | (const E& rhs) const
    {
        return FlagEnum<E>(
            static_cast<E>(
                static_cast<typename std::underlying_type<E>::type>(this->_value)
                |
                static_cast<typename std::underlying_type<E>::type>(rhs)
                )
            );
    }
    inline constexpr FlagEnum<E> operator | (const FlagEnum<E>& rhs) const
    {
        return *this | rhs._value;
    }

    inline constexpr FlagEnum<E> operator & (const E& rhs) const
    {
        return FlagEnum<E>(
            static_cast<E>(
                static_cast<typename std::underlying_type<E>::type>(this->_value)
                &
                static_cast<typename std::underlying_type<E>::type>(rhs)
                )
            );
    }
    inline constexpr FlagEnum<E> operator & (const FlagEnum<E>& rhs) const
    {
        return *this | rhs._value;
    }

    inline constexpr FlagEnum<E> operator ^ (const E& rhs) const
    {
        return FlagEnum<E>(
            static_cast<E>(
                static_cast<typename std::underlying_type<E>::type>(this->_value)
                ^
                static_cast<typename std::underlying_type<E>::type>(rhs)
                )
            );
    }
    inline constexpr FlagEnum<E> operator ^ (const FlagEnum<E>& rhs) const
    {
        return *this ^ rhs._value;
    }

    inline constexpr bool operator == (const E& rhs) const
    {
        return this->_value == rhs;
    }
    inline constexpr bool operator == (const FlagEnum<E>& rhs) const
    {
        return *this == rhs._value;
    }

    inline constexpr bool operator != (const E& rhs) const
    {
        return this->_value != rhs;
    }
    inline constexpr bool operator != (const FlagEnum<E>& rhs) const
    {
        return *this != rhs._value;
    }

    inline constexpr FlagEnum<E> operator << (const uint8_t rhs) const
    {
        return FlagEnum<E>(
            static_cast<E>(
                static_cast<typename std::underlying_type<E>::type>(this->_value)
                <<
                rhs
                )
            );
    }
    inline constexpr FlagEnum<E> operator >> (const uint8_t rhs) const
    {
        return FlagEnum<E>(
            static_cast<E>(
                static_cast<typename std::underlying_type<E>::type>(this->_value)
                >>
                rhs
                )
            );
    }

    inline constexpr FlagEnum<E>& operator |= (const E rhs)
    {
        *this = *this | rhs;
        return *this;
    }
    inline constexpr FlagEnum<E>& operator |= (const FlagEnum<E> rhs)
    {
        *this = *this | rhs;
        return *this;
    }

    inline constexpr FlagEnum<E>& operator &= (const E rhs)
    {
        *this = *this & rhs;
        return *this;
    }
    inline constexpr FlagEnum<E>& operator &= (const FlagEnum<E> rhs)
    {
        *this = *this & rhs;
        return *this;
    }

    inline constexpr FlagEnum<E>& operator ^= (const E rhs)
    {
        *this = *this ^ rhs;
        return *this;
    }
    inline constexpr FlagEnum<E>& operator ^= (const FlagEnum<E> rhs)
    {
        *this = *this ^ rhs;
        return *this;
    }

    inline constexpr typename std::underlying_type<E>::type operator + () const
    {
        return static_cast<typename std::underlying_type<E>::type>(this->_value);
    }
    inline constexpr FlagEnum<E> operator ~ () const
    {
        return FlagEnum<E>(static_cast<E>(~static_cast<typename std::underlying_type<E>::type>(this->_value)));
    }
    inline constexpr bool operator ! () const
    {
        return this->_value == E::Null;
    }
};


template<typename E>
struct IndexEnum : Enum<E>
{
    IndexEnum<E>(const IndexEnum<E>& value) : Enum<E>(value) {};
    IndexEnum<E>(const E& value) : Enum<E>(value) {};


    inline constexpr IndexEnum<E>& operator = (const IndexEnum<E>& rhs)
    {
        this->_value = rhs._value;
        return *this;
    }
    inline constexpr IndexEnum<E>& operator = (const E& rhs)
    {
        this->_value = rhs;
        return *this;
    }
    inline constexpr IndexEnum<E>& operator = (volatile const E& rhs)
    {
        this->_value = rhs;
        return *this;
    }

    inline constexpr IndexEnum<E> operator + (const E& rhs) const
    {
        return IndexEnum<E>(
            static_cast<E>(
                static_cast<typename std::underlying_type<E>::type>(this->_value)
                +
                static_cast<typename std::underlying_type<E>::type>(rhs)
                )
            );
    }
    inline constexpr IndexEnum<E> operator + (const IndexEnum<E>& rhs) const
    {
        return *this + rhs._value;
    }

    inline constexpr IndexEnum<E> operator - (const E& rhs) const
    {
        return IndexEnum<E>(
            static_cast<E>(
                static_cast<typename std::underlying_type<E>::type>(this->_value)
                -
                static_cast<typename std::underlying_type<E>::type>(rhs)
                )
            );
    }
    inline constexpr IndexEnum<E> operator - (const IndexEnum<E>& rhs) const
    {
        return *this - rhs._value;
    }

    inline constexpr bool operator == (const E& rhs) const
    {
        return this->_value == rhs;
    }
    inline constexpr bool operator == (const IndexEnum<E>& rhs) const
    {
        return *this == rhs._value;
    }

    inline constexpr bool operator != (const E& rhs) const
    {
        return this->_value != rhs;
    }
    inline constexpr bool operator != (const IndexEnum<E>& rhs) const
    {
        return *this != rhs._value;
    }

    inline constexpr IndexEnum<E>& operator += (const E rhs)
    {
        *this = *this + rhs;
        return *this;
    }
    inline constexpr IndexEnum<E>& operator += (const IndexEnum<E> rhs)
    {
        *this = *this + rhs;
        return *this;
    }

    inline constexpr bool operator > (const E& rhs) const
    {
        return this->_value > rhs;
    }
    inline constexpr bool operator > (const IndexEnum<E>& rhs) const
    {
        return *this > rhs._value;
    }

    inline constexpr bool operator >= (const E& rhs) const
    {
        return this->_value >= rhs;
    }
    inline constexpr bool operator >= (const IndexEnum<E>& rhs) const
    {
        return *this >= rhs._value;
    }

    inline constexpr bool operator < (const E& rhs) const
    {
        return this->_value < rhs;
    }
    inline constexpr bool operator < (const IndexEnum<E>& rhs) const
    {
        return *this < rhs._value;
    }

    inline constexpr bool operator <= (const E& rhs) const
    {
        return this->_value <= rhs;
    }
    inline constexpr bool operator <= (const IndexEnum<E>& rhs) const
    {
        return *this <= rhs._value;
    }

    inline constexpr IndexEnum<E>& operator -= (const E rhs)
    {
        *this = *this - rhs;
        return *this;
    }
    inline constexpr IndexEnum<E>& operator -= (const IndexEnum<E> rhs)
    {
        *this = *this - rhs;
        return *this;
    }


    inline constexpr typename std::underlying_type<E>::type operator + () const
    {
        return static_cast<typename std::underlying_type<E>::type>(this->_value);
    }
    inline IndexEnum<E>& operator ++ ()
    {
        return *this = static_cast<E>(static_cast<typename std::underlying_type<E>::type>(this->_value) + 1);
    }
    inline IndexEnum<E> operator ++ (int)
    {
        IndexEnum<E> result = *this;
        ++(*this);
        return result;
    }

    inline IndexEnum<E>& operator -- ()
    {
        return *this = static_cast<E>(static_cast<typename std::underlying_type<E>::type>(this->_value) + 1);
    }
    inline IndexEnum<E> operator -- (int)
    {
        IndexEnum<E> result = *this;
        ++(*this);
        return result;
    }
};
