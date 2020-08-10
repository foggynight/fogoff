#include <stdio.h>
#include <string.h>

int encrypt_option(char *str);
int decrypt_option(char *str);

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("%s: invalid use: too few arguments", argv[0]);
	} else if (argc > 2) {
		printf("%s: invalid use: too many arguments", argv[0]);
	}

	FILE *input_fp = stdin;
	FILE *output_fp = stdout;

	if (encrypt_option(argv[1])) {
		// encrypt input
	} else if (decrypt_option(argv[1])) {
		// decrypt input
	} else {
		printf("%s: invalid argument: %s", argv[0], argv[1]);
	}

	return 0;
}

int encrypt_option(char *str) {
	return strcmp(str, "-e") == 0 || strcmp(str, "--encrypt") == 0;
}

int decrypt_option(char *str) {
	return strcmp(str, "-d") == 0 || strcmp(str, "--decrypt") == 0;
}
