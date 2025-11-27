#include "../include/core.h"
#include "../include/registers.h"

bool running = true;

/** Programs **/
const int program[] = {
    push, 5,
    push, 6,
    add,
    ret 
};

int fetch(int idx)
{
    return program[idx];
}

void eval(int instr, Stack *stk)
{
    switch (instr)
    {
        case push:
        {
            stack_push(stk, program[++reg[ip]]);
            printf("data pushed: %d\n", program[reg[ip]]);
            break;
        }
        case pop: {
            int d = stack_pop(stk);
            printf("data popped: %d\n", d);
            break;
        }
        case add:
        {
            int a = stack_pop(stk);
            int b = stack_pop(stk);
            int result = b + a;
            printf("add: %d\n", result);
            stack_push(stk, result);
            break;
        }
        case mov:
        {
            break;
        }
        // case set:
        // {
        //     break;
        // }
        // case cmp:
        // {
        //     break;
        // }
        // case jmp:
        // {
        //     break;
        // }
        // case call:
        // {
        //     break;
        // }
        case ret:
        {
            running = false;
            break;
        }
        default:
        {
            fprintf(stderr, "instructions not exists.\n");
            running = false;
            break;
        }
    }
}

void run_vm()
{
    Stack stack;

    stack_init(&stack);
    while(running)
    {
        eval(fetch(reg[ip]), &stack);
        reg[ip]++;
    }
}