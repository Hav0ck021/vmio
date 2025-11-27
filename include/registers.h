#ifndef REGISTERS_H
#define REGISTERS_H

#include "stdio.h"

/**
 * CPU Registers:
 *  ax, bx, cx, dx   - Accumulator, Base, Counter, Data
 *  si, di           - Source & Destination Index
 *  ip, sp, bp       - Instruction, Stack & Base Pointer
 *  cs, ds, ss       - Code, Data & Stack Segment
 *  fl               - Flags
 *  r0–r7            - General-purpose registers
 */
enum {
    ax, bx, cx, dx,
    si, di,
    ip, sp, bp,
    cs, ds, ss,
    fl,
    r0, r1, r2, r3,
    r4, r5, r6, r7,
    COUNT
};

extern __int64_t reg[COUNT];

/** Functions */

#endif // REGISTERS_H

// Future study to implementation
/*
    typedef uint8_t byte;
    
    typedef union {
        uint16_t value;
        struct {
            byte lsb;
            byte msb;
        };
    } Reg16;
*/
