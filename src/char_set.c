#include "char_set.h"

void create_char_set(char *char_set) {
    char_set[0] = '\t';
    char_set[1] = '\n';
    char_set[2] = '\r';
    for (int i = 0; i < CHARSETLEN-3; ++i) {
        char_set[i+3] = ' ' + i;
    }
}
