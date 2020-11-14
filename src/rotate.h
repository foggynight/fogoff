#include <stdio.h>

/**
 * Rotate a file in using the key to rotate
 * each character of the input stream.
 *
 * @param input_fp Input stream.
 * @param output_fp Output stream.
 * @param key Encryption key.
 * @param align Direction of the rotation.
 */
void rotate_file(FILE *input_fp, FILE *output_fp, char *key, int align);

/**
 * Rotate a single character by the key value,
 * in the direction of align, around char_set.
 *
 * @param input Character to rotate.
 * @param key Value to rotate input by.
 * @param align Direction to rotate input.
 * @param char_set Characters to rotate around.
 *
 * @return Encrypted character.
 */
char rotate_char(int input, int key, int align, char *char_set);
