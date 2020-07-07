/*
 * staa.c
 * main file to staa
 * Copyright (C) 2020 wlz <wlz@kyria>
 *
 * Distributed under terms of the MIT license.
 */

#include "staa.h"

#include <stdio.h>

#include "exec.h"
#include "make_func.h"


// define the variables needed for operation 

frame call_stack[STACK_SIZE] = {0};
func func_list[STACK_SIZE]   = {0};
int stack[STACK_SIZE]        = {0};
int block[STACK_SIZE]        = {0};
int program[STACK_SIZE]      = {0};

bool run_flag = true;
int fun_index = 0;
int fun_num   = 0;
int ip        = 0;
int sp        = 0;
int spb       = 0;
int spc       = 0;
int var       = 0;

// function main 
int main(int argc, char *argv[]) {
    int i = 0;
    if (argc < 2) {
        /*
         * todo :
         *      Enter the interactive interface to run.
         *      
         *      : like python or ipython.
         *
         */
        printf("!-=error! no file input\n");
        return 0;
    }
    for (i = 1; i < argc; i++) {
        // process the imported files
        if (DoFile(argv[i]) == 0) {
            return -1;
        }
        printf("[#] -=> exec <=-\n");
        Exec();
        printf("[#] -=> over <=-\n");
    }
    return 0;
}
