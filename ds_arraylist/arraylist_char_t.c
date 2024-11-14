#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

typedef struct ArrayList_char {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char initial_value;
    char *list;
} arraylist_char_t;



// prints all elements
void arraylist_char_print(arraylist_char_t *ArrayList) {
    for (size_t i = 0; i < ArrayList->length; i++) {
        printf("%c ", ArrayList->list[(ArrayList->index_start + i) % ArrayList->capacity]);
    }
    printf("\n");
}


//// initialization and cleanup ////

// create arraylist
arraylist_char_t *arraylist_char_create(size_t capacity, char initial_value) {

    // malloc the ArrayList struct
    arraylist_char_t *ArrayList = malloc_wrapper(sizeof(*ArrayList), __func__);

    // malloc the ArrayList->list with capacity
    ArrayList->list = malloc_wrapper(capacity * sizeof(*(ArrayList->list)), __func__);

    // memset list to initial_value
    memset(ArrayList->list, initial_value, capacity * sizeof(*(ArrayList->list)));

    // initialize all vars
    ArrayList->length        = 0;
    ArrayList->capacity      = capacity;
    ArrayList->index_start   = __SIZE_MAX__;
    ArrayList->index_end     = __SIZE_MAX__;
    ArrayList->initial_value = initial_value;

    return ArrayList;
}

// free arraylist
void arraylist_char_free(arraylist_char_t *ArrayList) {
    free(ArrayList->list);
    free(ArrayList);

    return;
}

// resize arraylist
arraylist_char_t *arraylist_char_resize(arraylist_char_t *ArrayList) {

    // initialize new arraylist
    arraylist_char_t *New_ArrayList = arraylist_char_create((ArrayList->capacity * 2), ArrayList->initial_value);

    for (int i = 0; i < ArrayList->length; i++) {
        New_ArrayList->list[i] = ArrayList->list[(ArrayList->index_start + i) % ArrayList->capacity];
    }
    New_ArrayList->index_start   = 0;
    New_ArrayList->index_end     = ArrayList->length - 1;
    New_ArrayList->length        = ArrayList->length;
    New_ArrayList->capacity      = ArrayList->capacity * 2;
    New_ArrayList->initial_value = ArrayList->initial_value;

    arraylist_char_free(ArrayList);

    return New_ArrayList;
}


//// setters ////

// set end
size_t arraylist_char_set_end(arraylist_char_t *ArrayList, char value) {

    // check if resize needed
    if (ArrayList->length == ArrayList->capacity) {
        ArrayList = arraylist_char_resize(ArrayList);
    }

    // check if empty array
    if (ArrayList->index_end == __SIZE_MAX__) {
        ArrayList->index_end    = 0;
        ArrayList->index_start  = 0;
        ArrayList->length       = 1;
        ArrayList->list[0]      = value;
    }

    // if not empty
    else {
        ArrayList->index_end    += 1;
        ArrayList->length       += 1;
        ArrayList->list[ArrayList->index_end] = value;
    }

    // return the index of the end,     since it's an array buffer, uses arraylist-length
    return ArrayList->length - 1;
}

//// memory helpers

void *malloc_wrapper(size_t size, const char* function_name) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "[ERROR] %s: (%s)\n", __func__, function_name);
        exit(EXIT_FAILURE);
    }
    return ptr;
}

