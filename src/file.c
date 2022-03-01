#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "file.h"
#include "dir.h"

bool cmp_int(void* a, void* b)
{
    if (*(int*)a == *(int*)b) {
        return true;
    }
    return false;
}

bool cmp_str(void* a, void* b)
{
    if (!strcmp((const char*)a, (const char*)b)) {
        return true;
    }
    return false;
}

bool cmp_file(File* file1, File* file2)
{
    if (strcmp(file1->file_type, file2->file_type)) {
        printf("Type of two files is different...\n");
        return false;
    }
    if (!strcmp(file1->file_type, "int")) {
        return cmp_int(file1->data, file2->data);
    }
    else if (!strcmp(file1->file_type, "string")) {
        return cmp_str(file1->data, file2->data);
    }
    return false;
}

void print_file(File* file)
{
    printf("%-15s", file->name);
    printf("%-15s", file->file_type);
    if (!strcmp(file->file_type, "int")) {
        printf("%-20d ", *(int*)file->data);
    }
    else if (!strcmp(file->file_type, "string")) {
        printf("%-20s ", (const char*)file->data);
    }
    else if (!strcmp(file->file_type, "double")) {
        printf("%-20lf ", *(double*)file->data);
    }
    printf("\n");
}