// Copyright (C) 2020-2021 Robert Coffey
// Released under the GPLv2 license

#include "bin_search.h"

#define CHARSETLEN (int)('~' - ' ' + 2)

/**
 * Define an array and fill it with the program's character set.
 *
 * @params
 * - x {symbol}: Name of the array to define.
 */
#define get_char_set(x) char (x)[CHARSETLEN]; create_char_set((x));

/**
 * Search for the given value in the array.
 *
 * @params
 * - x {char*}: Array to search through.
 * - y {char}: Target value.
 *
 * @return {int}: Index of target if found, else -1.
 */
#define get_char_index(x, y) (char)(bin_search((x), (y), 0, CHARSETLEN-1))

/**
 * Fill an array with the program's character set.
 *
 * @params
 * - char_set {char*}: Array to fill.
 */
void create_char_set(char *char_set);
