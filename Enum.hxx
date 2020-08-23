#ifdef ENABLE_ENUM_FLAG
    constexpr ENABLE_ENUM_FLAG operator | (const ENABLE_ENUM_FLAG& lhs, const ENABLE_ENUM_FLAG& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(lhs) | static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(rhs));
    }
    constexpr ENABLE_ENUM_FLAG operator & (const ENABLE_ENUM_FLAG& lhs, const ENABLE_ENUM_FLAG& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(lhs) & static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(rhs));
    }
    constexpr ENABLE_ENUM_FLAG operator ^ (const ENABLE_ENUM_FLAG& lhs, const ENABLE_ENUM_FLAG& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(lhs) ^ static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(rhs));
    }
    constexpr ENABLE_ENUM_FLAG operator << (const ENABLE_ENUM_FLAG& lhs, const uint8_t& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(lhs) << rhs);
    }
    constexpr ENABLE_ENUM_FLAG operator >> (const ENABLE_ENUM_FLAG& lhs, const uint8_t& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(lhs) >> rhs);
    }
    constexpr ENABLE_ENUM_FLAG operator ~ (const ENABLE_ENUM_FLAG& lhs)
    {
        return static_cast<ENABLE_ENUM_FLAG>(~static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(lhs));
    }
    constexpr bool operator ! (const ENABLE_ENUM_FLAG& lhs)
    {
        return lhs == ENABLE_ENUM_FLAG::Null;
    }
    constexpr ENABLE_ENUM_FLAG& operator |= (ENABLE_ENUM_FLAG& lhs, const ENABLE_ENUM_FLAG rhs)
    {
        lhs = lhs | rhs;
        return lhs;
    }
    constexpr ENABLE_ENUM_FLAG& operator &= (ENABLE_ENUM_FLAG& lhs, const ENABLE_ENUM_FLAG rhs)
    {
        lhs = lhs & rhs;
        return lhs;
    }
    constexpr ENABLE_ENUM_FLAG& operator ^= (ENABLE_ENUM_FLAG& lhs, const ENABLE_ENUM_FLAG rhs)
    {
        lhs = lhs ^ rhs;
        return lhs;
    }

    constexpr typename std::underlying_type<ENABLE_ENUM_FLAG>::type operator + (const ENABLE_ENUM_FLAG& lhs)
    {
        return static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG>::type>(lhs);
    }
#endif

// Allow defining compatibility by just defining ENABLE_ENUM_FLAG_OTHER when also using ENABLE_ENUM_FLAG
#if defined (ENABLE_ENUM_FLAG) && defined (ENABLE_ENUM_FLAG_OTHER) && ! defined (ENABLE_ENUM_FLAG_COMPATIBILITY)
    #define ENABLE_ENUM_FLAG_COMPATIBILITY ENABLE_ENUM_FLAG
#endif

#if defined (ENABLE_ENUM_FLAG_COMPATIBILITY) && defined (ENABLE_ENUM_FLAG_OTHER)
    constexpr ENABLE_ENUM_FLAG_COMPATIBILITY operator | (const ENABLE_ENUM_FLAG_COMPATIBILITY& lhs, const ENABLE_ENUM_FLAG_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(lhs) | static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(rhs));
    }
    constexpr ENABLE_ENUM_FLAG_COMPATIBILITY operator & (const ENABLE_ENUM_FLAG_COMPATIBILITY& lhs, const ENABLE_ENUM_FLAG_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(lhs) & static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(rhs));
    }
    constexpr ENABLE_ENUM_FLAG_COMPATIBILITY operator ^ (const ENABLE_ENUM_FLAG_COMPATIBILITY& lhs, const ENABLE_ENUM_FLAG_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(lhs) ^ static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(rhs));
    }
    constexpr ENABLE_ENUM_FLAG_COMPATIBILITY operator == (const ENABLE_ENUM_FLAG_COMPATIBILITY& lhs, const ENABLE_ENUM_FLAG_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(lhs) == static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(rhs));
    }
    constexpr ENABLE_ENUM_FLAG_COMPATIBILITY operator != (const ENABLE_ENUM_FLAG_COMPATIBILITY& lhs, const ENABLE_ENUM_FLAG_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_FLAG_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(lhs) != static_cast<typename std::underlying_type<ENABLE_ENUM_FLAG_COMPATIBILITY>::type>(rhs));
    }
    constexpr ENABLE_ENUM_FLAG_COMPATIBILITY& operator |= (ENABLE_ENUM_FLAG_COMPATIBILITY& lhs, const ENABLE_ENUM_FLAG_OTHER rhs)
    {
        lhs = lhs | rhs;
        return lhs;
    }
    constexpr ENABLE_ENUM_FLAG_COMPATIBILITY& operator &= (ENABLE_ENUM_FLAG_COMPATIBILITY& lhs, const ENABLE_ENUM_FLAG_OTHER rhs)
    {
        lhs = lhs & rhs;
        return lhs;
    }
    constexpr ENABLE_ENUM_FLAG_COMPATIBILITY& operator ^= (ENABLE_ENUM_FLAG_COMPATIBILITY& lhs, const ENABLE_ENUM_FLAG_OTHER rhs)
    {
        lhs = lhs ^ rhs;
        return lhs;
    }

#endif

