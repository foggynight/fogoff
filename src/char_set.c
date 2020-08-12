#include "char_set.h"

void create_char_set(char *char_set) {
	char_set[0] = '\n';
	for (int i = 0; i < CHARSETLEN-1; ++i) {
		char_set[i+1] = ' ' + i;
	}
}
