#ifndef ALGORITHM_COLLECTIONS_H
#define ALGORITHM_COLLECTIONS_H

// Libs
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

// Linked List

// Structs
typedef struct node {
    void *data;
    struct node *next;
    struct node *prev;
} node;

typedef struct {
    int size;
    node *head;
    node *tail;
} linklst;

extern linklst *linklst_init();

extern void linklst_append(linklst *list, void *data, size_t);

extern void linklst_prepend(linklst *link, void *data, size_t);

extern void linklst_pop(linklst *list);

extern node *linklst_find(linklst *list, void *data, bool(*fptr)(void *, void *));

extern void linklst_free(linklst **list);

extern void linklst_print(linklst *list, void(*fptr)(void *));

// Array List

// Printing
extern void print_string(void *s);

extern bool compare_string(void *s1, void *s2);

#endif //ALGORITHM_COLLECTIONS_H
