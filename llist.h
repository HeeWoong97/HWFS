#ifndef __LLIST_H__
#define __LLIST_H__

#include <stdio.h>
#include <stdbool.h>

#define dbg_printf(fmt, ...) \
    printf("%s line:%d %s():" fmt, __FILE__, __LINE__, __func__, ##__VA_ARGS__);

typedef struct Node Node;
struct Node
{
    void* data;
    Node* next;
};

Node* init_list(Node* list_head);
void insert_node(Node* list_head, void* data);
void delete_node(Node* list_head, void* data, bool cmp(void*, void*));
void print_list(Node* list_head);

#endif