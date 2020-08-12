#include "bin_search.h"

#define CHARSETLEN	(int)('~' - ' ' + 2)

/**
 * Define an array and fill it with the program's character set.
 * 
 * @param x Name of the array.
 */
#define get_char_set(x) char (x)[CHARSETLEN]; create_char_set((x));

/**
 * Search for the given value in the array.
 * 
 * @param x Array to search through.
 * @param y Target value.
 * 
 * @return Index of target if found, else -1.
 */
#define get_char_index(x, y) (char)(bin_search((x), (y), 0, CHARSETLEN-1))

/** 
 * Fill an array with the program's character set.
 * 
 * @param char_set Array to fill.
 */
void create_char_set(char *char_set);
