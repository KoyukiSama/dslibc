#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#include <time.h>

#define GRAY "\033[38;5;8m"
#define GREEN "\033[38;5;2m"
#define ORANGE "\033[38;5;214m"
#define RED "\033[38;5;1m"
#define END "\033[0m"

typedef struct Katarray_char {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    char initial_value;
    char *list;
} katarray_char_t;


size_t katarray_char_set_overwrite_at(katarray_char_t **KatArray, ssize_t index, char value);
void *malloc_wrapper(size_t size, const char* function_name);

// prints all elements
// if option > 0: then display index.
void katarray_char_length_print(katarray_char_t *KatArray, char option) {
    if (option > 0) {
        // index
        printf(GRAY" ");
        for (size_t i = 0; i < KatArray->length; i++) {
            printf(" %zu", i);
            if (i < KatArray->length - 1) {
                printf(" ");
            }
        }
        printf("  \n"END);

        // list
        printf("[");
        for (size_t i = 0; i < KatArray->length; i++) {
            printf(" %c", KatArray->list[(KatArray->index_start + i) % KatArray->capacity]);
            if (i < KatArray->length - 1) {
                printf(",");
            }
        }
        printf(" ]\n");
    }
    else {
        printf("[");
        for (size_t i = 0; i < KatArray->length; i++) {
            printf(" %c", KatArray->list[(KatArray->index_start + i) % KatArray->capacity]);
            if (i < KatArray->length - 1) {
                printf(",");
            }
        }
        printf(" ]\n");
    }

    putchar('\n');
    return;
}

void katarray_char_capacity_print(katarray_char_t *KatArray, char option) {
    if (option > 0) {
        // index
        printf(GRAY" ");
        for (size_t i = 0; i < KatArray->capacity; i++) {
            printf(" %zu", i);
            if (i < KatArray->capacity - 1) {
                printf(" ");
            }
        }
        printf("  \n"END);

        // list
        printf("[");
        for (size_t i = 0; i < KatArray->capacity; i++) {
            printf(" %c", KatArray->list[(KatArray->index_start + i) % KatArray->capacity]);
            if (i < KatArray->capacity - 1) {
                printf(",");
            }
        }
        printf(" ]\n");
    }
    else {
        printf("[");
        for (size_t i = 0; i < KatArray->capacity; i++) {
            printf(" %c", KatArray->list[(KatArray->index_start + i) % KatArray->capacity]);
            if (i < KatArray->capacity - 1) {
                printf(",");
            }
        }
        printf(" ]\n");
    }
    
    return;
}

void katarray_char_debug_print(katarray_char_t *KatArray, char option) {
    if (option > 0) {
        size_t index_start = KatArray->index_start;
        size_t index_end   = KatArray->index_end;

        // index
        fprintf(stderr, GRAY);
        for (size_t i = 0; i < KatArray->capacity; i++) {
            if (i > 9) {
                fprintf(stderr, " %zu", i);
            } else {

                fprintf(stderr, "  %zu", i);
            }
        }
        fprintf(stderr, "  \n"END);

        // list
        fprintf(stderr, "[");
        for (size_t i = 0; i < KatArray->capacity; i++) {
            // color picking for index start and index end
            if (i == index_start && i == index_end) {
                fprintf(stderr, ORANGE" %c"END, KatArray->list[i]);
            }
            else if (i == index_start) {
                fprintf(stderr, GREEN" %c"END, KatArray->list[i]);
            }
            else if (i == index_end) {
                fprintf(stderr, RED" %c"END, KatArray->list[i]);
            }
            else {
                fprintf(stderr, " %c", KatArray->list[i]);
            }

            // print comma
            if (i < KatArray->capacity - 1) {
                fprintf(stderr, ",");
            }
        }
        fprintf(stderr, " ]\n");
    }
    else {
        fprintf(stderr, "[");
        for (size_t i = 0; i < KatArray->capacity; i++) {
            fprintf(stderr, " %c", KatArray->list[i]);
            if (i < KatArray->capacity - 1) {
                fprintf(stderr, ",");
            }
        }
        fprintf(stderr, " ]\n");
    }
    
    return;
}

//// initialization and cleanup ////

