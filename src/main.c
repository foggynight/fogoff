#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
#include "encrypt.h"
// #include "decrypt.h"

#define stringify(x) #x
#define str(x) stringify(x)

int is_encrypt_option(char *str);
int is_decrypt_option(char *str);
int is_key_option(char *str);
char *get_key(char *dest);

typedef struct {
	unsigned int encrypt : 1;
	unsigned int decrypt : 1;
	unsigned int key_arg : 1;
} Flags;

enum { ENCRYPT, DECRYPT, KEY, INVALID };

char key[KEYSTRLEN];

int main(int argc, char **argv) {
	char *get_key(char *dest);
	Flags get_args(int argc, char **argv);

	Flags flags = get_args(argc, argv);

	if (!flags.key_arg) {
		if (!get_key(key)) {
			fprintf(stderr,
				"%s: error: cannot read key from key.txt\n",
				argv[0]);
			return 1;
		}
	}

	if (strlen(key) == 0) {
		fprintf(stderr, "%s: invalid use: no key provided\n", argv[0]);
		return 1;
	}
	
	FILE *input_fp = stdin;
	FILE *output_fp = stdout;
	if (flags.encrypt) {
		encrypt_file(input_fp, output_fp, key);
	} else if (flags.decrypt) {
		// decrypt input
	} else {
		printf("%s: invalid use: neither encrypt (-e) nor decrypt (-d) selected\n",
			argv[0]);
		return 1;
	}

	return 0;
}

char *get_key(char *dest) {
	FILE *key_file = fopen("key.txt", "r");
	if (!key_file) return NULL;

	fscanf(key_file, "%" str(MAXKEYLEN) "s", dest);

	fclose(key_file);
	return dest;
}

int is_encrypt_option(char *str) {
	return strcmp(str, "-e") == 0 || strcmp(str, "--encrypt") == 0;
}

int is_decrypt_option(char *str) {
	return strcmp(str, "-d") == 0 || strcmp(str, "--decrypt") == 0;
}

int is_key_option(char *str) {
	return strcmp(str, "-k") == 0 || strcmp(str, "--key") == 0;
}

char option_type(char *str) {
	if (is_encrypt_option(str)) return ENCRYPT;
	else if (is_decrypt_option(str)) return DECRYPT;
	else if (is_key_option(str)) return KEY;
	else return INVALID;
}

Flags get_args(int argc, char **argv) {
	Flags flags = {0};

	for (char **arg_ptr = argv+1; argc > 1; --argc, ++arg_ptr) {
		switch (option_type(*arg_ptr)) {
		case ENCRYPT:
			if (flags.decrypt) {
				fprintf(stderr,
					"%s: invalid use: encrypt and decrypt selected\n",
					argv[0]);
				exit(1);
			} else {
				flags.encrypt = 1;
			}
			break;
		case DECRYPT:
			if (flags.encrypt) {
				fprintf(stderr,
					"%s: invalid use: encrypt and decrypt selected\n",
					argv[0]);
				exit(1);
			} else {
				flags.decrypt = 1;
			}
			break;
		case KEY:
			if (flags.key_arg) {
				fprintf(stderr,
					"%s: invalid use: multiple keys detected\n",
					argv[0]);
				exit(1);
			} else if (--argc <= 1) {
				fprintf(stderr,
					"%s: invalid use: key option selected but no key provided\n",
					argv[0]);
				exit(1);
			} else {
				++arg_ptr;
				if (strlen(*arg_ptr) > MAXKEYLEN) {
					fprintf(stderr,
						"%s: invalid use: key too long, max length: %d\n",
						argv[0], MAXKEYLEN);
					exit(1);
				} else {
					flags.key_arg = 1;
					strcpy(key, *arg_ptr);
				}
			}
			break;
		default:
			fprintf(stderr,
				"%s: invalid argument: %s\n",
				argv[0], *arg_ptr);
			exit(1);
			break;
		}
	}

	return flags;
}
