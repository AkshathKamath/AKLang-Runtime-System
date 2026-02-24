#include <stdio.h>
#include <stdlib.h>
#include "Heap-Objects/Dynamic-Array/dynamic_array.h"
#include "Heap-Objects/Primitve-Objects/object.h"

int main()
{
    obj_t *arr = create_array(1);
    obj_t *obj1 = create_int(5);
    append(arr, obj1);
    obj_t *obj2 = create_float(3.14);
    append(arr, obj2);
    obj_t *obj3 = create_string("Hi, my name is AK!");
    append(arr, obj3);
    obj_t *subarr = create_array(1);
    obj_t *sub_obj = create_int(42);
    obj_t *sub_obj2 = create_int(69);
    append(subarr, sub_obj);
    append(subarr, sub_obj2);
    append(arr, subarr);

    print(arr);

    return 1;
}