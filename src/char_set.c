#define CHARSETLEN	'~' - ' ' + 2

#define get_char_set(x) char char_set[CHARSETLEN]; create_char_set(x);

void create_char_set(char *char_set) {
	char_set[0] = '\n';
	for (int i = 1; i < CHARSETLEN; ++i) {
		char_set[i] = ' ' + i;		
	}
}
