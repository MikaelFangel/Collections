#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "collections.h"

/**
 * Initializes a new emtpy linked list with size 0
 * @return pointer to the new linked list
 */
linklst *linklst_init() {
    linklst *list = (linklst *) malloc(sizeof(linklst));
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;

    return list;
}

/**
 * Create a new linked list node with all values initialized
 * @return created node
 */
node *linklist_create_node() {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = NULL;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

/**
 * Adds a new node to the end of the linked list
 * @param list node should be added to
 * @param data the node should contain
 * @param size of the data.
 */
void linklst_append(linklst *list, void *data, size_t size) {
    if (list != NULL) {
        node *new_node = linklist_create_node();
        new_node->data = malloc(size);

        memcpy(new_node->data, data, size + 1);

        if (list->head == NULL) {
            list->head = new_node;
            list->tail = new_node;
        } else {
            new_node->prev = list->tail;
            list->tail->next = new_node;
            list->tail = new_node;
        }

        list->size++;
    }
}

/**
 * Adds a new node to the beginning of the linked list
 * @param list node should be added to
 * @param data the node should contain
 * @param size of the data.
 */
void linklst_prepend(linklst *list, void *data, size_t size) {
    if (list != NULL) {
        node *new_node = linklist_create_node();
        new_node->data = malloc(size);

        memcpy(new_node->data, data, size + 1);

        if (list->head == NULL) {
            list->head = new_node;
            list->tail = new_node;
        } else {
            new_node->next = list->head;
            list->head->prev = new_node;
            list->head = new_node;
        }
    }

    list->size++;
}

/**
 * Removes and frees the last node on the list
 * @param list where the node should be popped
 */
void linklst_pop(linklst *list) {
    if (list != NULL) {
        if (list->size > 1) {
            node *tail = list->tail;
            list->tail = list->tail->prev;
            list->tail->next = NULL;

            free(tail->data);
            tail->data = NULL;
            free(tail);
        } else if (list->size == 1) {
            free(list->tail->data);
            list->tail->data = NULL;

            list->tail = NULL;
            list->head = NULL;

            free(list->tail);
        }

        if (list->size > 0)
            list->size--;
    }
}

/**
 * Finds a node in a linked list based on its data
 * @param list to search
 * @param data to search for
 * @param fptr compare function for the node data
 * @return the node that contains the data
 */
node *linklst_find(linklst *list, void *data, bool(*fptr)(void *, void *)) {
    if (list != NULL) {
        node *curr_node = list->head;
        while (curr_node != NULL) {
            if ((*fptr)(curr_node->data, data)) {
                return curr_node;
            }
            curr_node = curr_node->next;
        }
    }

    return NULL;
}

/**
 * Free all data, all nodes and the linked list from memory and sets all values to NULL
 * @param list to free
 */
void linklst_free(linklst **list) {
    if (*list != NULL) {
        linklst *remove = *list;
        if (remove->size > 0) {
            for (int i = 0; i < remove->size; ++i) {
                linklst_pop(*list);
            }
        }

        free(*list);
        *list = NULL;
    }
}

/**
 * Iterates the list from the head to the tail and executes the function pointer
 * on the node data. Function is intended for printing the list.
 * @param list to operate on
 * @param fptr to printing function
 */
void linklst_print(linklst *list, void(*fptr)(void *)) {
    if (list != NULL) {
        node *curr_node = list->head;
        while (curr_node != NULL) {
            (*fptr)(curr_node->data);
            curr_node = curr_node->next;
        }
    }
}

/**
 * Prints a string from a void pointer
 * @param s pointer to beginning of string
 */
void print_string(void *s) {
    while (*(char *) s != '\0') {
        printf("%c", *(char *) s);
        s++;
    }

    printf("\n");
}

bool compare_string(void *s1, void *s2) {
    if (strcmp((char *) s1, (char *) s2) == 0)
        return true;
    else
        return false;
}