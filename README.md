# dslibc
A library where I'll recreate datastructures that will be generically used.

## Future datastructs:


### - ArrayList -

DONT USE arraylist->index_tail or index_start, these should be private and work with a ring buffer,
use arraylist_get_length or arraylist->length

(types of arraylist)
1. arraylist_char_... , arraylist_uchar
2. arraylist_short_..., arraylist_ushort
3. arraylist_int_..., arraylist_uint
4. arraylist_long_..., arraylist_ulong
5. arraylist_longlong_..., arraylist_ulonglong
6. arraylist_float_...,
7. arraylist_double_...,
8. arraylist_longdouble_...,
9. arraylist_voidp_...
10. arraylist_...           <-- this one will merge types together in an arraylist

(printer function)
1. arraylist_print_length
2. arraylist_print_capacity
3. arraylist_print_debug

(initialization and cleanup)
1. arraylist_create
2. arraylist_free
3. arraylist_reset
4. arraylist_convert -> will convert the special arraylist to a normal for whatever reason you might need this

(setters)
1. arraylist_set_append             O(1)   unless resize O(n)
2. arraylist_set_prepend            O(1)   unless resize O(n)
3. arraylist_set_insert_at          O(n/2) unless resize O(n)
4. arraylist_set_overwrite_at       O(1)   unless resize O(n)

-- Queue / ring buffer Operations--
5. arraylist_enqueue                O(1)
6. arraylist_dequeue                O(1)
7. arraylist_peek_head              O(1)
8. arraylist_is_full        // stack too O(1)
9. arraylist_is_empty       // stack too O(1)

-- Stack Operations
10. arraylist_push          // O(1)
11. arraylist_pop           // O(1)
12. arraylist_peek_top      // O(1)

(removers)
1. arraylist_remove_append          (removes last element)      // O(1)
2. arraylist_remove_prepend         (removes first element)     // O(1)
3. arraylist_remove_insert_at       (will remove in an uninsert manner) // O(n/2), 
                                                                     neg i O(1), 
                                                              i > length-1 O(1)
4. arraylist_remove_overwrite_at    (will overwrite with initial value) // O(1)

(getters)
1. arraylist_get_value_at       // O(1)
3. arraylist_get_first_value    // O(1)
4. arraylist_get_last_value     // O(1)
5. arraylist_get_length         // O(1)
6. arraylist_get_capacity       // O(1)

(searches)
1. linear search for index
2. binary search for index
3. iterative Search for index
4. linear search for index structs

(internal helper function)
1. arraylist_resize             // O(n)

you can use a static array but then you will have to create and initialize the struct your self.
```typedef struct Katarray_char {
    size_t length;
    size_t capacity;

    size_t index_start;
    size_t index_end;

    char shrinkable;
    char initial_value;
    char list[N]; <-- instead of char* list
} katarray_char_t;
```


### - LinkedList -
no need anymore since my arraylist beats a linked list

### - Stack -
no need anymore since my arraylist is also a stack.
I'll include operations for stacks in my arraylist same for queue.

### - Queue
look at stack

### - RingBuffer -
no need anymore since my arraylist works as a flawless ring buffer

### - Hashmap -