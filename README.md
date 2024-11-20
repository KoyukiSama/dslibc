# dslibc
A library where I'll recreate datastructures that will be generically used.

## Future datastructs:

! I'll try to make all of these for all data types to reduce cache missallignment

### - ArrayList -
1. capacity as initialization parameter
2. Length in struct to check length
3. RingBuffered under the hood to save memory
4. Start ArrayList at 25% of the array capacity so that add_start will be O(1)

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
1. arraylist_print

(initialization and cleanup)
1. arraylist_create
2. arraylist_free

(setters)
1. arraylist_set_append        O(1) unless resize O(n)
2. arraylist_set_prepend      O(1) unless resize O(n)
3. arraylist_set_insert_at     O(n) unless resize O(n)  { O(2n) }
4. arraylist_set_overwrite_at  O(1) unless resize O(n)

(removers)
1. arraylist_remove_end
2. arraylist_remove_start
3. arraylist_remove_uninsert

(getters)
1. arraylist_get_value
2. arraylist_get_index
3. arraylist_get_length
4. arraylist_get_capacity
5. arraylist_get_empty   // shows if arraylist is empty

(internal helper function)
1. arraylist_resize

SOON maybe also serealization


### - LinkedList -

### - Hashmap -

### - RingBuffer -