#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "encrypt.h"
#include "circular_list.h"

#include "char_set.c"

void encrypt_file(FILE *input_fp, FILE *output_fp, char *key) {
	Node *key_node = create_circular_list(key);
	get_char_set(char_set);

	int buffer;
	char align = 1;
	while ((buffer = fgetc(input_fp)) != EOF) {
		fputc(encrypt_char(buffer, key_node->val, align), output_fp);
		key_node = key_node->next;
		align = -align;
	}

	destroy_circular_list(key_node);
}

char encrypt_char(char input_val, char key_val, char align) {
	return input_val;
}
