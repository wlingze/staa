/*
 * Copyright (C) 2020 wlz <wlz@kyria>
 *
 * Distributed under terms of the MIT license.
 */
#include "make_frame.h"

#include <stdio.h>

#include "other.h"
#include "staa.h"

void _UpdataFrame(int id) {
    fun_index = id > 0 ? id : call_stack[spc].index;
    ip        = call_stack[spc].ip;
    sp        = call_stack[spc].sp;
    spb       = call_stack[spc].spb;
    CpArr(call_stack[spc].stack, stack);
    CpArr(call_stack[spc].block, block);
    CpArr(func_list[fun_index].program, program);
}

void _SaveFrame() {
    call_stack[spc].ip    = ip;
    call_stack[spc].sp    = sp;
    call_stack[spc].spb   = spb;
    call_stack[spc].index = fun_index;
    CpArr(stack, call_stack[spc].stack);
    CpArr(block, call_stack[spc].block);
}

void DealFrame(int deal_flag, int var) {
    if (deal_flag) {
        int id = var;
        _SaveFrame();
        spc += 1;
        _UpdataFrame(id);
        ip -= 1;
    } else {
        spc -= 1;
        _UpdataFrame(-1);
        if (spc == -1) {
            run_flag = false;
        }
    }
}

void InitFrame() {
    spc = 0;
    _UpdataFrame(0);
    run_flag  = true;
    fun_index = 0;
    ip        = 0;
    sp        = 0;
    spb       = 0;
    spc       = 0;
}
