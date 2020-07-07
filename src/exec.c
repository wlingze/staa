/*
 * Copyright (C) 2020 wlz <wlz@kyria>
 *
 * Distributed under terms of the MIT license.
 */

// exec instruction

#include "exec.h"

#include <stdio.h>
#include <stdlib.h>

#include "make_frame.h"
#include "staa.h"

// get next instruction to run
int _Fetch() { return program[ip]; }

// run instruction
void _Eval(int opcode) {
    switch (opcode) {
        int var;
        case nop:
            printf("!-= nop =-!\n");
            run_flag = false;
            break;
        case push:
            stack[sp++] = program[++ip];
            printf("push %d => stack[%d]\n", stack[sp], sp);
            break;
        case pushb:
            block[spb++] = program[++ip];
            printf("push %d => block[%d]\n", block[spb], spb);
            break;
        case pop:
            printf("pop  %d <= stack\n", stack[sp - 1]);
            sp -= 1;
            break;
        case add:
            stack[sp - 2] += stack[sp - 1];
            printf("  add   => %d\n", stack[sp - 2]);
            sp -= 1;
            break;
        case addb:
            block[spb - 2] += block[spb - 1];
            printf(" addb  => %d\n", block[spb - 2]);
            spb -= 1;
            break;
        case cmpb:
            block[spb++] = block[spb - 1] == program[++ip];
            printf("cmpb %d==%d\n", block[spb - 1], program[ip]);
            break;
        case cmp:
            block[spb++] = stack[sp - 1] == program[++ip];
            printf("cmp  %d==%d\n", stack[sp - 1], program[ip]);
            break;
        case jmpf:
            if (block[--spb] == 0) {
                var = program[++ip];
                ip += var;
                printf("jmp! \n");
            }
            printf("no jmp\n");
            break;
        case ret:
            DealFrame(0, 1);
            printf("[v] return \n");
            break;
        case call:
            printf("[^] call %d\n", program[ip + 1]);
            DealFrame(1, program[++ip]);
            break;
    }
}

void Exec() {
    // initialization function call stack
    InitFrame();

    // start looping the virtual machine
    while (run_flag) {
        _Eval(_Fetch());
        ip += 1;
    }
}
