/*
    stack definition.
*/

#ifndef STACK_H
#define STACK_H

#include "stdio.h"
#include "stdlib.h"

#define MAX 256

typedef struct {
    int data[MAX];  // Program Steps
} Stack;

__uint8_t stack_init(Stack *stk);

__uint8_t stack_push(Stack *stk, int d);

int stack_pop(Stack *stk);

#endif // STACK_H