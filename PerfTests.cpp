#include <chrono>
#include <iostream>

#include "PerfTests.hpp"
#include "Classes.hpp"
#include "Enums.hpp"

#define TEST_TIME 2ull;

class Timer
{
private:
    // Type aliases to make accessing nested type easier
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }

    void reset()
    {
        m_beg = clock_t::now();
    }

    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

void iterateEnums()
{
    Timer t;
    size_t loops = 40000000ull * TEST_TIME;

    std::cout << std::endl << "Iterating through all values " << loops << " times using a for loop." << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (uint32_t j = 0; j < 26;)
        {
            volatile auto _k = j;
            auto k = _k;
            LowercaseLetters[k];
            j = ++k;
        }
    }
    auto time = t.elapsed();
    std::cout << "Control array iteration:                                  " << time << " seconds" << std::endl << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (uint32_t j = CEnumLowercaseLetterIndex::Init; j < CEnumLowercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = _k;
            LowercaseLetters[k];
            j = ++k;
        }
    }
    std::cout << "C Enum array iteration:                                   " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (uint32_t j = ConstexprLowercaseLetterIndex::Init; j < ConstexprLowercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = _k;
            LowercaseLetters[k];
            j = ++k;
        }
    }
    std::cout << "Constexpr array iteration:                                " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto j = LowercaseLetterIndex::Init; j < LowercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = _k;
            LowercaseLetters[+k];
            j = ++k;
        }
    }
    std::cout << "Strong Enum array iteration with plus:                    " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto j = LowercaseLetterIndex::Init; j < LowercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = _k;
            LowercaseLetters[static_cast<uint32_t>(k)];
            j = ++k;
        }
    }
    std::cout << "Strong Enum array iteration with static_cast:             " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto j = UppercaseLetterIndex::Init; j < UppercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = _k;
            UppercaseLetters[k];
            j = ++k;
        }
    }
    std::cout << "Strong Enum ConstEnumeratedArray iteration:               " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto j = UppercaseLetterIndex::Init; j < UppercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = _k;
            UppercaseLetters[+k];
            j = ++k;
        }
    }
    std::cout << "Strong Enum ConstEnumeratedArray iteration with plus:     " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto j = LowercaseLetterIndex::Init; j < LowercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = _k;
            LowercaseLettersNonConst[k];
            j = ++k;
        }
    }
    std::cout << "Strong Enum EnumeratedArray iteration:                    " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto j = LowercaseLetterIndex::Init; j < LowercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = _k;
            ClassUppercaseLetters[+k];
            j = ++k;
        }
    }
    std::cout << "Strong Enum EnumeratedArray iteration with plus:          " << t.elapsed() - time << " seconds" << std::endl;

    
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (ClassUppercaseLetterIndex::Type j = ClassUppercaseLetterIndex::Init; j < ClassUppercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = ClassUppercaseLetterIndex::Type(_k);
            ClassUppercaseLetters[+k];
            j = ++k;
        }
    }
    std::cout << "IndexEnum  EnumeratedArray iteration with plus:           " << t.elapsed() - time << " seconds" << std::endl;

    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (CRTPUppercaseLetterIndex::Type j = CRTPUppercaseLetterIndex::Init; j < CRTPUppercaseLetterIndex::Count;)
        {
            volatile auto _k = j;
            auto k = CRTPUppercaseLetterIndex::Type(_k);
            ClassUppercaseLetters[+k];
            j = ++k;
        }
    }
    std::cout << "CRTPIndexEnum iteration with plus:                        " << t.elapsed() - time << " seconds" << std::endl;
}

void arrayAccess()
{
    Timer t;
    volatile char c;
    size_t loops = 2600000000ull * TEST_TIME;

    std::cout << std::endl << "Accessing array value " << loops << " times" << std::endl;


    c = 0;
    volatile auto _t0 = 0;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t0 = _t0;
        c = LowercaseLetters[t0];
    }
    auto time = t.elapsed();
    std::cout << "Control array access:                                     " << time << " seconds" << std::endl << std::endl;


    c = 0;
    volatile CEnumLowercaseLetterIndex _t1 = CEnumLowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t1 = _t1;
        c = LowercaseLetters[t1];
    }
    std::cout << "C Enum array access:                                      " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile auto _t2 = ConstexprLowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t2 = _t2;
        c = LowercaseLetters[t2];
    }
    std::cout << "Constexpr array access:                                   " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile LowercaseLetterIndex _t3 = LowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t3 = _t3;
        c = LowercaseLetters[+t3];
    }
    std::cout << "Strong Enum array access with plus:                       " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile LowercaseLetterIndex _t4 = LowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t4 = _t4;
        c = LowercaseLetters[static_cast<uint32_t>(t4)];
    }
    std::cout << "Strong Enum array access with static_cast:                " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile UppercaseLetterIndex _t5 = UppercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t5 = _t5;
        c = UppercaseLetters[t5];
    }
    std::cout << "Strong Enum ConstEnumeratedArray access:                  " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile UppercaseLetterIndex _t6 = UppercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t6 = _t6;
        c = UppercaseLetters[+t6];
    }
    std::cout << "Strong Enum ConstEnumeratedArray access with plus:        " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile LowercaseLetterIndex _t7 = LowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t7 = _t7;
        c = LowercaseLettersNonConst[t7];
    }
    std::cout << "Strong Enum EnumeratedArray access:                       " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile LowercaseLetterIndex _t8 = LowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t8 = _t8;
        c = LowercaseLettersNonConst[+t8];
    }
    std::cout << "Strong Enum EnumeratedArray access with plus:             " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile auto _t9 = ClassUppercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t9 = ClassUppercaseLetterIndex::Type(_t9);
        c = ClassUppercaseLetters[t9];
    }
    std::cout << "Strong Enum ClassEnumeratedArray access:                  " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile auto _t10 = ClassUppercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t10 = ClassUppercaseLetterIndex::Type(_t10);
        c = ClassUppercaseLetters[+t10];
    }
    std::cout << "IndexEnum EnumeratedArray access with plus:               " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile auto _t11 = ClassUppercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t11 = ClassUppercaseLetterIndex::Type(_t11);
        c = _UppercaseLetters[+t11];
    }
    std::cout << "IndexEnum array access with plus:                         " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile auto _t12 = CRTPUppercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t12 = _t12;
        c = _UppercaseLetters[+t12];
    }
    std::cout << "CRTPIndexEnum array access with plus:                     " << t.elapsed() - time << " seconds" << std::endl;
}