// shrinkable -> shrinkable > 0
// create arraylist
katarray_char_t *katarray_char_create(size_t length, char initial_value, size_t capacity, char shrinkable) {
    if (length > capacity) {
        length = capacity;
    }
    if (capacity <= 0) {
        capacity = 1;
    }
    if (length <= 0) {
        length = 0;
    }
    // malloc the KatArray struct
    katarray_char_t *KatArray = malloc_wrapper(sizeof(*KatArray), __func__);

    // malloc the KatArray->list with capacity
    KatArray->list = malloc_wrapper(capacity * sizeof(*(KatArray->list)), __func__);

    // memset list to initial_value
    memset(KatArray->list, initial_value, capacity * sizeof(*(KatArray->list)));

    // initialize all vars
    KatArray->length          = length;
    KatArray->capacity        = capacity;
    if (length == 0) {
        KatArray->index_start = __SIZE_MAX__;
        KatArray->index_end   = __SIZE_MAX__;
    } else {
        KatArray->index_start = 0;
        KatArray->index_end   = length - 1;
    }
    KatArray->initial_value   = initial_value;
    KatArray->shrinkable      = shrinkable;

    return KatArray;
}

// free arraylist
void katarray_char_free(katarray_char_t *KatArray) {
    free(KatArray->list);
    free(KatArray);

    return;
}

// resize arraylist
void katarray_char_resize(katarray_char_t **KatArray, double growth_factor, size_t add_factor) {

    size_t new_capacity = (*KatArray)->capacity * growth_factor + add_factor;

    // initialize new arraylist
    katarray_char_t *New_ArrayList = katarray_char_create((*KatArray)->length, (*KatArray)->initial_value, new_capacity, (*KatArray)->shrinkable);

    for (size_t i = 0; i < (*KatArray)->length; i++) {
        New_ArrayList->list[i] = (*KatArray)->list[((*KatArray)->index_start + i) % (*KatArray)->capacity];
    }
    New_ArrayList->length        = (*KatArray)->length;
    New_ArrayList->index_start   = 0;
    New_ArrayList->index_end     = New_ArrayList->length - 1;
    New_ArrayList->capacity      = new_capacity;
    New_ArrayList->initial_value = (*KatArray)->initial_value;

    katarray_char_free(*KatArray);

    *KatArray = New_ArrayList;

    return;
}

// convert arraylist, does what resizing does but without the resize
void katarray_char_convert(katarray_char_t **KatArray) {

    katarray_char_t *New_ArrayList = katarray_char_create((*KatArray)->length, (*KatArray)->initial_value, (*KatArray)->capacity, (*KatArray)->shrinkable);

    for (size_t i = 0; i < (*KatArray)->length; i++) {
        New_ArrayList->list[i] = (*KatArray)->list[((*KatArray)->index_start + i) % (*KatArray)->capacity];
    }
    New_ArrayList->length        = (*KatArray)->length;
    New_ArrayList->index_start   = 0;
    New_ArrayList->index_end     = (*KatArray)->length - 1;
    New_ArrayList->capacity      = (*KatArray)->capacity;
    New_ArrayList->initial_value = (*KatArray)->initial_value;

    katarray_char_free(*KatArray);

    *KatArray = New_ArrayList;

    return;
}

//// setters ////

// set end
size_t katarray_char_set_append(katarray_char_t **KatArray, char value) {

    // check if resize needed
    if ((*KatArray)->length == (*KatArray)->capacity) {
        katarray_char_resize(KatArray, 2, 0);
    }

    // check if empty array
    if ((*KatArray)->length == 0) {
        (*KatArray)->index_end    = 0;
        (*KatArray)->index_start  = 0;
        (*KatArray)->length       = 1;
        (*KatArray)->list[0]      = value;
    }

    // if not empty
    else {
        (*KatArray)->index_end     = ((*KatArray)->index_end + 1) % (*KatArray)->capacity;
        (*KatArray)->length       += 1;
        (*KatArray)->list[(*KatArray)->index_end] = value;
    }

    // return new length
    return (*KatArray)->length;
}

