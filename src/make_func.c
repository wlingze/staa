/*
 * Copyright (C) 2020 wlz <wlz@kyria>
 *
 * Distributed under terms of the MIT license.
 */

#include "make_func.h"

#include <stdio.h>

#include "other.h"
#include "staa.h"

int DoFile(char *filename) {
    fun_num      = 0;
    int file_fun = 1;
    FILE *file   = fopen(filename, "r");
    if (!file) {
        printf("[!] error: could not read file `%s`\n", filename);
        return 0;
    }
    printf("[+] open file `%s`\n", filename);
    int i = 0;

    do {
        int num      = 0;
        int arr[256] = {0};
        while (fscanf(file, "%d", &num) > 0) {
            if (num == -1) {
                file_fun += 1;
                i = 0;
            } else if (num == -2) {
                file_fun -= 1;
                break;
            } else {
                arr[i] = num;
                printf("[*] read file %d\n", arr[i]);
                i++;
            }
        }
        CpArr(arr, func_list[fun_num].program);
        fun_num += 1;
    } while (file_fun);
    fclose(file);

    return 1;
}
