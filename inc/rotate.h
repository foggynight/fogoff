// Copyright (C) 2020 Robert Coffey
// Released under the GPLv2 license

#include <stdio.h>

/**
 * Rotate a file in using the key to rotate each character of the input
 * stream.
 *
 * @params
 * - input_fp {FILE*}: Input stream.
 * - output_fp {FILE*}: Output stream.
 * - key {CHAR*}: Encryption key.
 * - align {int}: Direction of the rotation.
 */
void rotate_file(FILE *input_fp, FILE *output_fp, char *key, int align);

/**
 * Rotate a single character by the key value, in the direction of
 * align, around char_set.
 *
 * @params
 * - input {int}: Character to rotate.
 * - key {int}: Value to rotate input by.
 * - align {int}: Direction to rotate input.
 * - char_set {char*}: Characters to rotate around.
 *
 * @return {char}: Encrypted character.
 */
char rotate_char(int input, int key, int align, char *char_set);
