#include <iostream>

#include "Enums.hpp"
#include "PerfTests.hpp"

int main()
{
    // Using: ENABLE_ENUM_BITWISE_OPERATIONS(LowercaseLetterIndex, uint32_t);
    // We have enabled arithmetic operations on LowercaseLetterIndex
    FlagExample test = (FlagExample::Flag4 ^ FlagExample::Flag8) & ~(FlagExample::Flag2 | FlagExample::Flag1);

    // Using: ENABLE_ENUM_BITWISE_COMPATIBILITY(FlagExample, FlagExample2, uint32_t);
    // We have enabled bitwise compatibility between FlagExample and FlagExample2 so we are allowed to do this:
    // (Note that the reverse is not possible in this demo because we have not enabled it)
    test &= FlagExample2::Flag4;

    // To output, we need to convert them to a primitive data type
    // We have defined some shortcuts for this, e.g. for ENUM e:
    // - +e converts it to it's underlying type (enabled by ENABLE_ENUM_PLUS_SHORTCUT(FlagExample, uint32_t))
    // - !e returns e == ENUM::Null
    std::cout << "test numerical value: " << +test << std::endl;
    std::cout << "test boolean value: " << !!test << std::endl;

    // Using: ENABLE_ENUM_BITWISE_COMPATIBILITY(FlagExample2, uint32_t, uint32_t);
    // We have enabled bitwise compatibility between FlagExample2 and uint32_t so we are allowed to do this:
    // (Note that the reverse is not possible in this demo because we have not enabled it)
    FlagExample2 test2 = FlagExample2::Null | 8;
    std::cout << "test2 numerical value: " << +test2 << std::endl;
    std::cout << "test2 boolean value: " << !!test2 << std::endl;

    LowercaseLetterIndex lc = LowercaseLetterIndex::LetterA;
    UppercaseLetterIndex uc = UppercaseLetterIndex::LetterB;

    // Here we use the plus shortcut for array access
    std::cout << "lc value: " << LowercaseLetters[+lc] << std::endl;
    std::cout << "uc value: " << UppercaseLetters[+uc] << std::endl;

    // Using: ENABLE_ENUM_ARITHMETIC_OPERATIONS(LowercaseLetterIndex, uint32_t);
    // We have enabled arithmetic operations on LowercaseLetterIndex
    LowercaseLetterIndex lc2 = lc + LowercaseLetterIndex::LetterE;

    // Using: ENABLE_ENUM_ARITHMETIC_COMPATIBILITY(LowercaseLetterIndex, UppercaseLetterIndex, uint32_t);
    // We have enabled arithmetic compatibility between FlagExample2 and uint32_t so we are allowed to do this:
    // (Note that the reverse is not possible in this demo because we have not enabled it)
    lc2 -= uc;

    std::cout << "lc2 value: " << LowercaseLetters[+lc2] << std::endl;

    // Using: ENABLE_ENUM_ARITHMETIC_COMPATIBILITY(UppercaseLetterIndex, uint32_t, uint32_t);
    // We have enabled arithmetic compatibility between UppercaseLetterIndex and uint32_t so we are allowed to do this:
    // (Note that the reverse is not possible in this demo because we have not enabled it)
    UppercaseLetterIndex uc2 = uc + 3;

    // UppercaseLetters is an EnumeratedArray that wraps a const array
    // It allows array access with either an enum or a size_t value
    std::cout << "Access uc2 by enum: " << UppercaseLetters[uc2] << std::endl;
    std::cout << "Access uc2 by value: " << UppercaseLetters[+uc2] << std::endl;

    // Comparison operations are also possible with the arithmetic functions
    std::cout << "lc2 > uc2: " << (lc2 > uc2) << std::endl;
    std::cout << "lc2 > lc: " << (lc2 < lc) << std::endl;

    // Here we show the difference between looping through an array and an Enumerated Array
    std::cout << "Loop a normal array: " << std::endl;
    for (auto i = LowercaseLetterIndex::Init; i < LowercaseLetterIndex::Count; ++i)
    {
        std::cout << LowercaseLetters[+i] << std::endl;
    }
    std::cout << "Loop an EnumeratorArray: " << std::endl;
    for (auto i = UppercaseLetterIndex::Init; i < UppercaseLetterIndex::Count; ++i)
    {
        std::cout << UppercaseLetters[i] << std::endl;
    }

    // Performance tests
    std::cout << std::endl << "Performance times are relative to the control time." << std::endl;
    iterateEnums();
    arrayAccess();
    bitwiseOperations();

    return 0;
}