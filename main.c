#include <stdio.h>
#include <string.h>
#include "HWFS.h"

int main(void)
{
    Dir* dir1 = create_directory("dir1");
   
    int data1 = 26;
    File file1 = {"file", "hw's age", "int", &data1};
    create_file(dir1, &file1);

    const char* data2 = "HeeWoong";
    File file2 = {"file", "my_name", "string", data2};
    create_file(dir1, &file2);

    Dir* dir2 = create_directory("dir2");
    dir2->parent_dir = dir1;
    create_file(dir1, dir2);

    const char* data3 = "010-9449-7017";
    File file3 = {"file", "my_number", "string", data3};
    create_file(dir1, &file3);

    Dir* dir3 = create_directory("dir3");
    dir3->parent_dir = dir1;
    create_file(dir1, dir3);

    double data4 = 3.141592;
    File file4 = {"file", "pi", "double", &data4}; 
    create_file(dir1, &file4);
    
    int data5 = 24;
    File file5 = {"file", "jw's age", "int", &data5};
    create_file(dir2, &file5);

    int data6 = 25;
    File file6 = {"file", "hy's age", "int", &data6};
    create_file(dir2, &file6);

    const char* data7 = "010-9372-5095";
    File file7 = {"file", "jw's number", "string", data7};
    create_file(dir2, &file7);

    Dir* cur_dir = dir1;
    while (1) {
        char input[20];
        printf("Enter command: ");
        scanf("%s", input);

        if (!strcmp(input, "ls")) {
            show_files(cur_dir);
        }
        else if (!strcmp(input, "cd")) {
            char next_dir[20];
            printf("Enter next dir: ");
            scanf("%s", next_dir);
            // "dir2"
            cur_dir = dir2;
        }
    }

    return 0;
}