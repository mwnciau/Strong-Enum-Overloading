# Strong Enum Overloading

A collection of macros and tests working with C++ strong enums to broaden their possible usage using operator overloading.

## Macros

Macros to enable strong enum functionality are defined in [`Macros.hpp`](./Macros.hpp). In the following definitions, `<ENUM>` is the name of a strong enum, `<TYPE>` is its underlying type and `<OTHER>` is another enum or compatible type.

Note that attempting to use both the bitwise and arithmetic macros will cause errors, but it is possible to use the compatibility macros between bitwise and arithmetic strong enums, providing both macros aren't used for a `<ENUM>` - `<OTHER>` pair.


##### `ENABLE_ENUM_PLUS_SHORTCUT(<ENUM>, <TYPE>)`

Overloads the unary `+` operator to return an enum's underlying value.


##### `ENABLE_ENUM_BITWISE_OPERATIONS(<ENUM>, <TYPE>)`

Overloads the bitwise operators for `<ENUM>`: `|`, `&`, `^`, `~`, `|=`, `&=`, `^=`, `>>` and `<<`. Additionally, it overloads the `!` unary operator to return true if the current value is `<ENUM>::Null`.


##### `ENABLE_ENUM_BITWISE_COMPATIBILITY(<ENUM>, <OTHER>, <TYPE>)`

Overloads the bitwise operators to allow `<OTHER>` to be on the rhs of the binary operators: `|`, `&`, `^`, `|=`, `&=` and `^=`. Additionally, the comparison operators are defined between the two types: `==` and `!=`.

`<OTHER>` can be another strong enum, or it could be a type compatible with the underlying type of `<ENUM>`.


##### `ENABLE_ENUM_ARITHMETIC_OPERATIONS(<ENUM>, <TYPE>)`

Overloads the arithmetic operators for `<ENUM>`: `+`, `-`, `*`, `/`, `++`, `--`, `+=`, `-=`, `*=` and `/=`. Note that the comparison operations, `==`, `!=`, `>`, `<`, `>=` and `<=`, work without overloading.


##### `ENABLE_ENUM_ARITHMETIC_COMPATIBILITY(<ENUM>, <OTHER>, <TYPE>)`

Overloads the arithmetic operators to allow `<OTHER>` to be on the rhs of the arithmetic operators: `+`, `-`, `*`, `/`, `+=`, `-=`, `*=` and `/=`. Additionally, the comparison operators are defined between the two types: `==`, `!=`, `>`, `<`, `>=` and `<=`.

`<OTHER>` can be another strong enum, or it could be a type compatible with `<TYPE>`.

## `EnumeratedArray<TYPE, ENUM>` and `ConstEnumeratedArray<TYPE, ENUM>` class

As defined in [`Enums.hpp`](./Enums.hpp), these classes are simple wrapper for arrays and const array that allow you to use a strong enum as well as normal integer indices to access elements in the array.

## Usage

Full usage examples can be found in [`Main.cpp`](./Main.cpp). Excerpts are shown below.

#### Flags
```
enum class FlagExample : uint32_t
{
    Null = 0,
    Flag1 = 1,
    Flag2 = 2,
    ...
}
ENABLE_ENUM_BITWISE_OPERATORS(FlagExample, uint32_t);
ENABLE_ENUM_BITWISE_COMPATIBILITY(FlagExample, uint32_t, uint32_t);
ENABLE_ENUM_PLUS_SHORTCUT(FlagExample, uint32_t);

FlagExample f1 = FlagExample::Flag1, f2 = 0;
if ( !((f1 & ~f2) ^ FlagExample::Flag4 )
{
    f2 |= 8;
}
```

#### Array indexing
```
enum class LowercaseLetterIndex : uint32_t
{
    Init,
    LetterA = 0,
    LetterB,
    ...
    Count
};
ENABLE_ENUM_ARITHMETIC_OPERATIONS(LowercaseLetterIndex, uint32_t);
ENABLE_ENUM_ARITHMETIC_COMPATIBILITY(LowercaseLetterIndex, UppercaseLetterIndex, uint32_t);
ENABLE_ENUM_PLUS_SHORTCUT(LowercaseLetterIndex, uint32_t);

static constexpr const char _LowercaseLetters[] = {
    'a',
    ...
};
const ConstEnumeratedArray<char, LowercaseLetterIndex> LowercaseLetters(_LowercaseLetters);

LowercaseLetterIndex lc1 = LowercaseLetterIndex::LetterH, lc2 = LowercaseLetterIndex::LetterJ;

std::cout << LowercaseLetters[lc1] << _LowercaseLetters[+(lc2 - LowercaseLetterIndex::LetterB)];
```

## Performance testing

A few performance tests are defined in [`PerfTests.cpp`](./PerfTests.cpp) to test the difference between the various ways of using strong enums as well as comparisons to the old enum style.

A sample output is provided below (built for release in x64). The only significant difference is the cost of using the `(Const)EnumeratedArray` wrapper, which is arguably worth the cost for better type safety and ease of use.

```
Performance times are relative to the control time.

Iterating through all values 400000000 times using a for loop.
Control array iteration:                                  10.7426 seconds

C Enum array iteration:                                   0.252712 seconds
Strong Enum array iteration with plus:                    -0.0314223 seconds
Strong Enum array iteration with static_cast:             -0.183256 seconds
Strong Enum ConstEnumeratedArray iteration:               -0.172771 seconds
Strong Enum ConstEnumeratedArray iteration with plus:     -0.194378 seconds
Strong Enum EnumeratedArray iteration:                    -0.0075654 seconds
Strong Enum EnumeratedArray iteration with plus:          -0.0806227 seconds

Accessing array value 26000000000 times
Control array access:                                     9.88202 seconds

C Enum array access:                                      3.28631 seconds
Strong Enum array access with plus:                       3.27055 seconds
Strong Enum array access with static_cast:                3.19699 seconds
Strong Enum ConstEnumeratedArray access:                  3.22026 seconds
Strong Enum ConstEnumeratedArray access with plus:        3.28473 seconds
Strong Enum EnumeratedArray access:                       3.39409 seconds
Strong Enum EnumeratedArray access with plus:             3.31091 seconds

Writing array value 40000000000 times
Control array write:                                      10.1319 seconds

C Enum array write:                                       -0.0303196 seconds
Strong Enum array write with plus:                        10.2083 seconds
Strong Enum array write with static_cast:                 -0.0013018 seconds
Strong Enum EnumeratedArray write:                        4.88098 seconds
Strong Enum EnumeratedArray write with plus:              4.89207 seconds

Performing a set of bitwise operations 40000000000 times
Control bitwise operations:                               10.0219 seconds

C Enum bitwise operations:                                0.189034 seconds
Strong Enum bitwise operations:                           0.132944 seconds
Mixing Strong Enum bitwise operations:                    0.0073264 seconds
```

## Changelog

This project follows [Semantic Versioning 2](https://semver.org).

- v2.0.1 (2020-08-21): Minor adjustments to tests
- v2.0.0 (2020-08-21): Renamed EnumeratedArray to ConstEnumeratedArray and added EnumeratedArray class
- v1.2.0 (2020-08-21): Added `*`, `/`, `*=`, `/=` operators to the arithmetic macros.
- v1.1.0 (2020-08-21): Added license and readme.
- v1.0.0 (2020-08-20): Initial release.

## License

Strong-Enum-Overloading is unlicensed. See [`LICENSE`](./LICENSE.md) for the full (un)licensing statement.