#include <chrono>
#include <iostream>

#include "PerfTests.hpp"
#include "Enums.hpp"

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
    size_t loops = 125000000;

    std::cout << std::endl << "Iterating through all values " << loops << " times using a for loop." << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (volatile uint32_t j = 0; j < 26;)
        {
            auto k = j;
            LowercaseLetters[k];
            j = ++k;
        }
    }
    auto time = t.elapsed();
    std::cout << "Control array iteration:                                  " << t.elapsed() << " seconds" << std::endl << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (volatile uint32_t j = CEnumLowercaseLetterIndex::Init; j < CEnumLowercaseLetterIndex::Count;)
        {
            auto k = j;
            LowercaseLetters[k];
            j = ++k;
        }
    }
    std::cout << "C Enum array iteration:                                   " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (volatile auto j = LowercaseLetterIndex::Init; j < LowercaseLetterIndex::Count;)
        {
            auto k = j;
            LowercaseLetters[+k];
            j = ++k;
        }
    }
    std::cout << "Strong Enum array iteration with plus:                    " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (volatile auto j = LowercaseLetterIndex::Init; j < LowercaseLetterIndex::Count;)
        {
            auto k = j;
            LowercaseLetters[static_cast<uint32_t>(k)];
            j = ++k;
        }
    }
    std::cout << "Strong Enum array iteration with static_cast:             " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (volatile auto j = UppercaseLetterIndex::Init; j < UppercaseLetterIndex::Count;)
        {
            auto k = j;
            UppercaseLetters[k];
            j = ++k;
        }
    }
    std::cout << "Strong Enum ConstEnumeratedArray iteration:               " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (volatile auto j = UppercaseLetterIndex::Init; j < UppercaseLetterIndex::Count;)
        {
            auto k = j;
            UppercaseLetters[+k];
            j = ++k;
        }
    }
    std::cout << "Strong Enum ConstEnumeratedArray iteration with plus:     " << t.elapsed() - time << " seconds" << std::endl;


    volatile auto t6 = UppercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (volatile auto j = t6; j < UppercaseLetterIndex::Count;)
        {
            auto k = j;
            UppercaseLetters[i];
            j = ++k;
        }
    }
    std::cout << "Strong Enum EnumeratedArray iteration:                    " << t.elapsed() - time << " seconds" << std::endl;


    volatile auto t7 = UppercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (volatile auto j = t7; j < UppercaseLetterIndex::Count;)
        {
            auto k = j;
            UppercaseLetters[+i];
            j = ++k;
        }
    }
    std::cout << "Strong Enum EnumeratedArray iteration with plus:          " << t.elapsed() - time << " seconds" << std::endl;
}

void arrayAccess()
{
    Timer t;
    volatile char c;
    size_t loops = 10000000000;

    std::cout << std::endl << "Accessing array value " << loops << " times" << std::endl;


    c = 0;
    volatile auto _t0 = 0;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t0 = _t0;
        c = t0;
    }
    auto time = t.elapsed();
    std::cout << "Control array access:                                     " << t.elapsed() << " seconds" << std::endl << std::endl;


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
    volatile LowercaseLetterIndex _t2 = LowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t2 = _t2;
        c = LowercaseLetters[+t2];
    }
    std::cout << "Strong Enum array access with plus:                       " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile LowercaseLetterIndex _t3 = LowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t3 = _t3;
        c = LowercaseLetters[static_cast<uint32_t>(t3)];
    }
    std::cout << "Strong Enum array access with static_cast:                " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile UppercaseLetterIndex _t4 = UppercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t4 = _t4;
        c = UppercaseLetters[t4];
    }
    std::cout << "Strong Enum ConstEnumeratedArray access:                  " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile UppercaseLetterIndex _t5 = UppercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t5 = _t5;
        c = UppercaseLetters[+t5];
    }
    std::cout << "Strong Enum ConstEnumeratedArray access with plus:        " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile UppercaseLetterIndex _t6 = UppercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t4 = _t4;
        c = LowercaseLettersNonConst[t4];
    }
    std::cout << "Strong Enum EnumeratedArray access:                       " << t.elapsed() - time << " seconds" << std::endl;


    c = 0;
    volatile UppercaseLetterIndex _t7 = UppercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t5 = _t5;
        c = LowercaseLettersNonConst[+t5];
    }
    std::cout << "Strong Enum EnumeratedArray access with plus:             " << t.elapsed() - time << " seconds" << std::endl;
}


void arrayWrite()
{
    Timer t;
    volatile char c = 'a';
    size_t loops = 10000000000;

    std::cout << std::endl << "Writing array value " << loops << " times" << std::endl;


    volatile auto _t0 = 0;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t0 = _t0;
        _LowercaseLettersNonConst[0] = c;
    }
    auto time = t.elapsed();
    std::cout << "Control array write:                                      " << t.elapsed() << " seconds" << std::endl << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        _LowercaseLettersNonConst[0] = c;
    }
    std::cout << "C Enum array write:                                       " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        _LowercaseLettersNonConst[+UppercaseLetterIndex::LetterA] = c;
    }
    std::cout << "Strong Enum array write with plus:                        " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        _LowercaseLettersNonConst[static_cast<uint32_t>(UppercaseLetterIndex::LetterA)] = c;
    }
    std::cout << "Strong Enum array write with static_cast:                 " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        LowercaseLettersNonConst[UppercaseLetterIndex::LetterA] = c;
    }
    std::cout << "Strong Enum EnumeratedArray write:                        " << t.elapsed() - time << " seconds" << std::endl;


    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        LowercaseLettersNonConst[+UppercaseLetterIndex::LetterA] = c;
    }
    std::cout << "Strong Enum EnumeratedArray write with plus:              " << t.elapsed() - time << " seconds" << std::endl;
}

void bitwiseOperations()
{
    Timer t;
    volatile char c = 0;
    size_t loops = 12000000000;

    std::cout << std::endl << "Performing a set of bitwise operations " << loops << " times" << std::endl;


    volatile uint32_t _t0 = 0;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        uint32_t t0 = _t0;
        t0 = static_cast<uint32_t>(~(((t0 | 1) & 2) ^ 4));
    }
    auto time = t.elapsed();
    std::cout << "Control bitwise operations:                               " << t.elapsed() << " seconds" << std::endl << std::endl;


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
        t2 = static_cast<FlagExample>(~(((t2 | FlagExample::Flag1) & FlagExample::Flag2) ^ FlagExample::Flag4));
    }
    std::cout << "Strong Enum bitwise operations:                           " << t.elapsed() - time << " seconds" << std::endl;


    volatile FlagExample c3 = FlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        FlagExample t3 = c3;
        t3 = static_cast<FlagExample>(~(((t3 | FlagExample2::Flag1) & FlagExample2::Flag2) ^ FlagExample2::Flag4));
    }
    std::cout << "Mixing Strong Enum bitwise operations:                    " << t.elapsed() - time << " seconds" << std::endl;
}
