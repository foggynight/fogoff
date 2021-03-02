// Copyright (C) 2020-2021 Robert Coffey
// Released under the MIT license

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

char *file_read(char *path)
{
    FILE *fp;
    struct stat st;
    char *file_content;

    if (stat(path, &st)) {
        fprintf(stderr, "fogoff: stat failed on file: %s\n", path);
        return NULL;
    }

    if (st.st_size < 0) {
        fprintf(stderr, "fogoff: invalid file size: %s\n", path);
        return NULL;
    }

    fp = fopen(path, "r");
    if (!fp) {
        fprintf(stderr, "fogoff: cannot open file: %s\n", path);
        return NULL;
    }

    file_content = malloc(st.st_size);
    if (!file_content) {
        fprintf(stderr, "fogoff: memory allocation failed\n");
        return NULL;
    }

    // Note: st.st_size has been verified above to be non-negative
    if (fread(file_content, sizeof(char), st.st_size, fp) != (size_t)st.st_size) {
        fprintf(stderr, "fogoff: file read failed\n");
        return NULL;
    }

    return file_content;
}
