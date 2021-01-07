// Copyright (C) 2020-2021 Robert Coffey
// Released under the GPLv2 license

#include <string.h>

#include "char_set.h"

void create_char_set(char *char_set)
{
    strcpy(char_set, "\t\n");
    for (int i = 2; i < CHARSETLEN; ++i)
        char_set[i] = ' ' + (i - 2);
}
