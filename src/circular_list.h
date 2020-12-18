// Copyright (C) 2020 Robert Coffey
// Released under the GPLv2 license

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
 * @params
 * - key {char*}: Key to generate list from.
 *
 * @return {Node*}: Head of circular linked list.
 */
Node *create_circular_list(char *str);

/**
 * Destroy a circular linked list.
 *
 * @params
 * - list_head {Node*}: Head of the list to destroy.
 */
void destroy_circular_list(Node *list_node);
