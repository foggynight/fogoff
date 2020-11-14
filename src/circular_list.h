#include <stdlib.h>

typedef struct node {
    char val;
    struct node *next;
} Node;

/**
 * Create a circular linked list of Nodes using
 * the given key. Must be destroyed using the
 * destroy_circular_list function.
 *
 * @param key Key to generate list from.
 *
 * @return Head of circular linked list.
 */
Node *create_circular_list(char *str);

/**
 * Destroy a circular linked list.
 *
 * @param list_head Head of the list to destroy.
 */
void destroy_circular_list(Node *list_node);