// set start
size_t katarray_char_set_prepend(katarray_char_t **KatArray, char value) {

    // check if resize needed
    if ((*KatArray)->length == (*KatArray)->capacity) {
        katarray_char_resize(KatArray, 2, 0);
    }

    // check if empty array
    if ((*KatArray)->length == 0) {
        (*KatArray)->index_end    = 0;
        (*KatArray)->index_start  = 0;
        (*KatArray)->length       = 1;
        (*KatArray)->list[0]      = value;
    }

    // if not empty
    else {
        (*KatArray)->index_start   = ((*KatArray)->index_start - 1 + (*KatArray)->capacity) % (*KatArray)->capacity;
        (*KatArray)->length       += 1;
        (*KatArray)->list[(*KatArray)->index_start] = value;
    }

    // returns new length
    return (*KatArray)->length;
}

// set insert at
ssize_t katarray_char_set_insert_at(katarray_char_t **KatArray, ssize_t index, char value) {
    if ((size_t)index < (*KatArray)->length && index >= 0) {

        // check if resize needed
        if ((*KatArray)->length == (*KatArray)->capacity) {
            katarray_char_resize(KatArray, 2, index);
        }

        // sliding window
        // insert numbers, shove numbers to the right
        char temp_out         = value;
        char temp_in          = 0;
        (*KatArray)->length += 1;

        // if shove to the left
        if ((size_t)index < ((*KatArray)->length / 2)) {
            (*KatArray)->index_start = (((*KatArray)->index_start) - 1 + (*KatArray)->capacity) % (*KatArray)->capacity;
            size_t i                  = (index + (*KatArray)->index_start) % (*KatArray)->capacity;
            size_t condition          = ((*KatArray)->index_start - 1 + (*KatArray)->capacity) % (*KatArray)->capacity;

            while (i != condition) {

                temp_in = (*KatArray)->list[i];
                (*KatArray)->list[i] = temp_out;
                temp_out = temp_in;

                // wrap the index if needed and decrement
                i = (i - 1 + (*KatArray)->capacity) % (*KatArray)->capacity;
            }
        }

        // if shove to the right
        else {
            (*KatArray)->index_end = ((*KatArray)->index_end + 1) % (*KatArray)->capacity;
            // ( i - gap + capacity ) % capacity
            size_t i                = (((index + (*KatArray)->index_start) % (*KatArray)->capacity));
            size_t condition        = ((*KatArray)->index_end + 1) % (*KatArray)->capacity;

            while (i != condition) {
                temp_in = (*KatArray)->list[i];
                (*KatArray)->list[i] = temp_out;
                temp_out = temp_in;

                // wrap the index if needed and increment
                i = (i + 1 + (*KatArray)->capacity) % (*KatArray)->capacity;
            }
        }

    }

    // do katarray_char_set_overwrite_at
    else {
        katarray_char_set_overwrite_at(KatArray, index, value);
    }

    return (*KatArray)->length;
}

// set overwrite
size_t katarray_char_set_overwrite_at(katarray_char_t **KatArray, ssize_t index, char value) {

    // if positive
    if (index >= 0) {
        
        // check if resize needed
        if ((size_t)index >= (*KatArray)->capacity) {
            katarray_char_resize(KatArray, 2, index);
        }

        // check if empty
        if ((*KatArray)->length == 0) {
            (*KatArray)->index_start  = 0;
            (*KatArray)->index_end    = index;
            (*KatArray)->length       = index + 1;
            (*KatArray)->list[index]  = value;
        }

        // overwrite
        else {
            // if overwrite exceeded length
            if ((size_t)index >= (*KatArray)->length) {
                (*KatArray)->index_end = (index + (*KatArray)->index_start) % (*KatArray)->capacity;
                (*KatArray)->length    =  index + 1;
                (*KatArray)->list[(*KatArray)->index_end] = value;
            }

            (*KatArray)->list[(index + (*KatArray)->index_start) % ((*KatArray)->capacity)] = value;
        }
    }

    // check if negative
    else {

        // check if resize needed
        if ((size_t)(index * -1) + (*KatArray)->length > (*KatArray)->capacity) {
            katarray_char_resize(KatArray, 2, index * -1);
        }

        // check if empty
        if ((*KatArray)->length == 0) {
            (*KatArray)->index_start  = (*KatArray)->capacity - index;
            (*KatArray)->index_end    =   0;
            (*KatArray)->length       =   index * -1 + 1;
            (*KatArray)->list[(*KatArray)->index_start]  = value;
        }

        // overwrite into negative index
        else {
            (*KatArray)->index_start  = (index + (*KatArray)->index_start + (*KatArray)->capacity) % (*KatArray)->capacity;
            (*KatArray)->length      += (index * -1);
            (*KatArray)->list[(*KatArray)->index_start] = value;
        }
    }

    return (*KatArray)->length; // returns new length
}


