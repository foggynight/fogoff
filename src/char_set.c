// Copyright (C) 2020 Robert Coffey
// Released under the GPLv2 license

#include <string.h>

#include "char_set.h"

void create_char_set(char *char_set)
{
    strcpy(char_set, "\t\n");
    for (int i = 0; i < CHARSETLEN-3; ++i)
        char_set[i+3] = ' ' + i;
}
