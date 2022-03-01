#ifndef __FILE_H__
#define __FILE_H__

#include <stdbool.h>

typedef struct File File;
struct File
{
    char type[20];
    char name[20];
    char file_type[20];
    void* data;
};

bool cmp_int(void* a, void* b);
bool cmp_str(void* a, void* b);
bool cmp_file(File* file1, File *file2);
void print_file(File* file);

#endif