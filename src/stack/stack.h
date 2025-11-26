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
    int sp;         // Stack Pointer
} Stack;

void stack_init(Stack *stk);

void stack_push(Stack *stk, int d);

int stack_pop(Stack *stk);

#endif // STACK_H