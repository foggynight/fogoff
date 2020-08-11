#include <stdio.h>

/** 
 * Encrypt file in strlen(key) sized blocks.
 * 
 * @param FILE* input_fp Input stream.
 * @param FILE* output_fp Output stream.
 * @param char* key Encryption key.
 */
void encrypt_file(FILE *input_fp, FILE *output_fp, char *key);

/** 
 * Encrypt block of block_size characters.
 * 
 * @param char* block Block of characters.
 * @param int block_size Size of block argument.
 * 
 * @return block if successful, else NULL.
 */
char *encrypt_block(char *block, int block_size);
