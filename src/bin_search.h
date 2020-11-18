// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2020 Robert Coffey

#include <stdlib.h>

/**
 * Binary search on an array of characters.
 *
 * @params
 * - arr {char*}: The array to search.
 * - target {char}: The target value.
 * - left {int}: The left border of the search.
 * - right {int}: The right border of the search.
 *
 * @return {int}: Index of target if found, else -1.
 */
int bin_search(char *arr, char target, int left, int right);
