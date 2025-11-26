#ifndef VMIO_H
#define VMIO_H

#include "stdio.h"
#include "../stack/stack.h"

extern bool running;

/** Instructions */
extern int ip; // Instruction Pointer
#define ip (regs[IP])

typedef enum {
    PSH,
    POP,
    ADD,
    SET,
    EXT
} Instructions;

/** Functions */
int fetch();

void eval(int instr, Stack *stack);

void run_vm();

#endif // VMIO_H