/**
 * fogoff - File encryption utility
 *
 * Copyright (C) 2020-2021 Robert Coffey
 * Released under the MIT license
 **/

#include <stdio.h>

#include "caesar/caesar.h"
#include "file.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "fogoff: invalid arguments\n");
        return 0;
    }

    char *file_content = file_read(argv[1]);
    caesar_encrypt(file_content, "1");
    caesar_encrypt(file_content, "-1");

    printf("%s\n", file_content);

    return 0;
}
