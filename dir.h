#ifndef __DIR_H__
#define __DIR_H__

#include "llist.h"

#define MAX_NAME_LEN    10

typedef struct Dir Dir;
struct Dir
{
    Node* list_head;
    Dir* parent_dir;
    Dir* child_dir;

    char dir_name[MAX_NAME_LEN];
    int num_of_child_dir;
};

Dir* create_directory(const char* dir_name);
void create_file(Dir *dir, int data);
void delete_file(Dir *dir, int data);
void show_files(Dir* dir);

#endif