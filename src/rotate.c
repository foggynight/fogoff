#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "char_set.h"
#include "circular_list.h"
#include "config.h"
#include "rotate.h"

void rotate_file(FILE *input_fp, FILE *output_fp, char *key, int align) {
	Node *key_node = create_circular_list(key);
	get_char_set(char_set);

	int buffer;
	while ((buffer = fgetc(input_fp)) != EOF) {
		char new_char = rotate_char(buffer, key_node->val, align, char_set);

		if (buffer == '\n' || new_char == '\n') {
			int c;
			if ((c = fgetc(input_fp)) != EOF) {
				ungetc(c, input_fp);
				fputc(new_char, output_fp);
			} 
		} else {
			fputc(new_char, output_fp);
		}

		key_node = key_node->next;
		align = -align;
	}

	fputc('\n', output_fp);
	destroy_circular_list(key_node);
}

char rotate_char(int input_val, int key_val, int align, char *char_set) {
	input_val = get_char_index(char_set, input_val);
	key_val = get_char_index(char_set, key_val);
	int new_index = (input_val + align*key_val) % CHARSETLEN;
	if (new_index < 0) {
		new_index = CHARSETLEN + new_index;
	}
	return char_set[new_index];
}
