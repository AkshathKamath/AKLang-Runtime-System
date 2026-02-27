#include <stdio.h>
#include <stdlib.h>
#include "Heap-Objects/Dynamic-Array/dynamic_array.h"
#include "Heap-Objects/Primitive-Objects/object.h"
#include "Garbage-Collector/Reference-Counting/ref_counter.h"

int main()
{
    // obj_t *arr = create_array(1);
    // obj_t *obj1 = create_int(5);
    // append(arr, obj1);
    // obj_t *obj2 = create_float(3.14);
    // append(arr, obj2);
    // obj_t *obj3 = create_string("Hi, my name is AK!");
    // append(arr, obj3);
    // obj_t *subarr = create_array(1);
    // obj_t *sub_obj = create_int(42);
    // obj_t *sub_obj2 = create_int(69);
    // append(subarr, sub_obj);
    // append(subarr, sub_obj2);
    // append(arr, subarr);

    // print(arr); // [5, 3.14, "Hi, my name is AK!", [42, 69]]

    obj_t *a = reassign_object(NULL, create_int(10));
    a = reassign_object(a, create_int(5));
    obj_t *arr = reassign_object(NULL, create_array(1));
    append(arr, a);
    append(arr, create_int(7));
    obj_t *b = reassign_object(NULL, a);
    print(b);
    printf("%d\n", a->ref_ct);
    printf("%d\n", arr->ref_ct);

    arr = reassign_object(arr, create_int(10));
    printf("%d\n", a->ref_ct);

    return 0;
}