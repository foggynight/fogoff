#include <stdio.h>

/** 
 * Encrypt file in using the key to rotate
 * each character of the input stream.
 * 
 * @param input_fp Input stream.
 * @param output_fp Output stream.
 * @param key Encryption key.
 */
void encrypt_file(FILE *input_fp, FILE *output_fp, char *key);

/**
 * Encrypt a single character, rotating it
 * based on align and the key.
 * 
 * @param input Character to encrypt.
 * @param key Value to rotate input by.
 * @param align Direction to rotate input.
 * 
 * @return Encrypted character.
 */
char encrypt_char(char input, char key, char align);