#ifdef ENABLE_ENUM_INDEX
    constexpr ENABLE_ENUM_INDEX operator + (const ENABLE_ENUM_INDEX& lhs, const ENABLE_ENUM_INDEX& rhs)
    {
        return static_cast<ENABLE_ENUM_INDEX>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(lhs) + static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(rhs));
    }
    constexpr ENABLE_ENUM_INDEX operator - (const ENABLE_ENUM_INDEX& lhs, const ENABLE_ENUM_INDEX& rhs)
    {
        return static_cast<ENABLE_ENUM_INDEX>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(lhs) - static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(rhs));
    }
    constexpr ENABLE_ENUM_INDEX operator * (const ENABLE_ENUM_INDEX& lhs, const ENABLE_ENUM_INDEX& rhs)
    {
        return static_cast<ENABLE_ENUM_INDEX>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(lhs) * static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(rhs));
    }
    constexpr ENABLE_ENUM_INDEX operator / (const ENABLE_ENUM_INDEX& lhs, const ENABLE_ENUM_INDEX& rhs)
    {
        return static_cast<ENABLE_ENUM_INDEX>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(lhs) / static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(rhs));
    }
    inline ENABLE_ENUM_INDEX& operator ++ (ENABLE_ENUM_INDEX& lhs)
    {
        return lhs = static_cast<ENABLE_ENUM_INDEX>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(lhs) + 1);
    }
    inline ENABLE_ENUM_INDEX operator ++ (ENABLE_ENUM_INDEX& lhs, int)
    {
        ENABLE_ENUM_INDEX result = lhs;
        ++lhs;
        return result;
    }
    inline ENABLE_ENUM_INDEX& operator -- (ENABLE_ENUM_INDEX& lhs)
    {
        return lhs = static_cast<ENABLE_ENUM_INDEX>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(lhs) - 1);
    }
    inline ENABLE_ENUM_INDEX operator -- (ENABLE_ENUM_INDEX& lhs, int)
    {
        ENABLE_ENUM_INDEX result = lhs;
        --lhs;
        return result;
    }
    constexpr ENABLE_ENUM_INDEX& operator += (ENABLE_ENUM_INDEX& lhs, const ENABLE_ENUM_INDEX rhs)
    {
        return lhs = lhs + rhs;
    }
    constexpr ENABLE_ENUM_INDEX& operator -= (ENABLE_ENUM_INDEX& lhs, const ENABLE_ENUM_INDEX rhs)
    {
        return lhs = lhs - rhs;
    }
    constexpr ENABLE_ENUM_INDEX& operator *= (ENABLE_ENUM_INDEX& lhs, const ENABLE_ENUM_INDEX rhs)
    {
        return lhs = lhs * rhs;
    }
    constexpr ENABLE_ENUM_INDEX& operator /= (ENABLE_ENUM_INDEX& lhs, const ENABLE_ENUM_INDEX rhs)
    {
        return lhs = lhs / rhs;
    }

    constexpr typename std::underlying_type<ENABLE_ENUM_INDEX>::type operator + (const ENABLE_ENUM_INDEX& lhs)
    {
        return static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX>::type>(lhs);
    }
#endif


// Allow defining compatibility by just defining ENABLE_ENUM_INDEX_OTHER when also using ENABLE_ENUM_INDEX
#if defined (ENABLE_ENUM_INDEX) && defined (ENABLE_ENUM_INDEX_OTHER) && ! defined (ENABLE_ENUM_INDEX_COMPATIBILITY)
#define ENABLE_ENUM_INDEX_COMPATIBILITY ENABLE_ENUM_INDEX
#endif

#if defined (ENABLE_ENUM_INDEX_COMPATIBILITY) && defined (ENABLE_ENUM_INDEX_OTHER)
    constexpr ENABLE_ENUM_INDEX_COMPATIBILITY operator + (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_INDEX_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) + static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs));
    }
    constexpr ENABLE_ENUM_INDEX_COMPATIBILITY operator - (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_INDEX_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) - static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs));
    }
    constexpr ENABLE_ENUM_INDEX_COMPATIBILITY operator * (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_INDEX_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) * static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs));
    }
    constexpr ENABLE_ENUM_INDEX_COMPATIBILITY operator / (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<ENABLE_ENUM_INDEX_COMPATIBILITY>(static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) / static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs));
    }
    constexpr bool operator > (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) > static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs);
    }
    constexpr bool operator >= (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) >= static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs);
    }
    constexpr bool operator < (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) < static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs);
    }
    constexpr bool operator <= (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) <= static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs);
    }
    constexpr bool operator == (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) == static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs);
    }
    constexpr bool operator != (const ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER& rhs)
    {
        return static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(lhs) != static_cast<typename std::underlying_type<ENABLE_ENUM_INDEX_COMPATIBILITY>::type>(rhs);
    }
    constexpr ENABLE_ENUM_INDEX_COMPATIBILITY& operator += (ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER rhs)
    {
        return lhs = lhs + rhs;
    }
    constexpr ENABLE_ENUM_INDEX_COMPATIBILITY& operator -= (ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER rhs)
    {
        return lhs = lhs - rhs;
    }
    constexpr ENABLE_ENUM_INDEX_COMPATIBILITY& operator *= (ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER rhs)
    {
        return lhs = lhs * rhs;
    }
    constexpr ENABLE_ENUM_INDEX_COMPATIBILITY& operator /= (ENABLE_ENUM_INDEX_COMPATIBILITY& lhs, const ENABLE_ENUM_INDEX_OTHER rhs)
    {
        return lhs = lhs / rhs;
    }
#endif

#undef ENABLE_ENUM_FLAG
#undef ENABLE_ENUM_FLAG_COMPATIBILITY
#undef ENABLE_ENUM_FLAG_OTHER
#undef ENABLE_ENUM_INDEX
#undef ENABLE_ENUM_INDEX_COMPATIBILITY
#undef ENABLE_ENUM_INDEX_OTHER