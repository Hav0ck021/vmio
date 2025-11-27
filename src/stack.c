#include "../include/stack.h"
#include "../include/registers.h"

__uint8_t stack_init(Stack *stk)
{
    if(!stk)
    {
        fprintf(stderr, "Error: stack is null pointer, not declared.\n");
        return EXIT_FAILURE;
    }
    reg[sp] = -1;
    return EXIT_SUCCESS;
}

__uint8_t stack_push(Stack *stk, int d)
{
    if(reg[sp] >= MAX - 1)
    {
        fprintf(stderr, "Error: overflow in stack.\n");
        return EXIT_FAILURE;
    }
    stk->data[++reg[sp]] = d;
    return EXIT_SUCCESS;
}

int stack_pop(Stack *stk)
{
    if(reg[sp] < 0) 
    {
        fprintf(stderr, "Error: stack is empty.\n");
        return EXIT_FAILURE;
    }
    int d = stk->data[reg[sp]--];
    return d;
} 
