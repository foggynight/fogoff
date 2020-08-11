#include <stdlib.h>

typedef struct keynode {
	char val;
	struct keynode *next;
} KeyNode;

/**
 * Create a circular linked list of KeyNodes
 * using the given key. Must be destroyed using
 * the destroy_circular_key function.
 * 
 * @param key Key to generate list from.
 * 
 * @return Head of circular linked list.
 */
KeyNode *create_circular_key(char *key);

/**
 * Destroy a circular linked list.
 * 
 * @param list_head Head of the list to destroy.
 */
void destroy_circular_key(KeyNode *list_head);