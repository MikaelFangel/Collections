#ifndef ALGORITHM_COLLECTIONS_H
#define ALGORITHM_COLLECTIONS_H

#include <stdbool.h>
#include <stdlib.h>

// Linked List
typedef struct node {
    void *data;
    struct node *next;
    struct node *prev;
} node;

typedef struct linklst {
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
typedef struct arrlst {
    size_t block_size;
    size_t size;
    size_t buf;
    void *list;
} arrlst;

arrlst *arrlst_init(size_t block_size);

void add(arrlst *list, void *data);

void resize_list(arrlst *list);

void arrlst_free(arrlst *list);

// Printing
extern void print_string(void *s);

extern bool compare_string(void *s1, void *s2);

#endif //ALGORITHM_COLLECTIONS_H
