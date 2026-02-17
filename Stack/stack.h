#include <stdlib.h>

typedef struct Stack
{
    size_t size;
    size_t capacity;
    void **data;
} stack;

stack *create_stack(size_t capacity);
void push(stack *st, void *obj);
void *pop(stack *st);
void free_stack(stack *st);