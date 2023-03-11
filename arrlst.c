#include <stdlib.h>
#include <string.h>

#include "collections.h"

/**
 * Initializes an array list with a default size of 10
 * @param block_size the type that should be used throughout the list
 * @return pointer to the new list
 */
arrlst *arrlst_init(size_t block_size) {
    arrlst *sptr = malloc(sizeof(arrlst));
    sptr->size = 0;
    sptr->block_size = block_size;
    sptr->buf = 10;
    sptr->list = calloc(block_size,  10);

    return sptr;
}

/**
 * Adds an element to the list and resizes it if necessary
 * @param list to arrlst_add to
 * @param data to arrlst_add to list
 */
void arrlst_add(arrlst *list, void *data) {
    if (list->size < list->buf) {
        memcpy(list->list + list->size * list->block_size, data, list->block_size);
        list->size++;
    } else {
        resize_arrlst(list);
        arrlst_add(list, data);
    }
}

/**
 * Doubles the size allocated for the list with the chosen block size
 * @param list to expand
 */
void resize_arrlst(arrlst *list) {
    list->list = realloc(list->list, list->block_size * list->buf * 2);
    list->buf *= 2;
}

/**
 * Frees the list from memory
 * @param list to free
 */
void arrlst_free(arrlst *list) {
    if (list) {
        free(list->list);
        free(list);
    }
}