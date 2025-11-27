#ifndef REGISTERS_H
#define REGISTERS_H

#include "stdio.h"

/**
 * CPU Registers:
 *  r0–r7            - General-purpose registers
 *  ip, sp           - Instruction & Stack Pointer
 */
enum {
    r0, r1, r2, r3,
    r4, r5, r6, r7,
    ip, sp,
    COUNT
};

extern __int64_t reg[COUNT];

#endif // REGISTERS_H