#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "llist.h"
#include "file.h"

Node* init_list(Node* list_head)
{
    list_head = (Node*)malloc(sizeof(Node));
    list_head->next = NULL;
    dbg_printf("list_head: %p\n", list_head);

    return list_head;
}

void insert_node(Node* list_head, void* data)
{
    Node* cur = list_head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    Node* new = (Node*)malloc(sizeof(Node));
    new->data = data;
    cur->next = new;
    new->next = NULL;
}

void delete_node(Node* list_head, void* data)
{
    Node* cur = list_head;
    while (1) {
        if (cur->next == NULL) {
            return;
        }
        if (cmp_file(cur->next->data, data)) {
            break;
        }
        cur = cur->next;
    }
    Node* target = cur->next;
    cur->next = target->next;
    free(target);
}