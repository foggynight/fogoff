#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"
// #include "encrypt.h"
// #include "decrypt.h"

#define stringify(x) #x
#define str(x) stringify(x)

int is_encrypt_option(char *str);
int is_decrypt_option(char *str);
int is_key_option(char *str);
char *get_key(char *dest);

struct {
	unsigned int encrypt : 1;
	unsigned int decrypt : 1;
	unsigned int key_arg : 1;
} flags;

char key[MAXKEYSTRLEN];

int main(int argc, char **argv) {
	for (char **arg_ptr = argv+1; argc > 1; --argc, ++arg_ptr) {
		if (is_encrypt_option(*arg_ptr)) {
			if (flags.decrypt) {
				printf("%s: invalid use: encrypt and decrypt selected\n", argv[0]);
				return 1;
			} else {
				flags.encrypt = 1;
			}
		} else if (is_decrypt_option(*arg_ptr)) {
			if (flags.encrypt) {
				printf("%s: invalid use: encrypt and decrypt selected\n", argv[0]);
				return 1;
			} else {
				flags.decrypt = 1;
			}
		} else if (is_key_option(*arg_ptr)) {
			if (flags.key_arg) {
				printf("%s: invalid use: multiple keys detected\n", argv[0]);
				return 1;
			} else if (--argc <= 1) {
				printf("%s: invalid use: key option selected but no key provided\n", argv[0]);
				return 1;
			} else {
				++arg_ptr;
				if (strlen(*arg_ptr) > MAXKEYSTRLEN) {
					printf("%s: invalid use: key too long, max length: %d\n", argv[0], MAXKEYLEN);
					return 1;
				} else {
					flags.key_arg = 1;
					strcpy(key, *arg_ptr);
				}
			}
		} else {
			printf("%s: invalid argument: %s\n", argv[0], *arg_ptr);
			return 1;
		}
	}

	if (!flags.key_arg) {
		get_key(key);
	}

	FILE *input_fp = stdin;
	FILE *output_fp = stdout;
	if (flags.encrypt) {
		// encrypt input
	} else if (flags.decrypt) {
		// decrypt input
	} else {
		printf("%s: invalid use: neither encrypt (-e) nor decrypt (-d) selected\n", argv[0]);
		return 1;
	}

	return 0;
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

char *get_key(char *dest) {
	FILE *key_file = fopen("key.txt", "r");
	if (!key_file) return NULL;

	fscanf(key_file, "%" str(MAXKEYLEN) "s", dest);
	
	fclose(key_file);
	return dest;
}