//// remove functions

// returns the removed value
// remove appended
char katarray_char_remove_append(katarray_char_t **KatArray) {

    char removed_value = (*KatArray)->list[(*KatArray)->index_end];

    // check if downsize is needed
    if ((*KatArray)->shrinkable > 0 && (*KatArray)->capacity > 5 && (*KatArray)->length <= ((*KatArray)->capacity / 3)) {
        katarray_char_resize(KatArray, 0.5f, 0);
    }

    // remove appended
    if ((*KatArray)->length > 0) {
        (*KatArray)->length--;
        (*KatArray)->list[(*KatArray)->index_end] = (*KatArray)->initial_value;
        if ((*KatArray)->length != 0) {
            (*KatArray)->index_end = ((*KatArray)->index_end - 1 + (*KatArray)->capacity) % (*KatArray)->capacity;
        }
    }

    // check if empty
    if ((*KatArray)->length == 0) {
        (*KatArray)->index_end    = 0;
        (*KatArray)->index_start  = 0;
    }

    return removed_value;
}

// returns the removed value
// remove prepended
char katarray_char_remove_prepend(katarray_char_t **KatArray) {

    char removed_value = (*KatArray)->list[(*KatArray)->index_start];
    
    // check if downsize is needed
    if ((*KatArray)->shrinkable > 0 && (*KatArray)->capacity > 5 && (*KatArray)->length <= ((*KatArray)->capacity / 3)) {
        katarray_char_resize(KatArray, 0.5f, 0);
    }

    // remove prepended
    if ((*KatArray)->length > 0) {
        (*KatArray)->length--;
        (*KatArray)->list[(*KatArray)->index_start] = (*KatArray)->initial_value;
        if ((*KatArray)->length != 0) {
            (*KatArray)->index_start = ((*KatArray)->index_start + 1) % (*KatArray)->capacity;
        }
    }

    // check if empty
    if ((*KatArray)->length == 0) {
        (*KatArray)->index_end   = 0;
        (*KatArray)->index_start = 0;
    }

    return removed_value;
}

// remove insert at
char katarray_char_remove_insert_at(katarray_char_t **KatArray, size_t index) {

    char removed_value = (*KatArray)->list[(index + (*KatArray)->index_start) % (*KatArray)->capacity];

    if (index < (*KatArray)->length) {

        // check if downsize is needed
        if ((*KatArray)->shrinkable > 0 && (*KatArray)->capacity > 5 && (*KatArray)->length <= ((*KatArray)->capacity / 3)) {
            katarray_char_resize(KatArray, 0.5f, 0);
        }

        // remove inserted at
        if ((*KatArray)->length > 0) {
            (*KatArray)->length--;
            //char temp_in = 0;
            size_t i        = 0;
            size_t i_offset = 0;

            // shove from left side
            if (index < (*KatArray)->length / 2) {

                i = (index + (*KatArray)->index_start) % (*KatArray)->capacity;

                while (i != (*KatArray)->index_start) {
                    i_offset = (i - 1 + (*KatArray)->capacity) % (*KatArray)->capacity;
                    (*KatArray)->list[i] = (*KatArray)->list[i_offset];

                    i = i_offset;
                }
                (*KatArray)->list[i] = (*KatArray)->initial_value;
                (*KatArray)->index_start = ((*KatArray)->index_start + 1) % (*KatArray)->capacity;
            }

            // shove from right side
            else {
                
                i = (index + (*KatArray)->index_start) % (*KatArray)->capacity;

                while (i != (*KatArray)->index_end) {
                    i_offset = (i + 1 + (*KatArray)->capacity) % (*KatArray)->capacity;
                    (*KatArray)->list[i] = (*KatArray)->list[i_offset];

                    i = i_offset;
                }
                (*KatArray)->list[i] = (*KatArray)->initial_value;
                (*KatArray)->index_end = ((*KatArray)->index_end - 1 + (*KatArray)->capacity) % (*KatArray)->capacity;
            }
        }
    }

    // check if empty
    if ((*KatArray)->length == 0) {
        (*KatArray)->index_end   = 0;
        (*KatArray)->index_start = 0;
    }
    
    return removed_value;
}

