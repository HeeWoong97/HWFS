#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dir.h"

Dir* create_directory(const char* dir_name)
{
    Dir* dir = (Dir*)malloc(sizeof(Dir));

    dir->list_head = init_list(dir->list_head);
    dir->parent_dir = NULL;
    dir->child_dir = NULL;

    if (strlen(dir_name) < MAX_NAME_LEN)
        strcpy(dir->dir_name, dir_name);
    else 
        printf("Directory name is too long...\n");
    dir->num_of_child_dir = 0;

    return dir;
}

void create_file(Dir* dir, void* data)
{
    insert_node(dir->list_head, data);
}

void delete_file(Dir* dir, void* data)
{
    delete_node(dir->list_head, data);
}

void show_files(Dir* dir)
{
    print_list(dir->list_head);
}