#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "Garbage-Collector/Reference-Counting/ref_counter.h"

void increment_refCount(obj_t *obj)
{
    if (obj == NULL)
    {
        return;
    }
    obj->ref_ct++;
    return;
}

void decrement_refCount(obj_t *obj)
{
    if (obj == NULL)
    {
        return;
    }
    obj->ref_ct--;
    if (obj->ref_ct == 0)
        free_obj(obj);
    return;
}

void free_obj(obj_t *obj)
{
    switch (obj->kind)
    {
    case INTEGER:
        break;
    case FLOAT:
        break;
    case STRING:
    {
        free(obj->data.a_str);
        break;
    }
    case ARRAY:
    {
        darray *arr = obj->data.a_arr;
        for (unsigned long i = 0; i < arr->size; i++)
            decrement_refCount(arr->objects[i]);
        free(arr->objects);
        free(arr);
        break;
    }

    default:
        break;
    }
    free(obj);
    printf("Object freed from memory\n");
    return;
}