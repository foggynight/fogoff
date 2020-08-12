#include "bin_search.h"

#define CHARSETLEN	'~' - ' ' + 2

#define get_char_set() char char_set[CHARSETLEN]; create_char_set(char_set);
#define get_char_index(x) (char)(bin_search(char_set, (x)))

void create_char_set(char *char_set);
