#include <stdlib.h>
#include <stdio.h>

typedef struct ArrayList_char {
    size_t length;
    size_t capacity;

    size_t index_head; // oldest element
    size_t index_tail;

    char *list;
} arraylist_char_t;

void arraylist_char_print(arraylist_char_t *ArrayList) {
    for (size_t i = 0; i < ArrayList->length; i++) {
        printf("%c ", ArrayList->list[(ArrayList->index_head + i) % ArrayList->capacity]);
    }
    printf("\n");
}

arraylist_char_t *arraylist_char_create(size_t capacity, char initial_value) {

    // malloc the ArrayList struct
    arraylist_char_t *ArrayList = malloc_wrapper(sizeof(*ArrayList), __func__);

    // malloc the ArrayList->list with capacity
    ArrayList->list = malloc_wrapper(capacity * sizeof(*(ArrayList->list)), __func__);

    // memset list to initial_value
    memset(ArrayList->list, initial_value, capacity * sizeof(*(ArrayList->list)));

    // initialize all vars
    ArrayList->length = 0;
    ArrayList->capacity = capacity;
    ArrayList->index_head = 0;
    ArrayList->index_tail = 0;

    return ArrayList;
}


// memory helpers

void *malloc_wrapper(size_t size, const char* function_name) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "[ERROR] %s: (%s)\n", __func__, function_name);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

