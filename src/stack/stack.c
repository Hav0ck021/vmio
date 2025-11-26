#include "stack.h"

void stack_init(Stack *stk)
{
    if(!stk)
    {
        fprintf(stderr, "Error: stack is null pointer, not declared.\n");
        return;
    }
    stk->sp = -1;
}

void stack_push(Stack *stk, int d)
{
    if(stk->sp >= MAX - 1)
    {
        fprintf(stderr, "Error: overflow in stack.\n");
        return;
    }
    stk->data[++stk->sp] = d;
}

int stack_pop(Stack *stk)
{
    if(stk->sp < 0) 
    {
        fprintf(stderr, "Error: stack is empty.\n");
        return EXIT_FAILURE;
    }
    int d = stk->data[stk->sp--];
    return d;
} 
