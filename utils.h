#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdbool.h>
#include "file.h"

bool cmp_int(void* a, void* b);
void print_int(void* a);
bool cmp_str(void* a, void* b);
void print_str(void* a);
bool cmp_file(File* file1, File *file2);
void print_file(File* file);

#endif