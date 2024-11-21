# dslibc
A library where I'll recreate datastructures that will be generically used.

## Future datastructs:

! I'll try to make all of these for all data types to reduce cache missallignment

### - ArrayList -
1. initialization parameter, resizing in a negative manner option

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

(printer function)
1. arraylist_print_length
2. arraylist_print_capacity
3. arraylist_print_debug

(initialization and cleanup)
1. arraylist_create
2. arraylist_free

(setters)
1. arraylist_set_append             O(1)   unless resize O(n)
2. arraylist_set_prepend            O(1)   unless resize O(n)
3. arraylist_set_insert_at          O(n/2) unless resize O(n)
4. arraylist_set_overwrite_at       O(1)   unless resize O(n)

(removers)
1. arraylist_remove_append          (removes last element)
2. arraylist_remove_prepend         (removes first element)
3. arraylist_remove_insert_at       (will remove in an uninsert manner)
4. arraylist_remove_overwrite_at    (will overwrite with initial value)

(getters)
1. arraylist_get_value_at
2. arraylist_get_index_of
3. arraylist_get_length
4. arraylist_get_capacity

(internal helper function)
1. arraylist_resize

SOON maybe also serealization


### - LinkedList -

### - Hashmap -

### - RingBuffer -