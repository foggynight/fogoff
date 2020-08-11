#include "circular_key.h"

KeyNode *create_circular_key(char *key) {
	KeyNode *head = calloc(1, sizeof(KeyNode));
	head->val = *key;

	KeyNode *curr, *last = head;
	for (char *k = key+1; *k != '\0'; ++k) {
		curr = calloc(1, sizeof(KeyNode));
		curr->val = *k;
		last->next = curr;
		last = curr;
	}
	last->next = head;

	return head;
}