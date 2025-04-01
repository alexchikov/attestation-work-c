//
// Created by aleks on 31.03.25.
//

#ifndef LINKED_H
#define LINKED_H
#include <stdbool.h>

typedef struct node {
    char* value;
    struct node* next;
    struct node* prev;
} node_t;

node_t* init_list(int bytes, char* value);
void append_to_list(node_t* head, char* value);
void print_list(const node_t* head);
void pop_from_end(node_t* head);
node_t* pop_from_begin(node_t* head);
bool is_in_list(const node_t* head, const char* value);
int list_length(node_t* head);
void export_list_to_file(node_t* head, char* filename);

#endif //LINKED_H
