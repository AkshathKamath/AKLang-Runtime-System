#ifndef REF_COUNTER_H
#define REF_COUNTER_H

#include "Heap-Objects/Primitive-Objects/object.h"
#include "Heap-Objects/Dynamic-Array/dynamic_array.h"

typedef struct Object obj_t;

void increment_refCount(obj_t *obj);
void decrement_refCount(obj_t *obj);
void free_obj(obj_t *obj);

#endif
