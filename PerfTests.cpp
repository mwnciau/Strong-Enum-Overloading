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
    volatile char c = 0;
    size_t loops = 125000000;


    std::cout << std::endl << "Iterating through all values " << loops << " times using a for loop." << std::endl;

    volatile auto t0 = 0;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (uint32_t i = t0; i < 26; ++i)
        {
            c = 0;
        }
    }
    auto time = t.elapsed();
    std::cout << "Control array iteration:                          " << t.elapsed() << " seconds" << std::endl << std::endl;

    c = 0;
    volatile auto t1 = CEnumLowercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (uint32_t i = t1; i < CEnumLowercaseLetterIndex::Count; ++i)
        {
            c = LowercaseLetters[i];
        }
    }
    std::cout << "C Enum array iteration:                          " << t.elapsed() - time << " seconds" << std::endl;

    c = 0;
    volatile auto t2 = LowercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto i = t2; i < LowercaseLetterIndex::Count; ++i)
        {
            c = LowercaseLetters[+i];
        }
    }
    std::cout << "Strong Enum array iteration with plus:           " << t.elapsed() - time << " seconds" << std::endl;

    c = 0;
    volatile auto t3 = LowercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto i = t3; i < LowercaseLetterIndex::Count; ++i)
        {
            c = LowercaseLetters[static_cast<uint32_t>(i)];
        }
    }
    std::cout << "Strong Enum array iteration with static_cast:    " << t.elapsed() - time << " seconds" << std::endl;

    c = 0;
    volatile auto t4 = UppercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto i = t4; i < UppercaseLetterIndex::Count; ++i)
        {
            c = UppercaseLetters[i];
        }
    }
    std::cout << "Strong Enum EnumeratedArray iteration:           " << t.elapsed() - time << " seconds" << std::endl;

    c = 0;
    volatile auto t5 = UppercaseLetterIndex::Init;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        for (auto i = t5; i < UppercaseLetterIndex::Count; ++i)
        {
            c = UppercaseLetters[+i];
        }
    }
    std::cout << "Strong Enum EnumeratedArray iteration with plus: " << t.elapsed() - time << " seconds" << std::endl;
}

void arrayAccess()
{
    Timer t;
    volatile char c = 0;
    size_t loops = 3000000000;


    std::cout << std::endl << "Accessing array value " << loops << " times" << std::endl;

    volatile auto _t0 = 0;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t0 = _t0;
        c = t0;
    }
    auto time = t.elapsed();
    std::cout << "Control array access:                             " << t.elapsed() << " seconds" << std::endl << std::endl;

    c = 0;
    volatile CEnumLowercaseLetterIndex _t1 = CEnumLowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t1 = _t1;
        c = LowercaseLetters[t1];
    }
    std::cout << "C Enum array access:                              " << t.elapsed() - time << " seconds" << std::endl;

    c = 0;
    volatile LowercaseLetterIndex _t2 = LowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t2 = _t2;
        c = LowercaseLetters[+t2];
    }
    std::cout << "Strong Enum array access with plus:               " << t.elapsed() - time << " seconds" << std::endl;

    c = 0;
    volatile LowercaseLetterIndex _t3 = LowercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t3 = _t3;
        c = LowercaseLetters[static_cast<uint32_t>(t3)];
    }
    std::cout << "Strong Enum array access with static_cast:        " << t.elapsed() - time << " seconds" << std::endl;

    c = 0;
    volatile UppercaseLetterIndex _t4 = UppercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t4 = _t4;
        c = UppercaseLetters[t4];
    }
    std::cout << "Strong Enum EnumeratedArray access:               " << t.elapsed() - time << " seconds" << std::endl;

    c = 0;
    volatile UppercaseLetterIndex _t5 = UppercaseLetterIndex::LetterA;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        auto t5 = _t5;
        c = UppercaseLetters[+t5];
    }
    std::cout << "Strong Enum EnumeratedArray access with plus:     " << t.elapsed() - time << " seconds" << std::endl;
}

void bitwiseOperations()
{
    Timer t;
    size_t loops = 5000000000;

    volatile char c = 0;

    std::cout << std::endl << "Performing a set of bitwise operations " << loops << " times" << std::endl;


    volatile uint32_t _t0 = 0;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        uint32_t t0 = _t0;
        t0 = static_cast<uint32_t>(~(((t0 | 1) & 2) ^ 4));
    }
    auto time = t.elapsed();
    std::cout << "Control bitwise operations:                       " << t.elapsed() << " seconds" << std::endl << std::endl;

    volatile CEnumFlagExample c1 = CEnumFlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        CEnumFlagExample t1 = c1;
        t1 = static_cast<CEnumFlagExample>(~(((c1 | CEnumFlagExample::Flag1) & CEnumFlagExample::Flag2) ^ CEnumFlagExample::Flag4));
    }
    std::cout << "C Enum bitwise operations:                        " << t.elapsed() - time << " seconds" << std::endl;

    volatile FlagExample c2 = FlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        FlagExample t2 = c2;
        t2 = static_cast<FlagExample>(~(((t2 | FlagExample::Flag1) & FlagExample::Flag2) ^ FlagExample::Flag4));
    }
    std::cout << "Strong Enum bitwise operations:                   " << t.elapsed() - time << " seconds" << std::endl;

    volatile FlagExample c3 = FlagExample::Null;
    t.reset();
    for (size_t i = 0; i < loops; ++i)
    {
        // prevent caching of the result
        FlagExample t3 = c3;
        t3 = static_cast<FlagExample>(~(((t3 | FlagExample2::Flag1) & FlagExample2::Flag2) ^ FlagExample2::Flag4));
    }
    std::cout << "Mixing Strong Enum bitwise operations:            " << t.elapsed() - time << " seconds" << std::endl;
}
