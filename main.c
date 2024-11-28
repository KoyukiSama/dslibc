#include "./ds_katarray/katarray.h"

int main(void) {
    katarray_int_t *KatArray katarray_int_create(0, 0, 10, 1);
    katarray_int_set_append(&KatArray, 20);
    katarray_int_print_length(&KatArray, 20);
}