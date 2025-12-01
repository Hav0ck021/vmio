#ifndef VMIO_H
#define VMIO_H

#include "stdio.h"
#include "../include/stack.h"

extern bool running;

typedef enum {
    PSH,
    POP,
    ADD,
    SET,
    EXT
} Instructions;

int fetch(int idx);
void eval(int instr, Stack *stack);
void run_vm();

#endif // VMIO_H