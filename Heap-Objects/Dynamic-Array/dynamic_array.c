#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dynamic_array.h"

void append(obj_t *obj, obj_t *new_obj)
{
    if (obj == NULL || obj->kind != ARRAY || new_obj == NULL)
    {
        return;
    }
    darray *arr = obj->data.a_arr;
    if (arr->size == arr->capacity)
    {
        obj_t **temp = realloc(arr->objects, arr->capacity * 2 * sizeof(obj_t *));
        if (temp == NULL)
        {
            return;
        }
        arr->objects = temp;
        arr->capacity = 2 * arr->capacity;
    }
    arr->objects[arr->size++] = new_obj;
    return;
}

obj_t *get_array_obj(obj_t *obj, int index)
{
    if (obj == NULL || obj->kind != ARRAY)
    {
        return NULL;
    }
    darray *arr = obj->data.a_arr;
    if (index >= arr->size)
    {
        return NULL;
    }
    return arr->objects[index];
}

void set_array_obj(obj_t *obj, int index, obj_t *new_obj)
{
    if (obj == NULL || obj->kind != ARRAY || new_obj == NULL)
    {
        return;
    }
    darray *arr = obj->data.a_arr;
    if (index >= arr->size)
    {
        return;
    }
    arr->objects[index] = new_obj;
    return;
}