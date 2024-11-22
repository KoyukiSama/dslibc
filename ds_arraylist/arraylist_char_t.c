#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>

#define GRAY "\033[38;5;8m"
#define GREEN "\033[38;5;2m"
#define ORANGE "\033[38;5;214m"
#define RED "\033[38;5;1m"
#define END "\033[0m"

typedef struct ArrayList_char {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    char initial_value;
    char *list;
} arraylist_char_t;


size_t arraylist_char_set_overwrite_at(arraylist_char_t **ArrayList, ssize_t index, char value);
void *malloc_wrapper(size_t size, const char* function_name);

// prints all elements
// if option > 0: then display index.
void arraylist_char_length_print(arraylist_char_t *ArrayList, char option) {
    if (option > 0) {
        // index
        printf(GRAY" ");
        for (size_t i = 0; i < ArrayList->length; i++) {
            printf(" %zu", i);
            if (i < ArrayList->length - 1) {
                printf(" ");
            }
        }
        printf("  \n"END);

        // list
        printf("[");
        for (size_t i = 0; i < ArrayList->length; i++) {
            printf(" %c", ArrayList->list[(ArrayList->index_start + i) % ArrayList->capacity]);
            if (i < ArrayList->length - 1) {
                printf(",");
            }
        }
        printf(" ]\n");
    }
    else {
        printf("[");
        for (size_t i = 0; i < ArrayList->length; i++) {
            printf(" %c", ArrayList->list[(ArrayList->index_start + i) % ArrayList->capacity]);
            if (i < ArrayList->length - 1) {
                printf(",");
            }
        }
        printf(" ]\n");
    }

    putchar('\n');
    return;
}

void arraylist_char_capacity_print(arraylist_char_t *ArrayList, char option) {
    if (option > 0) {
        // index
        printf(GRAY" ");
        for (size_t i = 0; i < ArrayList->capacity; i++) {
            printf(" %zu", i);
            if (i < ArrayList->capacity - 1) {
                printf(" ");
            }
        }
        printf("  \n"END);

        // list
        printf("[");
        for (size_t i = 0; i < ArrayList->capacity; i++) {
            printf(" %c", ArrayList->list[(ArrayList->index_start + i) % ArrayList->capacity]);
            if (i < ArrayList->capacity - 1) {
                printf(",");
            }
        }
        printf(" ]\n");
    }
    else {
        printf("[");
        for (size_t i = 0; i < ArrayList->capacity; i++) {
            printf(" %c", ArrayList->list[(ArrayList->index_start + i) % ArrayList->capacity]);
            if (i < ArrayList->capacity - 1) {
                printf(",");
            }
        }
        printf(" ]\n");
    }
    
    return;
}

