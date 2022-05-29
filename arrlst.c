#include "collections.h"

arrlst *arrlst_init(size_t block_size) {
    arrlst *sptr = malloc(sizeof(arrlst));
    sptr->size = 0;
    sptr->block_size = block_size;
    sptr->buf = 10;
    sptr->list = malloc(block_size * 10);

    return sptr;
}

void add(arrlst *list, void *data) {
    if (list->size < list->buf) {
        memcpy(list->list + list->size * list->block_size, data, list->block_size);
        list->size++;
    } else {
        resize_list(list);
        add(list, data);
    }
}

void resize_list(arrlst *list) {
    list->list = realloc(list->list, list->block_size * list->buf * 2);
    list->buf *= 2;
}

void arrlst_free(arrlst *list) {
    if (list) {
        free(list->list);
        free(list);
    }
}