//
// Created by aleks on 31.03.25.
//
#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

#include <stdbool.h>
#include <string.h>

node_t* init_list(int bytes, char* value) {
    node_t* head = NULL;
    head = (node_t*) malloc(sizeof(char)*bytes);
    head->value = value;
    head->next = NULL;
    head->prev = NULL;
    return head;
}

void append_to_list(node_t* head, char* value) {
    node_t* next = NULL;
    next = (node_t*) malloc(sizeof(value));
    next->value = malloc(strlen(value) + 1);
    strcpy(next->value, value);
    next->next = NULL;
    while (head->next != NULL) {
        head = head->next;
    }
    head->next = next;
    next->prev = head;
}

void pop_from_end(node_t* head) {
    while (head->next != NULL) {
        head = head->next;
    }
    node_t* prev = head->prev;
    free(head);
    prev->next = NULL;
}

node_t* pop_from_begin(node_t* head) {
    node_t* next = head->next;
    next->prev = NULL;
    free(head);
    return next;
}

void print_list(const node_t* head) {
    while (head->next != NULL) {
        printf("%s\n", head->value);
        head = head->next;
    }
    printf("%s\n", head->value);
}

bool is_in_list(const node_t* head, const char* value) {
    while (head->next != NULL) {
        if (strcmp(head->value, value) == 0) {
            return true;
        }
        head = head->next;
    }
    return strcmp(head->value, value) == 0 ? true: false;
}

int list_length(node_t* head) {
    int counter = 0;
    while (head->next != NULL) {
        counter++;
        head = head->next;
    }
    return counter;
}

void export_list_to_file(node_t* head, char* filename) {
    FILE *file = fopen(filename, "w");
    while (head->next != NULL) {
        fputs(head->value, file);
        fputs("\n", file);
        head = head->next;
    }
    fputs(head->value, file);
    fclose(file);
}