//
// Created by aleks on 26.03.25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include <ctype.h>
#include "functions.h"
#include "linked.h"


void trim(char *str) {
    int i;
    int begin = 0;
    int end = strlen(str) - 1;

    while (isspace((unsigned char) str[begin])) {
        begin++;
    }
    while ((end >= begin) && isspace((unsigned char) str[end])) {
        end--;
    }
    for (i = begin; i <= end; i++) {
        str[i-begin] = str[i];
    }

    str[i-begin] = '\0';
}

void task_one(double array[], size_t array_size) {
    srand(time(NULL));
    for (int i = 0; i < array_size; i++) {
        array[i] = 10 + ((double) rand() / (double) RAND_MAX) * (100 - 10);
    }
}

int task_two(char* filename) {
    int counter = 0;
    FILE *file = fopen(filename, "r");
    if (file) {
        char buffer[256];
        while((fgets(buffer, 256, file))!=NULL) {
            char* pch = strtok(buffer, " ");
            while (pch != NULL) {
                trim(pch);
                if (pch[0] == '-') {
                    counter++;
                }
                pch = strtok(NULL, " ");
            }
        }
        fclose(file);
    } else {
        __assert("No file", "functions.c", 26);
    }
    return counter;
}

void task_three(char* filename) {
    FILE* file = fopen(filename, "r");
    node_t* head = init_list(512, "some_value");
    if (file) {
        char buffer[512];
        while (fgets(buffer, 512, file) != NULL) {
            int index = 0;
            char* pch = strtok(buffer, ",");
            while (pch != NULL) {
                trim(pch);
                if (index == 1 && !is_in_list(head, pch)) append_to_list(head, pch);
                index++;
                pch = strtok(NULL, ",\n");
            }
        }
        head = pop_from_begin(head);
        head = pop_from_begin(head);
        fclose(file);
    } else {
        __assert("No file found with this name", "functions.c", 43);
    }
    export_list_to_file(head, "out/output");
}
