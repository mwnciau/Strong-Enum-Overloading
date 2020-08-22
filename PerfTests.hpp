#pragma once

/**
 * This test will iterate through each element of an enum. This includes incrementing the index and accessing an array
 * using the enum/type as an index. The index is marked volatile so the compiler doesn't try to cache the result.
 */
void iterateEnums();

/**
 * This test will set a volatile variable to a value using the result of accessing an array. The index used is marked
 * volatile so the compiler doesn't try to cache it.
 */
void arrayAccess();

/**
 * This test is almost identicle to arrayAccess except it doesn't mark the index as volatile, so we can see if the
 * compiler is better at caching one type over another
 */
void arrayCache();

/**
 * This test will perform a series of bitwise operations on various types. The variable used is marked as volatile so
 * the compiler cannot optimise it out.
 */
void bitwiseOperations();