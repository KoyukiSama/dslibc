# dslibc
A library where I'll recreate datastructures that will be generically used.

## Future datastructs:

! I'll try to make all of these void pointers

### - ArrayList -
1. capacity as initialization parameter
2. Length in struct to check length
3. RingBuffered under the hood to save memory
4. Start ArrayList at 25% of the array capacity so that add_start will be O(1)

(initialization and cleanup)
1. arraylist_create
2. arraylist_free

(setters)
3. arraylist_set_end
4. arraylist_set_start
5. arraylist_set_insert
6. arraylist_set_overwrite

(removers)
6. arraylist_remove_end
7. arraylist_remove_start
8. arraylist_remove_uninsert

(getters)
9.  arraylist_get_value
10. arraylist_get_index
11. arraylist_get_size
12. arraylist_get_capacity
13. arraylist_get_empty   // shows if arraylist is empty

(internal helper function)
14. arraylist_resize

SOON maybe also serealization


### - LinkedList -

### - Hashmap -

### - RingBuffer -