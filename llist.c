#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;
struct Node
{
    int data;
    Node* next;
};

void init_list(Node* list_head)
{
    list_head = (Node*)malloc(sizeof(Node));
    list_head->next = NULL;
    printf("list_head: %p\n", list_head);
}

void insert_node(Node* list_head, int data)
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

int delete_node(Node* list_head, int num)
{
    Node* cur = list_head;
    while (1) {
        if (cur->next == NULL) {
            return -1;
        }
        if (cur->next->data == num) {
            break;
        }
        cur = cur->next;
    }
    Node* target = cur->next;
    cur->next = target->next;
    free(target);
    return num;
}

void print_list(Node* list_head)
{
    Node* cur = list_head->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}