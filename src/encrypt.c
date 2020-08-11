#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "encrypt.h"

void encrypt_file(FILE *input_fp, FILE *output_fp, char *key) {
	size_t block_size = strlen(key);
	char *block = malloc(block_size+1);
	
	while (fgets(block, block_size+1, input_fp)) {
		int count = strlen(block);
		if (block[count-1] == '\n') {
			--count;
			block[count] = '\0';
		}
		block = encrypt_block(block, count);
		fwrite(block, sizeof(char), count, output_fp);
	}

	free(block);
}

char *encrypt_block(char *block, int block_size) {
	return block;
}
