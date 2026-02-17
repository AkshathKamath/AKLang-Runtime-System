#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack
{
    size_t size;
    size_t capacity;
    void **data;
} stack;

stack *create_stack(size_t capacity)
{
    stack *st = malloc(sizeof(stack));
    st->capacity = capacity;
    st->size = 0;
    st->data = malloc(sizeof(void *) * capacity);

    return st;
}

void push(stack *st, void *obj)
{
    if (st->size == st->capacity)
    {
        printf("Stack capacity reached, doubling capacity");
        void **new_ptr = realloc(st->data, 2 * st->capacity * sizeof(void *));
        if (new_ptr == NULL)
        {
            exit(1);
        }
        st->data = new_ptr;
        st->capacity = 2 * st->capacity;
    }
    st->data[st->size++] = obj;
    return;
}

void *pop(stack *st)
{
    if (st->size == 0)
    {
        return NULL;
    }
    return st->data[--st->size];
}

void free_stack(stack *st)
{
    if (st == NULL)
    {
        return;
    }
    if (st->data)
    {
        free(st->data);
    }
    free(st);
    return;
}

int main()
{
    stack *st = create_stack(2);
    int a = 5;
    int b = 6;
    push(st, &a);
    push(st, &b);
    printf("%d\n", *(int *)st->data[st->size - 1]);
    int *popped = pop(st);
    printf("Popped element: %d\n", *popped);
    printf("%d\n", *(int *)st->data[st->size - 1]);
    pop(st);

    // Bad idea, but with generic pointers we can push data of any type onto the stack
    int x = 1337;
    push(st, (void *)x); // Can push ints onto the stack as well by type casting it to void *
    int *ptr = malloc(sizeof(int));
    *ptr = 1024;
    push(st, ptr);

    float *fptr = malloc(sizeof(float));
    *fptr = 3.14;
    push(st, (void *)fptr);
    char string[] = "Sneklang is very slow!";
    size_t length = sizeof(string);
    // An alternate way of doing the 2 lines above
    // char *string = "Sneklang is very slow!";
    // size_t length = strlen(string) + 1;
    char *sptr = malloc(sizeof(char) * length);
    strcpy(sptr, string);
    push(st, (void *)sptr);

    free(st);

    return 0;
}
