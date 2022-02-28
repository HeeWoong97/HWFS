#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dir.h"
#include "file.h"
#include "llist.h"

Dir* create_directory(const char* dir_name)
{
    Dir* dir = (Dir*)malloc(sizeof(Dir));

    dir->type = "directory";
    dir->list_head = init_list(dir->list_head);
    dir->parent_dir = NULL;

    strcpy(dir->name, dir_name);
    dbg_printf("strcpy finish\n");
    dir->num_of_child_dir = 0;
    dir->num_of_files = 0;
    dbg_printf("create directory finish\n");

    return dir;
}

void create_file(Dir* dir, void* data)
{
    insert_node(dir->list_head, data);
    dir->num_of_files++;
}

void delete_file(Dir* dir, void* data)
{
    delete_node(dir->list_head, data);
}

void show_files_name(Dir* dir)
{
    Node* cur = dir->list_head->next;

    while (cur != NULL) {
        if (!strcmp((const char*)((File*)cur->data)->type, "file")) {
            printf("%s(file)   ", ((File*)(cur->data))->name);
        }
        else if (!strcmp((const char*)((Dir*)cur->data)->type, "directory")) {
            printf("%s(dir)   ", ((Dir*)cur->data)->name);
        }
        cur = cur->next;
    }
    printf("\n");
}

void show_files_specific(Dir* dir)
{
    Node* cur = dir->list_head->next;

    printf("%-15s%-15s%-15s%-20s%-15s\n", "[Type]", "[Name]", "[File Type]", "[Content]", "[Parent Dir]");
    while (cur != NULL) {
        dbg_printf("show file...\n");
        if (!strcmp((const char*)((File*)cur->data)->type, "file")) {
            printf("%-15s", "File");
            print_file(cur->data);
        }
        else if (!strcmp((const char*)((Dir*)cur->data)->type, "directory")) {
            printf("%-15s", "Directory");
            printf("%-15s", (const char*)((Dir*)cur->data)->name);
            if ((Dir*)((Dir*)cur->data)->parent_dir != NULL) {
                printf("%-35s", " ");
                printf("%-15s", (const char*)((Dir*)((Dir*)cur->data)->parent_dir)->name);
            }
            printf("\n");
        }
        cur = cur->next;
    }
}