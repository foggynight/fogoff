#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXKEYLEN    1024
#define MAXSTRLEN    MAXKEYLEN + 1

#define stringify(x) #x
#define str(x) stringify(x)

int is_encrypt_option(char *str);
int is_decrypt_option(char *str);
char *get_key(void);

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("%s: invalid use: too few arguments\n", argv[0]);
		return 1;
	} else if (argc > 2) {
		printf("%s: invalid use: too many arguments\n", argv[0]);
		return 1;
	}

	FILE *input_fp = stdin;
	FILE *output_fp = stdout;
	char *key = get_key();

	if (is_encrypt_option(argv[1])) {
		// encrypt input
	} else if (is_decrypt_option(argv[1])) {
		// decrypt input
	} else {
		printf("%s: invalid argument: %s\n", argv[0], argv[1]);
	}

	return 0;
}

int is_encrypt_option(char *str) {
	return strcmp(str, "-e") == 0 || strcmp(str, "--encrypt") == 0;
}

int is_decrypt_option(char *str) {
	return strcmp(str, "-d") == 0 || strcmp(str, "--decrypt") == 0;
}

char *get_key(void) {
	FILE *key_file = fopen("key.txt", "r");
	if (!key_file) return NULL;

	char *key = calloc(MAXSTRLEN, sizeof(char));
	fscanf(key_file, "%" str(MAXKEYLEN) "s", key);
	
	fclose(key_file);
	return key;
}
