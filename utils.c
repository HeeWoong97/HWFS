#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "file.h"

bool cmp_int(void* a, void* b)
{
    if (*(int*)a == *(int*)b) {
        return true;
    }
    return false;
}

void print_int(void* a)
{
    printf("%d ", *(int*)a);
}

bool cmp_str(void* a, void* b)
{
    if (!strcmp((const char*)a, (const char*)b)) {
        return true;
    }
    return false;
}

void print_str(void* a)
{
    printf("%s ", (const char*)a);
}

bool cmp_file(File* file1, File* file2)
{
    if (strcmp(file1->type, file2->type)) {
        printf("Type of two files is different...\n");
        return false;
    }
    if (!strcmp(file1->type, "int")) {
        return cmp_int(file1->data, file2->data);
    }
    else if (!strcmp(file1->type, "string")) {
        return cmp_str(file1->data, file2->data);
    }
    return false;
}

void print_file(File* file)
{
    printf("file name: %s, ", file->name);
    printf("file type: %s, ", file->type);
    if (!strcmp(file->type, "int")) {
        print_int(file->data);
    }
    else if (!strcmp(file->type, "string")) {
        print_str(file->data);
    }
    printf("\n");
}