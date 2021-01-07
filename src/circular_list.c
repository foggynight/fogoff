// Copyright (C) 2020-2021 Robert Coffey
// Released under the GPLv2 license

#include "circular_list.h"

Node *create_circular_list(char *str)
{
    Node *head = calloc(1, sizeof(Node));
    head->val = *str;

    Node *curr, *last = head;
    for (char *k = str+1; *k != '\0'; ++k) {
        curr = calloc(1, sizeof(Node));
        curr->val = *k;
        last->next = curr;
        last = curr;
    }
    last->next = head;

    return head;
}

void destroy_circular_list(Node *node)
{
    Node *temp = node;
    Node *next = node->next;

    while (next != node) {
        temp = next;
        next = next->next;
        free(temp);
    }

    free(node);
}
