#ifndef OBJECT_H
#define OBJECT_H
#include <stddef.h>
#include "Heap-Objects/Dynamic-Array/dynamic_array.h"
#include "Garbage-Collector/Reference-Counting/ref_counter.h"

typedef struct DynamicArray darray;

typedef enum ObjectKind
{
    INTEGER,
    FLOAT,
    STRING,
    ARRAY
} obj_kind;

typedef union ObjectData
{
    int a_int;
    float a_float;
    char *a_str;
    darray *a_arr;
} obj_data;

typedef struct Object
{
    obj_kind kind;
    obj_data data;
    int ref_ct;
} obj_t;

obj_t *create_int(int value);
obj_t *create_float(float value);
obj_t *create_string(char *value);
obj_t *create_array(size_t capacity);
obj_t *reassign_object(obj_t *old_obj, obj_t *new_obj);
void print(obj_t *obj);

#endif