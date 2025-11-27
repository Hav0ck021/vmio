#ifndef STACK_H
#define STACK_H

#include "stdio.h"
#include "stdlib.h"
#include "registers.h"

#define MAX 256

typedef struct {            // Virtual Stack
    __uint64_t data[MAX];   // Program Steps
} Stack;

/** Functions **/
__uint8_t stack_init(Stack *stk);
__uint8_t stack_push(Stack *stk, int d);
int stack_pop(Stack *stk);

#endif // STACK_H