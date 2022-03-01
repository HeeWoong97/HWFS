#ifndef __DIR_H__
#define __DIR_H__

#include "llist.h"

typedef struct Dir Dir;
struct Dir
{
    char type[20];
    char name[100];
    int num_of_child_dir;
    int num_of_files;

    Node* list_head;
    Dir* parent_dir;
};

Dir* create_directory(const char* dir_name);
void create_file(Dir *dir, void* data);
void delete_file(Dir *dir, void* data);
void print_directory(Dir* dir);
void show_files_name(Dir* dir);
void show_files_specific(Dir* dir);

#endif