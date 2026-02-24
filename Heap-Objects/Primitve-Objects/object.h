#ifndef OBJECT_H
#define OBJECT_H

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
} obj_t;

obj_t *create_int(int value);
obj_t *create_float(float value);
obj_t *create_string(char *value);
obj_t *create_array(size_t capacity);
void print(obj_t *obj);

#endif