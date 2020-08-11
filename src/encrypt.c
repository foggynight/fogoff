#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "encrypt.h"
#include "circular_list.h"

void encrypt_file(FILE *input_fp, FILE *output_fp, char *key) {
	Node *key_node = create_circular_list(key);	

	int buffer;
	char align = 1;

	while ((buffer = fgetc(input_fp)) != EOF) {
		buffer = encrypt_char(buffer, key_node->val, align);
		key_node = key_node->next;
		align = -align;
	}

	destroy_circular_list(key_node);
}

char encrypt_char(char input_val, char key_val, char align) {
	
}
