/*
 * staa.h
 * Copyright (C) 2020 wlz <wlz@kyria>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef STAA_H
#define STAA_H

#define STACK_SIZE 256

typedef enum { false,
               true } bool;

// virtual instruction set
typedef enum {
    nop,
    pop,
    push,
    pushb,
    popb,
    addb,
    add,
    cmp,
    cmpb,
    jmpf,
    call,
    ret
    // todo : more instruction
} opcode;

// function call implementation

// save and restore  every function call
typedef struct {
    int stack[STACK_SIZE];
    int block[STACK_SIZE];
    int ip;
    int sp;
    int spb;
    int index;
} frame;

// save instructions for every define function
typedef struct {
    int program[STACK_SIZE];
} func;

// frame structure
extern frame call_stack[STACK_SIZE];  // array as stack
// functions instructions list
extern func func_list[STACK_SIZE];  // array
// munber of define functions
extern int fun_num;

// virtual machine running status

// currently data stack  => used for calculatoin
extern int stack[STACK_SIZE];  // array as stack

// currently block stack => used for cycle counter
extern int block[STACK_SIZE];  // array as stack

// currently program     => used save the instructions of currently function
extern int program[STACK_SIZE];  // array

// the index of the function list where the currently running function instruction is located
extern int fun_index;
// decide whether to continue
extern bool run_flag;

// pointer
// points to position of the currently running instruction in program[]
extern int ip;
// points the top of currently data  stack (stack[])
extern int sp;
// points the top of currently block stack (block[])
extern int spb;
// points the top of currently function call stack (call_stack[])
extern int spc;

#endif /* !STAA_H */
