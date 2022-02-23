#ifndef __LLIST_H__
#define __LLIST_H__

#include <stdio.h>

#define dbg_printf(fmt, ...) \
        do {                 \
            if (remove_dbg)  \
                printf("T[%ld] %s line:%d %s():" fmt, thread_index, \
                __FILE__, __LINE__, __func__, ##__VA_ARGS__); \
        } while(0)

typedef struct Node Node;
struct Node
{
    int data;
    Node* next;
};

void init_list(Node* list_head);
void insert_node(Node* list_head, int data);
int delete_node(Node* list_head, int num);
void print_list(Node* list_head);

#endif