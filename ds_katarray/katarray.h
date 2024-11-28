#ifndef KATARRAY_H
#define KATARRAY_H

#include "katarray_helper.h"
#include <sys/types.h>

////* CHAR LIB *///

typedef struct Katarray_char {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    char initial_value;
    char *list;
} katarray_char_t;

// (printers) //
void    katarray_char_length_print(katarray_char_t *KatArray, char option);
void    katarray_char_capacity_print(katarray_char_t *KatArray, char option);
void    katarray_char_debug_print(katarray_char_t *KatArray, char option);

// (management) //
katarray_char_t *katarray_char_create(size_t length, char initial_value, size_t capacity, char shrinkable);
void    katarray_char_free(katarray_char_t *KatArray);
void    katarray_char_resize(katarray_char_t **KatArray, double growth_factor, size_t add_factor);
void    katarray_char_convert(katarray_char_t **KatArray);
void    katarray_char_reset(katarray_char_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t  katarray_char_set_append(katarray_char_t **KatArray, char value);
size_t  katarray_char_set_prepend(katarray_char_t **KatArray, char value);
size_t  katarray_char_set_insert_at(katarray_char_t **KatArray, ssize_t index, char value);
size_t  katarray_char_set_overwrite_at(katarray_char_t **KatArray, ssize_t index, char value);

// (removers) //
char    katarray_char_remove_append(katarray_char_t **KatArray);
char    katarray_char_remove_prepend(katarray_char_t **KatArray);
char    katarray_char_remove_insert_at(katarray_char_t **KatArray, size_t index);
char    katarray_char_remove_overwrite_at(katarray_char_t **KatArray, size_t index);

// (getters) //
char    katarray_char_get_value_at(katarray_char_t *KatArray, size_t index);
char    katarray_char_get_first_value(katarray_char_t *KatArray);
char    katarray_char_get_last_value(katarray_char_t *KatArray);
size_t  katarray_char_get_length(katarray_char_t *KatArray);
size_t  katarray_char_get_capacity(katarray_char_t *KatArray);

// (QUEUE OPERATIONS) //
size_t  katarray_char_enqueue(katarray_char_t **KatArray, char value);
char    katarray_char_dequeue(katarray_char_t **KatArray);
char    katarray_char_peek_head(katarray_char_t *KatArray);

// (STACK OPERATIONS) //
size_t  katarray_char_push(katarray_char_t **KatArray, char value);
char    katarray_char_pop(katarray_char_t **KatArray);
char    katarray_char_peek_top(katarray_char_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char    katarray_char_is_full(katarray_char_t *KatArray);
char    katarray_char_is_empty(katarray_char_t *KatArray);


////* DOUBLE LIB *////

typedef struct KatArray_double {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    double initial_value;
    double *list;
} katarray_double_t;

// (printers) //
void    katarray_double_length_print(katarray_double_t *KatArray, char option);
void    katarray_double_capacity_print(katarray_double_t *KatArray, char option);
void    katarray_double_debug_print(katarray_double_t *KatArray, char option);

// (management) //
katarray_double_t *katarray_double_create(size_t length, double initial_value, size_t capacity, char shrinkable);
void    katarray_double_free(katarray_double_t *KatArray);
void    katarray_double_resize(katarray_double_t **KatArray, double growth_factor, size_t add_factor);
void    katarray_double_convert(katarray_double_t **KatArray);
void    katarray_double_reset(katarray_double_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t  katarray_double_set_append(katarray_double_t **KatArray, double value);
size_t  katarray_double_set_prepend(katarray_double_t **KatArray, double value);
size_t  katarray_double_set_insert_at(katarray_double_t **KatArray, ssize_t index, double value);
size_t  katarray_double_set_overwrite_at(katarray_double_t **KatArray, ssize_t index, double value);

// (removers) //
double  katarray_double_remove_append(katarray_double_t **KatArray);
double  katarray_double_remove_prepend(katarray_double_t **KatArray);
double  katarray_double_remove_insert_at(katarray_double_t **KatArray, size_t index);
double  katarray_double_remove_overwrite_at(katarray_double_t **KatArray, size_t index);

// (getters) //
double  katarray_double_get_value_at(katarray_double_t *KatArray, size_t index);
double  katarray_double_get_first_value(katarray_double_t *KatArray);
double  katarray_double_get_last_value(katarray_double_t *KatArray);
size_t  katarray_double_get_length(katarray_double_t *KatArray);
size_t  katarray_double_get_capacity(katarray_double_t *KatArray);

// (QUEUE OPERATIONS) //
size_t  katarray_double_enqueue(katarray_double_t **KatArray, double value);
double  katarray_double_dequeue(katarray_double_t **KatArray);
double  katarray_double_peek_head(katarray_double_t *KatArray);

// (STACK OPERATIONS) //
size_t  katarray_double_push(katarray_double_t **KatArray, double value);
double  katarray_double_pop(katarray_double_t **KatArray);
double  katarray_double_peek_top(katarray_double_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char    katarray_double_is_full(katarray_double_t *KatArray);
char    katarray_double_is_empty(katarray_double_t *KatArray);


////* FLOAT LIB *////

typedef struct KatArray_float {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    float initial_value;
    float *list;
} katarray_float_t;

// (printers) //
void    katarray_float_length_print(katarray_float_t *KatArray, char option);
void    katarray_float_capacity_print(katarray_float_t *KatArray, char option);
void    katarray_float_debug_print(katarray_float_t *KatArray, char option);

// (management) //
katarray_float_t *katarray_float_create(size_t length, float initial_value, size_t capacity, char shrinkable);
void    katarray_float_free(katarray_float_t *KatArray);
void    katarray_float_resize(katarray_float_t **KatArray, double growth_factor, size_t add_factor);
void    katarray_float_convert(katarray_float_t **KatArray);
void    katarray_float_reset(katarray_float_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t  katarray_float_set_append(katarray_float_t **KatArray, float value);
size_t  katarray_float_set_prepend(katarray_float_t **KatArray, float value);
size_t  katarray_float_set_insert_at(katarray_float_t **KatArray, ssize_t index, float value);
size_t  katarray_float_set_overwrite_at(katarray_float_t **KatArray, ssize_t index, float value);

// (removers) //
float   katarray_float_remove_append(katarray_float_t **KatArray);
float   katarray_float_remove_prepend(katarray_float_t **KatArray);
float   katarray_float_remove_insert_at(katarray_float_t **KatArray, size_t index);
float   katarray_float_remove_overwrite_at(katarray_float_t **KatArray, size_t index);

// (getters) //
float   katarray_float_get_value_at(katarray_float_t *KatArray, size_t index);
float   katarray_float_get_first_value(katarray_float_t *KatArray);
float   katarray_float_get_last_value(katarray_float_t *KatArray);
size_t  katarray_float_get_length(katarray_float_t *KatArray);
size_t  katarray_float_get_capacity(katarray_float_t *KatArray);

// (QUEUE OPERATIONS) //
size_t  katarray_float_enqueue(katarray_float_t **KatArray, float value);
float   katarray_float_dequeue(katarray_float_t **KatArray);
float   katarray_float_peek_head(katarray_float_t *KatArray);

// (STACK OPERATIONS) //
size_t  katarray_float_push(katarray_float_t **KatArray, float value);
float   katarray_float_pop(katarray_float_t **KatArray);
float   katarray_float_peek_top(katarray_float_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char    katarray_float_is_full(katarray_float_t *KatArray);
char    katarray_float_is_empty(katarray_float_t *KatArray);


////* INT LIB *////

typedef struct KatArray_int {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    int initial_value;
    int *list;
} katarray_int_t;

// (printers) //
void    katarray_int_length_print(katarray_int_t *KatArray, char option);
void    katarray_int_capacity_print(katarray_int_t *KatArray, char option);
void    katarray_int_debug_print(katarray_int_t *KatArray, char option);

// (management) //
katarray_int_t *katarray_int_create(size_t length, int initial_value, size_t capacity, char shrinkable);
void    katarray_int_free(katarray_int_t *KatArray);
void    katarray_int_resize(katarray_int_t **KatArray, double growth_factor, size_t add_factor);
void    katarray_int_convert(katarray_int_t **KatArray);
void    katarray_int_reset(katarray_int_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t  katarray_int_set_append(katarray_int_t **KatArray, int value);
size_t  katarray_int_set_prepend(katarray_int_t **KatArray, int value);
size_t  katarray_int_set_insert_at(katarray_int_t **KatArray, ssize_t index, int value);
size_t  katarray_int_set_overwrite_at(katarray_int_t **KatArray, ssize_t index, int value);

// (removers) //
int     katarray_int_remove_append(katarray_int_t **KatArray);
int     katarray_int_remove_prepend(katarray_int_t **KatArray);
int     katarray_int_remove_insert_at(katarray_int_t **KatArray, size_t index);
int     katarray_int_remove_overwrite_at(katarray_int_t **KatArray, size_t index);

// (getters) //
int     katarray_int_get_value_at(katarray_int_t *KatArray, size_t index);
int     katarray_int_get_first_value(katarray_int_t *KatArray);
int     katarray_int_get_last_value(katarray_int_t *KatArray);
size_t  katarray_int_get_length(katarray_int_t *KatArray);
size_t  katarray_int_get_capacity(katarray_int_t *KatArray);

// (QUEUE OPERATIONS) //
size_t  katarray_int_enqueue(katarray_int_t **KatArray, int value);
int     katarray_int_dequeue(katarray_int_t **KatArray);
int     katarray_int_peek_head(katarray_int_t *KatArray);

// (STACK OPERATIONS) //
size_t  katarray_int_push(katarray_int_t **KatArray, int value);
int     katarray_int_pop(katarray_int_t **KatArray);
int     katarray_int_peek_top(katarray_int_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char    katarray_int_is_full(katarray_int_t *KatArray);
char    katarray_int_is_empty(katarray_int_t *KatArray);


////* LONG LIB *////

typedef struct KatArray_long {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    long initial_value;
    long *list;
} katarray_long_t;

// (printers) //
void    katarray_long_length_print(katarray_long_t *KatArray, char option);
void    katarray_long_capacity_print(katarray_long_t *KatArray, char option);
void    katarray_long_debug_print(katarray_long_t *KatArray, char option);

// (management) //
katarray_long_t *katarray_long_create(size_t length, long initial_value, size_t capacity, char shrinkable);
void    katarray_long_free(katarray_long_t *KatArray);
void    katarray_long_resize(katarray_long_t **KatArray, double growth_factor, size_t add_factor);
void    katarray_long_convert(katarray_long_t **KatArray);
void    katarray_long_reset(katarray_long_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t  katarray_long_set_append(katarray_long_t **KatArray, long value);
size_t  katarray_long_set_prepend(katarray_long_t **KatArray, long value);
size_t  katarray_long_set_insert_at(katarray_long_t **KatArray, ssize_t index, long value);
size_t  katarray_long_set_overwrite_at(katarray_long_t **KatArray, ssize_t index, long value);

// (removers) //
long    katarray_long_remove_append(katarray_long_t **KatArray);
long    katarray_long_remove_prepend(katarray_long_t **KatArray);
long    katarray_long_remove_insert_at(katarray_long_t **KatArray, size_t index);
long    katarray_long_remove_overwrite_at(katarray_long_t **KatArray, size_t index);

// (getters) //
long    katarray_long_get_value_at(katarray_long_t *KatArray, size_t index);
long    katarray_long_get_first_value(katarray_long_t *KatArray);
long    katarray_long_get_last_value(katarray_long_t *KatArray);
size_t  katarray_long_get_length(katarray_long_t *KatArray);
size_t  katarray_long_get_capacity(katarray_long_t *KatArray);

// (QUEUE OPERATIONS) //
size_t  katarray_long_enqueue(katarray_long_t **KatArray, long value);
long    katarray_long_dequeue(katarray_long_t **KatArray);
long    katarray_long_peek_head(katarray_long_t *KatArray);

// (STACK OPERATIONS) //
size_t  katarray_long_push(katarray_long_t **KatArray, long value);
long    katarray_long_pop(katarray_long_t **KatArray);
long    katarray_long_peek_top(katarray_long_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char    katarray_long_is_full(katarray_long_t *KatArray);
char    katarray_long_is_empty(katarray_long_t *KatArray);


////* LONG DOUBLE LIB *////

typedef struct KatArray_longdouble {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    long double initial_value;
    long double *list;
} katarray_longdouble_t;

// (printers) //
void        katarray_longdouble_length_print(katarray_longdouble_t *KatArray, char option);
void        katarray_longdouble_capacity_print(katarray_longdouble_t *KatArray, char option);
void        katarray_longdouble_debug_print(katarray_longdouble_t *KatArray, char option);

// (management) //
katarray_longdouble_t *katarray_longdouble_create(size_t length, long double initial_value, size_t capacity, char shrinkable);
void        katarray_longdouble_free(katarray_longdouble_t *KatArray);
void        katarray_longdouble_resize(katarray_longdouble_t **KatArray, double growth_factor, size_t add_factor);
void        katarray_longdouble_convert(katarray_longdouble_t **KatArray);
void        katarray_longdouble_reset(katarray_longdouble_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t      katarray_longdouble_set_append(katarray_longdouble_t **KatArray, long double value);
size_t      katarray_longdouble_set_prepend(katarray_longdouble_t **KatArray, long double value);
size_t      katarray_longdouble_set_insert_at(katarray_longdouble_t **KatArray, ssize_t index, long double value);
size_t      katarray_longdouble_set_overwrite_at(katarray_longdouble_t **KatArray, ssize_t index, long double value);

// (removers) //
long double katarray_longdouble_remove_append(katarray_longdouble_t **KatArray);
long double katarray_longdouble_remove_prepend(katarray_longdouble_t **KatArray);
long double katarray_longdouble_remove_insert_at(katarray_longdouble_t **KatArray, size_t index);
long double katarray_longdouble_remove_overwrite_at(katarray_longdouble_t **KatArray, size_t index);

// (getters) //
long double katarray_longdouble_get_value_at(katarray_longdouble_t *KatArray, size_t index);
long double katarray_longdouble_get_first_value(katarray_longdouble_t *KatArray);
long double katarray_longdouble_get_last_value(katarray_longdouble_t *KatArray);
size_t      katarray_longdouble_get_length(katarray_longdouble_t *KatArray);
size_t      katarray_longdouble_get_capacity(katarray_longdouble_t *KatArray);

// (QUEUE OPERATIONS) //
size_t      katarray_longdouble_enqueue(katarray_longdouble_t **KatArray, long double value);
long double katarray_longdouble_dequeue(katarray_longdouble_t **KatArray);
long double katarray_longdouble_peek_head(katarray_longdouble_t *KatArray);

// (STACK OPERATIONS) //
size_t      katarray_longdouble_push(katarray_longdouble_t **KatArray, long double value);
long double katarray_longdouble_pop(katarray_longdouble_t **KatArray);
long double katarray_longdouble_peek_top(katarray_longdouble_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char        katarray_longdouble_is_full(katarray_longdouble_t *KatArray);
char        katarray_longdouble_is_empty(katarray_longdouble_t *KatArray);


////* LONG LONG LIB *////

typedef struct KatArray_longlong {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    long long initial_value;
    long long *list;
} katarray_longlong_t;

// (printers) //
void        katarray_longlong_length_print(katarray_longlong_t *KatArray, char option);
void        katarray_longlong_capacity_print(katarray_longlong_t *KatArray, char option);
void        katarray_longlong_debug_print(katarray_longlong_t *KatArray, char option);

// (management) //
katarray_longlong_t *katarray_longlong_create(size_t length, long long initial_value, size_t capacity, char shrinkable);
void        katarray_longlong_free(katarray_longlong_t *KatArray);
void        katarray_longlong_resize(katarray_longlong_t **KatArray, double growth_factor, size_t add_factor);
void        katarray_longlong_convert(katarray_longlong_t **KatArray);
void        katarray_longlong_reset(katarray_longlong_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t      katarray_longlong_set_append(katarray_longlong_t **KatArray, long long value);
size_t      katarray_longlong_set_prepend(katarray_longlong_t **KatArray, long long value);
size_t      katarray_longlong_set_insert_at(katarray_longlong_t **KatArray, ssize_t index, long long value);
size_t      katarray_longlong_set_overwrite_at(katarray_longlong_t **KatArray, ssize_t index, long long value);

// (removers) //
long long   katarray_longlong_remove_append(katarray_longlong_t **KatArray);
long long   katarray_longlong_remove_prepend(katarray_longlong_t **KatArray);
long long   katarray_longlong_remove_insert_at(katarray_longlong_t **KatArray, size_t index);
long long   katarray_longlong_remove_overwrite_at(katarray_longlong_t **KatArray, size_t index);

// (getters) //
long long   katarray_longlong_get_value_at(katarray_longlong_t *KatArray, size_t index);
long long   katarray_longlong_get_first_value(katarray_longlong_t *KatArray);
long long   katarray_longlong_get_last_value(katarray_longlong_t *KatArray);
size_t      katarray_longlong_get_length(katarray_longlong_t *KatArray);
size_t      katarray_longlong_get_capacity(katarray_longlong_t *KatArray);

// (QUEUE OPERATIONS) //
size_t      katarray_longlong_enqueue(katarray_longlong_t **KatArray, long long value);
long long   katarray_longlong_dequeue(katarray_longlong_t **KatArray);
long long   katarray_longlong_peek_head(katarray_longlong_t *KatArray);

// (STACK OPERATIONS) //
size_t      katarray_longlong_push(katarray_longlong_t **KatArray, long long value);
long long   katarray_longlong_pop(katarray_longlong_t **KatArray);
long long   katarray_longlong_peek_top(katarray_longlong_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char        katarray_longlong_is_full(katarray_longlong_t *KatArray);
char        katarray_longlong_is_empty(katarray_longlong_t *KatArray);


////* SHORT LIB *////

typedef struct KatArray_short {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    short initial_value;
    short *list;
} katarray_short_t;

// (printers) //
void    katarray_short_length_print(katarray_short_t *KatArray, char option);
void    katarray_short_capacity_print(katarray_short_t *KatArray, char option);
void    katarray_short_debug_print(katarray_short_t *KatArray, char option);

// (management) //
katarray_short_t *katarray_short_create(size_t length, short initial_value, size_t capacity, char shrinkable);
void    katarray_short_free(katarray_short_t *KatArray);
void    katarray_short_resize(katarray_short_t **KatArray, double growth_factor, size_t add_factor);
void    katarray_short_convert(katarray_short_t **KatArray);
void    katarray_short_reset(katarray_short_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t  katarray_short_set_append(katarray_short_t **KatArray, short value);
size_t  katarray_short_set_prepend(katarray_short_t **KatArray, short value);
size_t  katarray_short_set_insert_at(katarray_short_t **KatArray, ssize_t index, short value);
size_t  katarray_short_set_overwrite_at(katarray_short_t **KatArray, ssize_t index, short value);

// (removers) //
short   katarray_short_remove_append(katarray_short_t **KatArray);
short   katarray_short_remove_prepend(katarray_short_t **KatArray);
short   katarray_short_remove_insert_at(katarray_short_t **KatArray, size_t index);
short   katarray_short_remove_overwrite_at(katarray_short_t **KatArray, size_t index);

// (getters) //
short   katarray_short_get_value_at(katarray_short_t *KatArray, size_t index);
short   katarray_short_get_first_value(katarray_short_t *KatArray);
short   katarray_short_get_last_value(katarray_short_t *KatArray);
size_t  katarray_short_get_length(katarray_short_t *KatArray);
size_t  katarray_short_get_capacity(katarray_short_t *KatArray);

// (QUEUE OPERATIONS) //
size_t  katarray_short_enqueue(katarray_short_t **KatArray, short value);
short   katarray_short_dequeue(katarray_short_t **KatArray);
short   katarray_short_peek_head(katarray_short_t *KatArray);

// (STACK OPERATIONS) //
size_t  katarray_short_push(katarray_short_t **KatArray, short value);
short   katarray_short_pop(katarray_short_t **KatArray);
short   katarray_short_peek_top(katarray_short_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char    katarray_short_is_full(katarray_short_t *KatArray);
char    katarray_short_is_empty(katarray_short_t *KatArray);


////* UNSIGNED CHAR LIB *////

typedef struct KatArray_uchar {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    unsigned char initial_value;
    unsigned char *list;
} katarray_uchar_t;

// (printers) //
void            katarray_uchar_length_print(katarray_uchar_t *KatArray, char option);
void            katarray_uchar_capacity_print(katarray_uchar_t *KatArray, char option);
void            katarray_uchar_debug_print(katarray_uchar_t *KatArray, char option);

// (management) //
katarray_uchar_t *katarray_uchar_create(size_t length, unsigned char initial_value, size_t capacity, char shrinkable);
void            katarray_uchar_free(katarray_uchar_t *KatArray);
void            katarray_uchar_resize(katarray_uchar_t **KatArray, double growth_factor, size_t add_factor);
void            katarray_uchar_convert(katarray_uchar_t **KatArray);
void            katarray_uchar_reset(katarray_uchar_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t          katarray_uchar_set_append(katarray_uchar_t **KatArray, unsigned char value);
size_t          katarray_uchar_set_prepend(katarray_uchar_t **KatArray, unsigned char value);
size_t          katarray_uchar_set_insert_at(katarray_uchar_t **KatArray, ssize_t index, unsigned char value);
size_t          katarray_uchar_set_overwrite_at(katarray_uchar_t **KatArray, ssize_t index, unsigned char value);

// (removers) //
unsigned char   katarray_uchar_remove_append(katarray_uchar_t **KatArray);
unsigned char   katarray_uchar_remove_prepend(katarray_uchar_t **KatArray);
unsigned char   katarray_uchar_remove_insert_at(katarray_uchar_t **KatArray, size_t index);
unsigned char   katarray_uchar_remove_overwrite_at(katarray_uchar_t **KatArray, size_t index);

// (getters) //
unsigned char   katarray_uchar_get_value_at(katarray_uchar_t *KatArray, size_t index);
unsigned char   katarray_uchar_get_first_value(katarray_uchar_t *KatArray);
unsigned char   katarray_uchar_get_last_value(katarray_uchar_t *KatArray);
size_t          katarray_uchar_get_length(katarray_uchar_t *KatArray);
size_t          katarray_uchar_get_capacity(katarray_uchar_t *KatArray);

// (QUEUE OPERATIONS) //
size_t          katarray_uchar_enqueue(katarray_uchar_t **KatArray, unsigned char value);
unsigned char   katarray_uchar_dequeue(katarray_uchar_t **KatArray);
unsigned char   katarray_uchar_peek_head(katarray_uchar_t *KatArray);

// (STACK OPERATIONS) //
size_t          katarray_uchar_push(katarray_uchar_t **KatArray, unsigned char value);
unsigned char   katarray_uchar_pop(katarray_uchar_t **KatArray);
unsigned char   katarray_uchar_peek_top(katarray_uchar_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char            katarray_uchar_is_full(katarray_uchar_t *KatArray);
char            katarray_uchar_is_empty(katarray_uchar_t *KatArray);


////* UNSIGNED INT LIB *////

typedef struct KatArray_uint {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    unsigned int initial_value;
    unsigned int *list;
} katarray_uint_t;

// (printers) //
void            katarray_uint_length_print(katarray_uint_t *KatArray, char option);
void            katarray_uint_capacity_print(katarray_uint_t *KatArray, char option);
void            katarray_uint_debug_print(katarray_uint_t *KatArray, char option);

// (management) //
katarray_uint_t *katarray_uint_create(size_t length, unsigned int initial_value, size_t capacity, char shrinkable);
void            katarray_uint_free(katarray_uint_t *KatArray);
void            katarray_uint_resize(katarray_uint_t **KatArray, double growth_factor, size_t add_factor);
void            katarray_uint_convert(katarray_uint_t **KatArray);
void            katarray_uint_reset(katarray_uint_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t          katarray_uint_set_append(katarray_uint_t **KatArray, unsigned int value);
size_t          katarray_uint_set_prepend(katarray_uint_t **KatArray, unsigned int value);
size_t          katarray_uint_set_insert_at(katarray_uint_t **KatArray, ssize_t index, unsigned int value);
size_t          katarray_uint_set_overwrite_at(katarray_uint_t **KatArray, ssize_t index, unsigned int value);

// (removers) //
unsigned int    katarray_uint_remove_append(katarray_uint_t **KatArray);
unsigned int    katarray_uint_remove_prepend(katarray_uint_t **KatArray);
unsigned int    katarray_uint_remove_insert_at(katarray_uint_t **KatArray, size_t index);
unsigned int    katarray_uint_remove_overwrite_at(katarray_uint_t **KatArray, size_t index);

// (getters) //
unsigned int    katarray_uint_get_value_at(katarray_uint_t *KatArray, size_t index);
unsigned int    katarray_uint_get_first_value(katarray_uint_t *KatArray);
unsigned int    katarray_uint_get_last_value(katarray_uint_t *KatArray);
size_t          katarray_uint_get_length(katarray_uint_t *KatArray);
size_t          katarray_uint_get_capacity(katarray_uint_t *KatArray);

// (QUEUE OPERATIONS) //
size_t          katarray_uint_enqueue(katarray_uint_t **KatArray, unsigned int value);
unsigned int    katarray_uint_dequeue(katarray_uint_t **KatArray);
unsigned int    katarray_uint_peek_head(katarray_uint_t *KatArray);

// (STACK OPERATIONS) //
size_t          katarray_uint_push(katarray_uint_t **KatArray, unsigned int value);
unsigned int    katarray_uint_pop(katarray_uint_t **KatArray);
unsigned int    katarray_uint_peek_top(katarray_uint_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char            katarray_uint_is_full(katarray_uint_t *KatArray);
char            katarray_uint_is_empty(katarray_uint_t *KatArray);


////* UNSIGNED LONG LIB *////

typedef struct KatArray_ulong {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    unsigned long initial_value;
    unsigned long *list;
} katarray_ulong_t;

// (printers) //
void            katarray_ulong_length_prlong(katarray_ulong_t *KatArray, char option);
void            katarray_ulong_capacity_prlong(katarray_ulong_t *KatArray, char option);
void            katarray_ulong_debug_prlong(katarray_ulong_t *KatArray, char option);

// (management) //
katarray_ulong_t *katarray_ulong_create(size_t length, unsigned long initial_value, size_t capacity, char shrinkable);
void            katarray_ulong_free(katarray_ulong_t *KatArray);
void            katarray_ulong_resize(katarray_ulong_t **KatArray, double growth_factor, size_t add_factor);
void            katarray_ulong_convert(katarray_ulong_t **KatArray);
void            katarray_ulong_reset(katarray_ulong_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t          katarray_ulong_set_append(katarray_ulong_t **KatArray, unsigned long value);
size_t          katarray_ulong_set_prepend(katarray_ulong_t **KatArray, unsigned long value);
size_t          katarray_ulong_set_insert_at(katarray_ulong_t **KatArray, ssize_t index, unsigned long value);
size_t          katarray_ulong_set_overwrite_at(katarray_ulong_t **KatArray, ssize_t index, unsigned long value);

// (removers) //
unsigned long   katarray_ulong_remove_append(katarray_ulong_t **KatArray);
unsigned long   katarray_ulong_remove_prepend(katarray_ulong_t **KatArray);
unsigned long   katarray_ulong_remove_insert_at(katarray_ulong_t **KatArray, size_t index);
unsigned long   katarray_ulong_remove_overwrite_at(katarray_ulong_t **KatArray, size_t index);

// (getters) //
unsigned long   katarray_ulong_get_value_at(katarray_ulong_t *KatArray, size_t index);
unsigned long   katarray_ulong_get_first_value(katarray_ulong_t *KatArray);
unsigned long   katarray_ulong_get_last_value(katarray_ulong_t *KatArray);
size_t          katarray_ulong_get_length(katarray_ulong_t *KatArray);
size_t          katarray_ulong_get_capacity(katarray_ulong_t *KatArray);

// (QUEUE OPERATIONS) //
size_t          katarray_ulong_enqueue(katarray_ulong_t **KatArray, unsigned long value);
unsigned long   katarray_ulong_dequeue(katarray_ulong_t **KatArray);
unsigned long   katarray_ulong_peek_head(katarray_ulong_t *KatArray);

// (STACK OPERATIONS) //
size_t          katarray_ulong_push(katarray_ulong_t **KatArray, unsigned long value);
unsigned long   katarray_ulong_pop(katarray_ulong_t **KatArray);
unsigned long   katarray_ulong_peek_top(katarray_ulong_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char            katarray_ulong_is_full(katarray_ulong_t *KatArray);
char            katarray_ulong_is_empty(katarray_ulong_t *KatArray);


////* UNSIGNED LONG LONG LIB *////

typedef struct KatArray_ulonglong {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    unsigned long long initial_value;
    unsigned long long *list;
} katarray_ulonglong_t;

// (printers) //
void                katarray_ulonglong_length_prlong(katarray_ulonglong_t *KatArray, char option);
void                katarray_ulonglong_capacity_prlong(katarray_ulonglong_t *KatArray, char option);
void                katarray_ulonglong_debug_prlong(katarray_ulonglong_t *KatArray, char option);

// (management) //
katarray_ulonglong_t *katarray_ulonglong_create(size_t length, unsigned long long initial_value, size_t capacity, char shrinkable);
void                katarray_ulonglong_free(katarray_ulonglong_t *KatArray);
void                katarray_ulonglong_resize(katarray_ulonglong_t **KatArray, double growth_factor, size_t add_factor);
void                katarray_ulonglong_convert(katarray_ulonglong_t **KatArray);
void                katarray_ulonglong_reset(katarray_ulonglong_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t              katarray_ulonglong_set_append(katarray_ulonglong_t **KatArray, unsigned long long value);
size_t              katarray_ulonglong_set_prepend(katarray_ulonglong_t **KatArray, unsigned long long value);
size_t              katarray_ulonglong_set_insert_at(katarray_ulonglong_t **KatArray, ssize_t index, unsigned long long value);
size_t              katarray_ulonglong_set_overwrite_at(katarray_ulonglong_t **KatArray, ssize_t index, unsigned long long value);

// (removers) //
unsigned long long  katarray_ulonglong_remove_append(katarray_ulonglong_t **KatArray);
unsigned long long  katarray_ulonglong_remove_prepend(katarray_ulonglong_t **KatArray);
unsigned long long  katarray_ulonglong_remove_insert_at(katarray_ulonglong_t **KatArray, size_t index);
unsigned long long  katarray_ulonglong_remove_overwrite_at(katarray_ulonglong_t **KatArray, size_t index);

// (getters) //
unsigned long long  katarray_ulonglong_get_value_at(katarray_ulonglong_t *KatArray, size_t index);
unsigned long long  katarray_ulonglong_get_first_value(katarray_ulonglong_t *KatArray);
unsigned long long  katarray_ulonglong_get_last_value(katarray_ulonglong_t *KatArray);
size_t              katarray_ulonglong_get_length(katarray_ulonglong_t *KatArray);
size_t              katarray_ulonglong_get_capacity(katarray_ulonglong_t *KatArray);

// (QUEUE OPERATIONS) //
size_t              katarray_ulonglong_enqueue(katarray_ulonglong_t **KatArray, unsigned long long value);
unsigned long long  katarray_ulonglong_dequeue(katarray_ulonglong_t **KatArray);
unsigned long long  katarray_ulonglong_peek_head(katarray_ulonglong_t *KatArray);

// (STACK OPERATIONS) //
size_t              katarray_ulonglong_push(katarray_ulonglong_t **KatArray, unsigned long long value);
unsigned long long  katarray_ulonglong_pop(katarray_ulonglong_t **KatArray);
unsigned long long  katarray_ulonglong_peek_top(katarray_ulonglong_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char                katarray_ulonglong_is_full(katarray_ulonglong_t *KatArray);
char                katarray_ulonglong_is_empty(katarray_ulonglong_t *KatArray);


////* UNSIGNED SHORT LIB *////

typedef struct KatArray_unsigned {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    unsigned short initial_value;
    unsigned short *list;
} katarray_ushort_t;

// (printers) //
void            katarray_ushort_length_prshort(katarray_ushort_t *KatArray, char option);
void            katarray_ushort_capacity_prshort(katarray_ushort_t *KatArray, char option);
void            katarray_ushort_debug_prshort(katarray_ushort_t *KatArray, char option);

// (management) //
katarray_ushort_t *katarray_ushort_create(size_t length, unsigned short initial_value, size_t capacity, char shrinkable);
void            katarray_ushort_free(katarray_ushort_t *KatArray);
void            katarray_ushort_resize(katarray_ushort_t **KatArray, double growth_factor, size_t add_factor);
void            katarray_ushort_convert(katarray_ushort_t **KatArray);
void            katarray_ushort_reset(katarray_ushort_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t          katarray_ushort_set_append(katarray_ushort_t **KatArray, unsigned short value);
size_t          katarray_ushort_set_prepend(katarray_ushort_t **KatArray, unsigned short value);
size_t          katarray_ushort_set_insert_at(katarray_ushort_t **KatArray, ssize_t index, unsigned short value);
size_t          katarray_ushort_set_overwrite_at(katarray_ushort_t **KatArray, ssize_t index, unsigned short value);

// (removers) //
unsigned short  katarray_ushort_remove_append(katarray_ushort_t **KatArray);
unsigned short  katarray_ushort_remove_prepend(katarray_ushort_t **KatArray);
unsigned short  katarray_ushort_remove_insert_at(katarray_ushort_t **KatArray, size_t index);
unsigned short  katarray_ushort_remove_overwrite_at(katarray_ushort_t **KatArray, size_t index);

// (getters) //
unsigned short  katarray_ushort_get_value_at(katarray_ushort_t *KatArray, size_t index);
unsigned short  katarray_ushort_get_first_value(katarray_ushort_t *KatArray);
unsigned short  katarray_ushort_get_last_value(katarray_ushort_t *KatArray);
size_t          katarray_ushort_get_length(katarray_ushort_t *KatArray);
size_t          katarray_ushort_get_capacity(katarray_ushort_t *KatArray);

// (QUEUE OPERATIONS) //
size_t          katarray_ushort_enqueue(katarray_ushort_t **KatArray, unsigned short value);
unsigned short  katarray_ushort_dequeue(katarray_ushort_t **KatArray);
unsigned short  katarray_ushort_peek_head(katarray_ushort_t *KatArray);

// (STACK OPERATIONS) //
size_t          katarray_ushort_push(katarray_ushort_t **KatArray, unsigned short value);
unsigned short  katarray_ushort_pop(katarray_ushort_t **KatArray);
unsigned short  katarray_ushort_peek_top(katarray_ushort_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char            katarray_ushort_is_full(katarray_ushort_t *KatArray);
char            katarray_ushort_is_empty(katarray_ushort_t *KatArray);


////* VOID POINTER LIB *////

typedef struct KatArray_voidp {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    void* initial_value;
    void* *list;
} katarray_voidp_t;

// (printers) //
void    katarray_voidp_length_print(katarray_voidp_t *KatArray, char option);
void    katarray_voidp_capacity_print(katarray_voidp_t *KatArray, char option);
void    katarray_voidp_debug_print(katarray_voidp_t *KatArray, char option);

// (management) //
katarray_voidp_t *katarray_voidp_create(size_t length, void* initial_value, size_t capacity, char shrinkable);
void    katarray_voidp_free(katarray_voidp_t *KatArray);
void    katarray_voidp_resize(katarray_voidp_t **KatArray, double growth_factor, size_t add_factor);
void    katarray_voidp_convert(katarray_voidp_t **KatArray);
void    katarray_voidp_reset(katarray_voidp_t **KatArray, size_t length, size_t capacity);

// (setters) //
size_t  katarray_voidp_set_append(katarray_voidp_t **KatArray, void* value);
size_t  katarray_voidp_set_prepend(katarray_voidp_t **KatArray, void* value);
size_t  katarray_voidp_set_insert_at(katarray_voidp_t **KatArray, ssize_t index, void* value);
size_t  katarray_voidp_set_overwrite_at(katarray_voidp_t **KatArray, ssize_t index, void* value);

// (removers) //
void*   katarray_voidp_remove_append(katarray_voidp_t **KatArray);
void*   katarray_voidp_remove_prepend(katarray_voidp_t **KatArray);
void*   katarray_voidp_remove_insert_at(katarray_voidp_t **KatArray, size_t index);
void*   katarray_voidp_remove_overwrite_at(katarray_voidp_t **KatArray, size_t index);

// (getters) //
void*   katarray_voidp_get_value_at(katarray_voidp_t *KatArray, size_t index);
void*   katarray_voidp_get_first_value(katarray_voidp_t *KatArray);
void*   katarray_voidp_get_last_value(katarray_voidp_t *KatArray);
size_t  katarray_voidp_get_length(katarray_voidp_t *KatArray);
size_t  katarray_voidp_get_capacity(katarray_voidp_t *KatArray);

// (QUEUE OPERATIONS) //
size_t  katarray_voidp_enqueue(katarray_voidp_t **KatArray, void* value);
void*   katarray_voidp_dequeue(katarray_voidp_t **KatArray);
void*   katarray_voidp_peek_head(katarray_voidp_t *KatArray);

// (STACK OPERATIONS) //
size_t  katarray_voidp_push(katarray_voidp_t **KatArray, void* value);
void*   katarray_voidp_pop(katarray_voidp_t **KatArray);
void*   katarray_voidp_peek_top(katarray_voidp_t *KatArray);

// (QUEUE + STACK + RINGBUFFER EXTRAS) //
char    katarray_voidp_is_full(katarray_voidp_t *KatArray);
char    katarray_voidp_is_empty(katarray_voidp_t *KatArray);

#endif