// remove overwrite, defaults to initial value
char katarray_char_remove_overwrite_at(katarray_char_t **KatArray, size_t index) {
    
    char removed_value = (*KatArray)->list[(index + (*KatArray)->index_start) % (*KatArray)->capacity];

    // if at start or end, reroute
    if (index == 0) {
        katarray_char_remove_prepend(KatArray);
    }
    else if (index >= (*KatArray)->length - 1) {
        katarray_char_remove_append(KatArray);
    }

    // overwrite value with initial_value
    else {
        (*KatArray)->list[(index + (*KatArray)->index_start) % (*KatArray)->capacity] = (*KatArray)->initial_value;
    }

    return removed_value;
}

// remove / resest the whole array
void katarray_char_reset(katarray_char_t **KatArray, size_t length, size_t capacity) {
    *KatArray = katarray_char_create(length, (*KatArray)->initial_value, capacity, (*KatArray)->shrinkable);
    return;
}


//// getters

// get value at index
char katarray_char_get_value_at(katarray_char_t *KatArray, size_t index) {
    if (index < KatArray->length) {
        return KatArray->list[(index + KatArray->index_start) % KatArray->capacity];
    }

    else return -1;
}

// get value at start index
char katarray_char_get_first_value(katarray_char_t *KatArray) {
    return KatArray->list[KatArray->index_start];
}

// get value at end index
char katarray_char_get_last_value(katarray_char_t *KatArray) {
    return KatArray->list[KatArray->index_end];
}

// get length of array
size_t katarray_char_get_length(katarray_char_t *KatArray) {
    return KatArray->length;
}

// get capacity of array
size_t katarray_char_get_capacity(katarray_char_t *KatArray) {
    return KatArray->capacity;
}


//// queue operations + ring buffer operations

// enqueue
size_t katarray_char_enqueue(katarray_char_t **KatArray, char value) {
    return katarray_char_set_append(KatArray, value);
}

// dequeue
char katarray_char_dequeue(katarray_char_t **KatArray) {
    return katarray_char_remove_prepend(KatArray);
}

// peek at the start/head of the arraylist
char katarray_char_peek_head(katarray_char_t *KatArray) {
    return katarray_char_get_first_value(KatArray);
}

// is full -> automatic resizing is always on but you can actually check this before adding to know if you're going to go over the capacity limit to resize
// so if you want to use a strict capacity limit from the start, then use this.
char katarray_char_is_full(katarray_char_t *KatArray) {
    if (KatArray->length == KatArray->capacity) {
        return 1;
    }
    else return -1;
}

// is empty
char katarray_char_is_empty(katarray_char_t *KatArray) {
    if (KatArray->length == 0 && KatArray->index_end == KatArray->index_start) {
        return 1;
    }
    else return -1;
}


//// stack operations

// push
size_t katarray_char_push(katarray_char_t **KatArray, char value) {
    return katarray_char_set_append(KatArray, value);
}

// pop
char katarray_char_pop(katarray_char_t **KatArray) {
    return katarray_char_remove_append(KatArray);
}

// peek top
char katarray_char_peek_top(katarray_char_t *KatArray) {
    return katarray_char_get_last_value(KatArray);
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


int main(void) {
    
    size_t n_inserts = 10000000;
    double time_spent = 0;

    katarray_char_t *KatArray = katarray_char_create(0, '_', 5, 1);

    clock_t start = clock();

    for (size_t i = 0; i < n_inserts/4; i++) {

        // prepend
        katarray_char_set_prepend(&KatArray, '@');

        // append
        katarray_char_set_append(&KatArray, 'D');

        // insert at 1/4
        katarray_char_set_insert_at(&KatArray, '0', i/4);

        // insert at 3/4
        katarray_char_set_insert_at(&KatArray, 'D', (i/4)*3);

    }

    clock_t end   = clock();
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time for %zu : %f seconds\n", n_inserts, time_spent);

    katarray_char_free(KatArray);

    return 0;
}