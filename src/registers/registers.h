#ifndef REGISTER_H
#define REGISTER_H

#include "stdio.h"

/** Registers */
typedef enum {
    RXA, RXB, RXC, RXD,
    RXE, RXF, RXG, RXH,
    IP, SP,
    COUNT
} Registers;

extern Registers regs[COUNT];

#endif // REGISTER_H
