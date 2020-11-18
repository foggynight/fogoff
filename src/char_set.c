// SPDX-License-Identifier: GPL-2.0
// Copyright (C) 2020 Robert Coffey

#include <string.h>

#include "char_set.h"

void create_char_set(char *char_set)
{
    strcpy(char_set, "\n\r\t");
    for (int i = 0; i < CHARSETLEN-3; ++i)
        char_set[i+3] = ' ' + i;
}