void arrayCache()
{
    Timer t;
    volatile char c = 'a';
    size_t loops = 4000000000ull * TEST_TIME;

    std::cout << std::endl << "Cached array access " << loops << " times" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = _LowercaseLettersNonConst[0];
    }
    auto time = t.elapsed();
    std::cout << "Control cached array access:                              " << time << " seconds" << std::endl << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = _LowercaseLettersNonConst[CEnumLowercaseLetterIndex::LetterA];
    }
    std::cout << "C Enum cached array access:                               " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = _LowercaseLettersNonConst[ConstexprLowercaseLetterIndex::LetterA];
    }
    std::cout << "Constexpr cached array access:                            " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = _LowercaseLettersNonConst[+LowercaseLetterIndex::LetterA];
    }
    std::cout << "Strong Enum cached array access with plus:                " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = _LowercaseLettersNonConst[static_cast<uint32_t>(LowercaseLetterIndex::LetterA)];
    }
    std::cout << "Strong Enum cached array access with static_cast:         " << t.elapsed() - time << " seconds" << std::endl;


    /*t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = UppercaseLetters[UppercaseLetterIndex::LetterA];
    }
    std::cout << "Strong Enum ConstEnumeratedArray cached access:           " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = UppercaseLetters[+UppercaseLetterIndex::LetterA];
    }
    std::cout << "Strong Enum ConstEnumeratedArray cached access with plus: " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = LowercaseLettersNonConst[LowercaseLetterIndex::LetterA];
    }
    std::cout << "Strong Enum EnumeratedArray cached access:                " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = LowercaseLettersNonConst[+LowercaseLetterIndex::LetterA];
    }
    std::cout << "Strong Enum EnumeratedArray cached access with plus:      " << t.elapsed() - time << " seconds" << std::endl;*/

    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        c = _UppercaseLetters[+CRTPUppercaseLetterIndex::LetterA];
    }
    std::cout << "CRTPIndexEnum cached array access with plus:              " << t.elapsed() - time << " seconds" << std::endl;
}

void bitwiseOperations()
{
    Timer t;
    volatile char c = 0;
    size_t loops = 4000000000ull * TEST_TIME;

    std::cout << std::endl << "Performing a set of bitwise operations " << loops << " times" << std::endl;


    volatile uint32_t _t0 = 0;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        uint32_t t0 = _t0;
        t0 = static_cast<uint32_t>(~(((t0 | 1) & 2) ^ 4));
    }
    auto time = t.elapsed();
    std::cout << "Control bitwise operations:                               " << time << " seconds" << std::endl << std::endl;


    volatile CEnumFlagExample c1 = CEnumFlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        CEnumFlagExample t1 = c1;
        t1 = static_cast<CEnumFlagExample>(~(((c1 | CEnumFlagExample::Flag1) & CEnumFlagExample::Flag2) ^ CEnumFlagExample::Flag4));
    }
    std::cout << "C Enum bitwise operations:                                " << t.elapsed() - time << " seconds" << std::endl;


    volatile FlagExample c2 = FlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        FlagExample t2 = c2;
        t2 = ~(((t2 | FlagExample::Flag1) & FlagExample::Flag2) ^ FlagExample::Flag4);
    }
    std::cout << "Strong Enum bitwise operations:                           " << t.elapsed() - time << " seconds" << std::endl;


    volatile FlagExample c3 = FlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        FlagExample t3 = c3;
        t3 = ~(((t3 | FlagExample2::Flag1) & FlagExample2::Flag2) ^ FlagExample2::Flag4);
    }
    std::cout << "Mixing Strong Enum bitwise operations:                    " << t.elapsed() - time << " seconds" << std::endl;


    volatile auto c4 = ClassFlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        ClassFlagExample::Type t4(c4);
        t4 = ~(((t4 | ClassFlagExample::Flag1) & ClassFlagExample::Flag2) ^ ClassFlagExample::Flag4);
    }
    std::cout << "FlagEnum bitwise operations:                              " << t.elapsed() - time << " seconds" << std::endl;


    volatile auto c5 = CRTPFlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        CRTPFlagExample::Type t5(c5);
        t5 = ~(((t5 | CRTPFlagExample::Flag1) & CRTPFlagExample::Flag2) ^ CRTPFlagExample::Flag4);
    }
    std::cout << "CRTP IndexEnum bitwise operations:                        " << t.elapsed() - time << " seconds" << std::endl;
}
