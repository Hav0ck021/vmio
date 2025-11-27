#ifndef VMIO_H
#define VMIO_H

#include "stdio.h"
#include "stack.h"

extern bool running;

/** Instructions **/
typedef enum {
    push,        // push 1 byte in stack
    pop,         // pop 1 byte from stack
    add,         // add last 2 bytes in stack
    mov,         // move a byte to another base
    set,         // set a byte in a register
    cmp,         // compare 2 bytes
    jmp,         // jump to memory address
    call,        // push the memory address to stack
    ret,         // return memory address
} Instructions;

/** Functions **/
int fetch(int idx);
void eval(int instr, Stack *stack);
void run_vm();

#endif // VMIO_H