#include "bin_search.h"

#define CHARSETLEN	'~' - ' ' + 2

#define get_char_set(x) char (x)[CHARSETLEN]; create_char_set((x));
#define get_char_index(x, y) (char)(bin_search((x), (y), 0, CHARSETLEN-1))

void create_char_set(char *char_set);
