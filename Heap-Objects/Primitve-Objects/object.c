#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "object.h"
#include "../Dynamic-Array/dynamic_array.h"

obj_t *create_int(int value)
{
    obj_t *obj = malloc(sizeof(obj_t));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = INTEGER;
    obj->data.a_int = value;

    return obj;
}

obj_t *create_float(float value)
{
    obj_t *obj = malloc(sizeof(obj_t));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = FLOAT;
    obj->data.a_float = value;

    return obj;
}

obj_t *create_string(char *value)
{
    obj_t *obj = malloc(sizeof(obj_t));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = STRING;
    obj->data.a_str = malloc(sizeof(strlen(value) + 1) * sizeof(char *));
    strcpy(obj->data.a_str, value);

    return obj;
}

obj_t *create_array(size_t capacity)
{
    obj_t *obj = malloc(sizeof(obj_t));
    if (obj == NULL)
    {
        return NULL;
    }
    obj->kind = ARRAY;
    obj->data.a_arr = malloc(sizeof(darray));
    if (obj->data.a_arr == NULL)
    {
        free(obj);
        return NULL;
    }
    darray *arr = obj->data.a_arr;
    arr->size = 0;
    arr->capacity = capacity;
    arr->objects = calloc(capacity, sizeof(obj_t *));
    if (arr->objects == NULL)
    {
        free(obj);
        free(arr);
        return NULL;
    }
    return obj;
}

void print(obj_t *obj)
{
    switch (obj->kind)
    {
    case INTEGER:
    {
        printf("%d\n", obj->data.a_int);
        break;
    }
    case FLOAT:
    {
        printf("%f\n", obj->data.a_float);
        break;
    }
    case STRING:
    {
        printf("%s\n", obj->data.a_str);
        break;
    }
    case ARRAY:
    {
        darray *arr = obj->data.a_arr;
        for (int i = 0; i < arr->size; i++)
        {
            print(arr->objects[i]);
        }
        break;
    }
    default:
        break;
    }
}
