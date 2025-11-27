#include "../include/core.h"
#include "../include/registers.h"

bool running = true;

/** Programs */
const int program[] = {
    PSH, 5,
    PSH, 6,
    ADD,
    EXT 
};

int fetch(int idx)
{
    return program[idx];
}

void eval(int instr, Stack *stack)
{
    switch (instr)
    {
        case PSH:
        {
            stack_push(stack, program[++reg[ip]]);
            printf("data pushed: %d\n", program[reg[ip]]);
            break;
        }
        case POP: {
            int d = stack_pop(stack);
            printf("data popped: %d\n", d);
            break;
        }
        case ADD:
        {
            int a = stack_pop(stack);
            int b = stack_pop(stack);
            int result = b + a;
            printf("add: %d\n", result);
            stack_push(stack, result);
            break;
        }
        case EXT:
        {
            running = false;
            break;
        }
    }
}

void run_vm()
{
    Stack stack; // Virtual Machine Stack
    stack_init(&stack);
    while(running)
    {
        eval(fetch(reg[ip]), &stack);
        reg[ip]++;
    }
}