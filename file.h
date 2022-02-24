#ifndef __FILE_H__
#define __FILE_H__

#include <stdbool.h>

typedef struct File File;
struct File
{
    const char* type;
    const char* name;
    const char* file_type;
    void* data;
};

bool cmp_int(void* a, void* b);
bool cmp_str(void* a, void* b);
bool cmp_file(File* file1, File *file2);
void print_file(File* file);

#endif