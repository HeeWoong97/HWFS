#include "mkfile.h"    
#include <stdlib.h>
#include <string.h>

void make_normal_file(Dir* dir, char type[], char name[], char file_type[], void* data)
{
    File* file = (File*)malloc(sizeof(File));
    strcpy(file->type, type);
    strcpy(file->name, name);
    strcpy(file->file_type, file_type);
    file->data = data;
    dbg_printf("file %p\n", file);
    create_file(dir, file);
}

Dir* make_file(void)
{
    Dir* dir1 = (Dir*)malloc(sizeof(Dir));
    dir1 = create_directory("dir1");
    dbg_printf("dir1 %p\n", dir1);
   
    int* data1 = (int*)malloc(sizeof(int));
    *data1 = 26;
    make_normal_file(dir1, "file", "hw's age", "int", data1);

    char* data2 = (char*)malloc(sizeof(char) * 30);
    strcpy(data2, "HeeWoong");
    make_normal_file(dir1, "file", "my_name", "string", data2);

    Dir* dir2 = create_directory("dir2");
    dir2->parent_dir = dir1;
    create_file(dir1, dir2);
    dbg_printf("dir2 %p\n", dir2);

    char* data3 = (char*)malloc(sizeof(char) * 30);
    strcpy(data3, "010-9449-7017");
    make_normal_file(dir1, "file", "my_number", "string", data3);

    Dir* dir3 = create_directory("dir3");
    dir3->parent_dir = dir1;
    create_file(dir1, dir3);

    double* data4 = (double*)malloc(sizeof(double));
    *data4 = 3.141592;
    make_normal_file(dir1, "file", "pi", "double", data4);

    int* data5 = (int*)malloc(sizeof(int));
    *data5 = 24;
    make_normal_file(dir2, "file", "jw's age", "int", data5);

    int* data6 = (int*)malloc(sizeof(int));
    *data6 = 25;
    make_normal_file(dir2, "file", "hy's age", "int", data6);

    char* data7 = (char*)malloc(sizeof(char) * 30);
    strcpy(data7, "010-9372-5095");
    make_normal_file(dir2, "file", "jw's number", "string", data7);

    Dir* dir4 = create_directory("dir4");
    dir4->parent_dir = dir3;
    create_file(dir3, dir4);

    return dir1;
}