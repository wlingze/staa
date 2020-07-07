/*
 * Copyright (C) 2020 wlz <wlz@kyria>
 *
 * Distributed under terms of the MIT license.
 */

#include "other.h"

#include <stdio.h>

void CpArr(int *a, int *b) {
    int i = 0;
    do {
        b[i] = a[i];
        i++;
    } while (a[i]);
    b[i] = 0;
}