void arraylist_char_debug_print(arraylist_char_t *ArrayList, char option) {
    if (option > 0) {
        size_t index_start = ArrayList->index_start;
        size_t index_end   = ArrayList->index_end;

        // index
        fprintf(stderr, GRAY);
        for (size_t i = 0; i < ArrayList->capacity; i++) {
            if (i > 9) {
                fprintf(stderr, " %zu", i);
            } else {

                fprintf(stderr, "  %zu", i);
            }
        }
        fprintf(stderr, "  \n"END);

        // list
        fprintf(stderr, "[");
        for (size_t i = 0; i < ArrayList->capacity; i++) {
            // color picking for index start and index end
            if (i == index_start && i == index_end) {
                fprintf(stderr, ORANGE" %c"END, ArrayList->list[i]);
            }
            else if (i == index_start) {
                fprintf(stderr, GREEN" %c"END, ArrayList->list[i]);
            }
            else if (i == index_end) {
                fprintf(stderr, RED" %c"END, ArrayList->list[i]);
            }
            else {
                fprintf(stderr, " %c", ArrayList->list[i]);
            }

            // print comma
            if (i < ArrayList->capacity - 1) {
                fprintf(stderr, ",");
            }
        }
        fprintf(stderr, " ]\n");
    }
    else {
        fprintf(stderr, "[");
        for (size_t i = 0; i < ArrayList->capacity; i++) {
            fprintf(stderr, " %c", ArrayList->list[i]);
            if (i < ArrayList->capacity - 1) {
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
arraylist_char_t *arraylist_char_create(size_t length, char initial_value, size_t capacity, char shrinkable) {
    if (length > capacity) {
        length = capacity;
    }
    if (capacity <= 0) {
        capacity = 1;
    }
    if (length <= 0) {
        length = 0;
    }
    // malloc the ArrayList struct
    arraylist_char_t *ArrayList = malloc_wrapper(sizeof(*ArrayList), __func__);

    // malloc the ArrayList->list with capacity
    ArrayList->list = malloc_wrapper(capacity * sizeof(*(ArrayList->list)), __func__);

    // memset list to initial_value
    memset(ArrayList->list, initial_value, capacity * sizeof(*(ArrayList->list)));

    // initialize all vars
    ArrayList->length          = length;
    ArrayList->capacity        = capacity;
    if (length == 0) {
        ArrayList->index_start = __SIZE_MAX__;
        ArrayList->index_end   = __SIZE_MAX__;
    } else {
        ArrayList->index_start = 0;
        ArrayList->index_end   = length - 1;
    }
    ArrayList->initial_value   = initial_value;
    ArrayList->shrinkable      = shrinkable;

    return ArrayList;
}

// free arraylist
void arraylist_char_free(arraylist_char_t *ArrayList) {
    free(ArrayList->list);
    free(ArrayList);

    return;
}

// resize arraylist
void arraylist_char_resize(arraylist_char_t **ArrayList, double growth_factor, size_t add_factor) {

    size_t new_capacity = (*ArrayList)->capacity * growth_factor + add_factor;

    // initialize new arraylist
    arraylist_char_t *New_ArrayList = arraylist_char_create((*ArrayList)->length, (*ArrayList)->initial_value, new_capacity, (*ArrayList)->shrinkable);

    for (size_t i = 0; i < (*ArrayList)->length; i++) {
        New_ArrayList->list[i] = (*ArrayList)->list[((*ArrayList)->index_start + i) % (*ArrayList)->capacity];
    }
    New_ArrayList->length        = (*ArrayList)->length;
    New_ArrayList->index_start   = 0;
    New_ArrayList->index_end     = New_ArrayList->length - 1;
    New_ArrayList->capacity      = new_capacity;
    New_ArrayList->initial_value = (*ArrayList)->initial_value;

    arraylist_char_free(*ArrayList);

    *ArrayList = New_ArrayList;
}


//// setters ////

// set end
size_t arraylist_char_set_append(arraylist_char_t **ArrayList, char value) {

    // check if resize needed
    if ((*ArrayList)->length == (*ArrayList)->capacity) {
        arraylist_char_resize(ArrayList, 2, 0);
    }

    // check if empty array
    if ((*ArrayList)->length == 0) {
        (*ArrayList)->index_end    = 0;
        (*ArrayList)->index_start  = 0;
        (*ArrayList)->length       = 1;
        (*ArrayList)->list[0]      = value;
    }

    // if not empty
    else {
        (*ArrayList)->index_end     = ((*ArrayList)->index_end + 1) % (*ArrayList)->capacity;
        (*ArrayList)->length       += 1;
        (*ArrayList)->list[(*ArrayList)->index_end] = value;
    }

    // return new length
    return (*ArrayList)->length;
}

// set start
size_t arraylist_char_set_prepend(arraylist_char_t **ArrayList, char value) {

    // check if resize needed
    if ((*ArrayList)->length == (*ArrayList)->capacity) {
        arraylist_char_resize(ArrayList, 2, 0);
    }

    // check if empty array
    if ((*ArrayList)->length == 0) {
        (*ArrayList)->index_end    = 0;
        (*ArrayList)->index_start  = 0;
        (*ArrayList)->length       = 1;
        (*ArrayList)->list[0]      = value;
    }

    // if not empty
    else {
        (*ArrayList)->index_start   = ((*ArrayList)->index_start - 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;
        (*ArrayList)->length       += 1;
        (*ArrayList)->list[(*ArrayList)->index_start] = value;
    }

    // returns new length
    return (*ArrayList)->length;
}

// set insert at
ssize_t arraylist_char_set_insert_at(arraylist_char_t **ArrayList, ssize_t index, char value) {
    if ((size_t)index < (*ArrayList)->length && index >= 0) {

        // check if resize needed
        if ((*ArrayList)->length == (*ArrayList)->capacity) {
            arraylist_char_resize(ArrayList, 2, index);
        }

        // sliding window
        // insert numbers, shove numbers to the right
        char temp_out         = value;
        char temp_in          = 0;
        (*ArrayList)->length += 1;

        // if shove to the left
        if ((size_t)index < ((*ArrayList)->length / 2)) {
            (*ArrayList)->index_start = (((*ArrayList)->index_start) - 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;
            size_t i                  = (index + (*ArrayList)->index_start) % (*ArrayList)->capacity;
            size_t condition          = ((*ArrayList)->index_start - 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;

            while (i != condition) {

                temp_in = (*ArrayList)->list[i];
                (*ArrayList)->list[i] = temp_out;
                temp_out = temp_in;

                // wrap the index if needed and decrement
                i = (i - 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;
            }
        }

        // if shove to the right
        else {
            (*ArrayList)->index_end = ((*ArrayList)->index_end + 1) % (*ArrayList)->capacity;
            // ( i - gap + capacity ) % capacity
            size_t i                = (((index + (*ArrayList)->index_start) % (*ArrayList)->capacity));
            size_t condition        = ((*ArrayList)->index_end + 1) % (*ArrayList)->capacity;

            while (i != condition) {
                temp_in = (*ArrayList)->list[i];
                (*ArrayList)->list[i] = temp_out;
                temp_out = temp_in;

                // wrap the index if needed and increment
                i = (i + 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;
            }
        }

    }

    // do arraylist_char_set_overwrite_at
    else {
        arraylist_char_set_overwrite_at(ArrayList, index, value);
    }

    return (*ArrayList)->length;
}

// set overwrite
size_t arraylist_char_set_overwrite_at(arraylist_char_t **ArrayList, ssize_t index, char value) {

    // if positive
    if (index >= 0) {
        
        // check if resize needed
        if ((size_t)index >= (*ArrayList)->capacity) {
            arraylist_char_resize(ArrayList, 2, index);
        }

        // check if empty
        if ((*ArrayList)->length == 0) {
            (*ArrayList)->index_start  = 0;
            (*ArrayList)->index_end    = index;
            (*ArrayList)->length       = index + 1;
            (*ArrayList)->list[index]  = value;
        }

        // overwrite
        else {
            // if overwrite exceeded length
            if ((size_t)index >= (*ArrayList)->length) {
                (*ArrayList)->index_end = (index + (*ArrayList)->index_start) % (*ArrayList)->capacity;
                (*ArrayList)->length    =  index + 1;
                (*ArrayList)->list[(*ArrayList)->index_end] = value;
            }

            (*ArrayList)->list[(index + (*ArrayList)->index_start) % ((*ArrayList)->capacity)] = value;
        }
    }

    // check if negative
    else {

        // check if resize needed
        if ((size_t)(index * -1) + (*ArrayList)->length > (*ArrayList)->capacity) {
            arraylist_char_resize(ArrayList, 2, index * -1);
        }

        // check if empty
        if ((*ArrayList)->length == 0) {
            (*ArrayList)->index_start  = (*ArrayList)->capacity - index;
            (*ArrayList)->index_end    =   0;
            (*ArrayList)->length       =   index * -1 + 1;
            (*ArrayList)->list[(*ArrayList)->index_start]  = value;
        }

        // overwrite into negative index
        else {
            (*ArrayList)->index_start  = (index + (*ArrayList)->index_start + (*ArrayList)->capacity) % (*ArrayList)->capacity;
            (*ArrayList)->length      += (index * -1);
            (*ArrayList)->list[(*ArrayList)->index_start] = value;
        }
    }

    return (*ArrayList)->length; // returns new length
}

//// remove functions

// remove appended
size_t arraylist_char_remove_append(arraylist_char_t **ArrayList) {

    // check if downsize is needed
    if ((*ArrayList)->shrinkable > 0 && (*ArrayList)->capacity > 5 && (*ArrayList)->length <= ((*ArrayList)->capacity / 3)) {
        arraylist_char_resize(ArrayList, 0.5f, 0);
    }

    // remove appended
    if ((*ArrayList)->length > 0) {
        (*ArrayList)->length--;
        (*ArrayList)->list[(*ArrayList)->index_end] = (*ArrayList)->initial_value;
        if ((*ArrayList)->length != 0) {
            (*ArrayList)->index_end = ((*ArrayList)->index_end - 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;
        }
    }

    // check if empty
    if ((*ArrayList)->length == 0) {
        (*ArrayList)->index_end    = 0;
        (*ArrayList)->index_start  = 0;
    }

    return (*ArrayList)->length;
}

// remove prepended
size_t arraylist_char_remove_prepend(arraylist_char_t **ArrayList) {

    // check if downsize is needed
    if ((*ArrayList)->shrinkable > 0 && (*ArrayList)->capacity > 5 && (*ArrayList)->length <= ((*ArrayList)->capacity / 3)) {
        arraylist_char_resize(ArrayList, 0.5f, 0);
    }

    // remove prepended
    if ((*ArrayList)->length > 0) {
        (*ArrayList)->length--;
        (*ArrayList)->list[(*ArrayList)->index_start] = (*ArrayList)->initial_value;
        if ((*ArrayList)->length != 0) {
            (*ArrayList)->index_start = ((*ArrayList)->index_start + 1) % (*ArrayList)->capacity;
        }
    }

    // check if empty
    if ((*ArrayList)->length == 0) {
        (*ArrayList)->index_end   = 0;
        (*ArrayList)->index_start = 0;
    }

    return (*ArrayList)->length;
}

// remove insert at
size_t arraylist_char_remove_insert_at(arraylist_char_t **ArrayList, size_t index) {

    if (index < (*ArrayList)->length) {

        // check if downsize is needed
        if ((*ArrayList)->shrinkable > 0 && (*ArrayList)->capacity > 5 && (*ArrayList)->length <= ((*ArrayList)->capacity / 3)) {
            arraylist_char_resize(ArrayList, 0.5f, 0);
        }
        // remove inserted at
        if ((*ArrayList)->length > 0) {
            (*ArrayList)->length--;
            //char temp_in = 0;
            size_t i        = 0;
            size_t i_offset = 0;

            // shove from left side
            if (index < (*ArrayList)->length / 2) {

                i = (index + (*ArrayList)->index_start) % (*ArrayList)->capacity;

                while (i != (*ArrayList)->index_start) {
                    i_offset = (i - 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;
                    (*ArrayList)->list[i] = (*ArrayList)->list[i_offset];

                    i = i_offset;
                }
                (*ArrayList)->list[i] = (*ArrayList)->initial_value;
                (*ArrayList)->index_start = ((*ArrayList)->index_start + 1) % (*ArrayList)->capacity;
            }

            // shove from right side
            else {
                
                i = (index + (*ArrayList)->index_start) % (*ArrayList)->capacity;

                while (i != (*ArrayList)->index_end) {
                    i_offset = (i + 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;
                    (*ArrayList)->list[i] = (*ArrayList)->list[i_offset];

                    i = i_offset;
                }
                (*ArrayList)->list[i] = (*ArrayList)->initial_value;
                (*ArrayList)->index_end = ((*ArrayList)->index_end - 1 + (*ArrayList)->capacity) % (*ArrayList)->capacity;
            }
        }
    }

    // check if empty
    if ((*ArrayList)->length == 0) {
        (*ArrayList)->index_end   = 0;
        (*ArrayList)->index_start = 0;
    }
    
    return (*ArrayList)->length;
}

// remove overwrite, defaults to initial value
size_t arraylist_char_remove_overwrite_at(arraylist_char_t **ArrayList, size_t index) {
    
    // if at start or end, reroute
    if (index == 0) {
        arraylist_char_remove_prepend(ArrayList);
    }
    else if (index >= (*ArrayList)->length - 1) {
        arraylist_char_remove_append(ArrayList);
    }

    // overwrite value with initial_value
    else {
        (*ArrayList)->list[(index + (*ArrayList)->index_start) % (*ArrayList)->capacity] = (*ArrayList)->initial_value;
    }

    return (*ArrayList)->length;
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
    arraylist_char_t *ArrayList = arraylist_char_create(0, '_', 10, 1);

    // IS
    arraylist_char_set_prepend(&ArrayList, 'S');
    arraylist_char_set_prepend(&ArrayList, 'I');
    arraylist_char_set_prepend(&ArrayList, ' ');
    // MOMMY
    arraylist_char_set_prepend(&ArrayList, 'Y');
    arraylist_char_set_prepend(&ArrayList, 'M');
    arraylist_char_debug_print(ArrayList, 1);
    arraylist_char_length_print(ArrayList, 0);
    arraylist_char_set_prepend(&ArrayList, 'M');
    arraylist_char_debug_print(ArrayList, 1);
    arraylist_char_length_print(ArrayList, 0);
    arraylist_char_set_prepend(&ArrayList, 'O');
    arraylist_char_debug_print(ArrayList, 1);
    arraylist_char_length_print(ArrayList, 0);
    arraylist_char_set_prepend(&ArrayList, 'M');
    arraylist_char_debug_print(ArrayList, 1);
    arraylist_char_length_print(ArrayList, 0);
    arraylist_char_set_append(&ArrayList, ' ');
    arraylist_char_debug_print(ArrayList, 1);
    arraylist_char_length_print(ArrayList, 0);
    // COOL
    arraylist_char_set_append(&ArrayList, 'C');
    arraylist_char_set_append(&ArrayList, 'O');
    arraylist_char_set_append(&ArrayList, 'O');
    arraylist_char_set_append(&ArrayList, 'L');
    arraylist_char_debug_print(ArrayList, 1);
    arraylist_char_length_print(ArrayList, 0);

    arraylist_char_set_insert_at(&ArrayList, 10, '@');
    arraylist_char_set_insert_at(&ArrayList, 14, '@');
    arraylist_char_remove_insert_at(&ArrayList, 14);
    arraylist_char_remove_insert_at(&ArrayList, 10);
    //arraylist_char_remove_insert_at(&ArrayList, 10);
    
    arraylist_char_set_insert_at(&ArrayList, -8, '@');

    //arraylist_char_remove_overwrite_at(&ArrayList, );
    

    arraylist_char_debug_print(ArrayList, 1);
    arraylist_char_length_print(ArrayList, 0);

    //arraylist_char_set_insert_after(&ArrayList, 0, '9');
    //arraylist_char_debug_print(ArrayList, 1);
    //arraylist_char_length_print(ArrayList, 0);

    arraylist_char_free(ArrayList);

    return 0;
}