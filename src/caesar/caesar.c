// Copyright (C) 2021 Robert Coffey
// Released under the MIT license

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "caesar.h"

#define CHARSET_LENGTH (int)('~' - ' ' + 3)
static char char_set[] = {
    ' ', '!', '"', '#', '$', '%', '&','\'', '(', ')', '*', '+', ',',
    '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
    'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[','\\', ']', '^', '_', '`',
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
    'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '{', '|', '}', '~','\t','\n'
};

/**
 * Convert a key string into its integer representation, storing it in
 * the key value pointer.
 *
 * This function returns an integer value that is non-zero on success,
 * with failure indicating that the key_val was out of range.
 *
 * The key string must contain an integer preceded by nothing but
 * whitespace and the sign of the integer, with a null terminator
 * directly following it.
 *
 * @param key_str      String containing the key to convert
 * @param key_val_ptr  Address of the integer variable to store the
 *                     converted value in
 *
 * @return Non-zero indicates success
 **/
static int get_key_val(char *key_str, int *key_val_ptr);

/**
 * Rotate a character around the character set by a number of positions
 * equal to the key value.
 *
 * If key_val is greater than zero the set is traversed to the right, if
 * key_val is less than zero the set it traversed to the left.
 *
 * @param chr      Character to rotate around the character set
 * @param key_val  Key value, the magnitude represents the number of
 *                 steps to rotate around the set, and the sign
 *                 represents the direction to rotate
 *
 * @return Rotated character
 **/
static char rot_char(char chr, int key_val);

int caesar_encrypt(char *data, char *key)
{
    int key_val;

    if (data == NULL || key == NULL)
        return 0;

    if (!get_key_val(key, &key_val))
        return 0;

    key_val %= CHARSET_LENGTH;

    for (size_t i = 0; i < strlen(data); ++i)
        data[i] = rot_char(data[i], key_val);

    return 1;
}

static int get_key_val(char *key_str, int *key_val_ptr)
{
    char *end_ptr;

    errno = 0;
    *key_val_ptr = strtol(key_str, &end_ptr, 10);

    return *end_ptr == '\0' && errno != ERANGE;
}

static char rot_char(char chr, int key_val)
{
    int index;

    if (chr == '\t' || chr == '\n')
        index = (chr - '\t' + '~' - ' ' + 1 + key_val) % CHARSET_LENGTH;
    else
        index = (chr - ' ' + key_val) % CHARSET_LENGTH;

    if (index < 0)
        index += CHARSET_LENGTH;

    return char_set[index];
}
