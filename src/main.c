/**
 * fogoff - File encryption utility
 *
 * Copyright (C) 2020-2021 Robert Coffey
 * Released under the MIT license
 **/

#include <stdio.h>

#include "file.h"

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "fogoff: invalid arguments\n");
        return 0;
    }

    char *file_content = file_read(argv[2]);
    printf("*** START: FILE CONTENT ***\n"
           "%s\n"
           "*** END: FILE CONTENT ***\n",
           file_content);

    return 0;
}
