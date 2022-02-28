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

    Dir* dir4 = create_directory("dir4");
    dir4->parent_dir = dir3;
    create_file(dir3, dir4);

    Dir* cur_dir = dir1;
    while (true) {
        char input[20];
        printf("[%s]$ ", cur_dir->name);
        // scanf("%s", input);
        fgets(input, 20, stdin);
        input[strlen(input) - 1] = '\0';
        if (!strcmp(input, "ls")) {
            show_files_name(cur_dir);
        }
        else if (!strcmp(input, "ls -al")) {
            show_files_specific(cur_dir);
        }
        else if (!strcmp(input, "cd")) {
            char next_dir[20];
            scanf("%s", next_dir);
            if (!strcmp(next_dir, "../")) {
                Dir* cur_pos = cur_dir->parent_dir;
                if (cur_pos == NULL) {
                    printf("Wrong parent directory name...\n\n");
                    continue;
                }
                cur_dir = cur_pos;
                printf("\n");
                continue;
            }
            Node* cur = cur_dir->list_head->next;
            while (cur != NULL) {
                if (!strcmp((const char*)((Dir*)cur->data)->type, "directory")
                    && !strcmp((const char*)((Dir*)cur->data)->name, next_dir)) {
                    cur_dir = (Dir*)cur->data;
                    break;
                }
                cur = cur->next;
                if (cur == NULL) {
                    printf("Can't find directory name \"%s\"...\n", next_dir);
                }
            }
        }
        else if (!strcmp(input, "pwd")) {
            char dirs[10][100];
            Dir* cur_pos = cur_dir;
            int dept = 0;
            while (true) {
                strcpy(dirs[dept], cur_pos->name);
                cur_pos = cur_pos->parent_dir;
                if (cur_pos == NULL) {
                    break;
                }
                dept++;
            }
            for (int i = dept; i >= 0; i--) {
                printf("%s/", dirs[i]);
            }
            printf("\n");
        }
        else if (!strcmp(input, "exit")) {
            printf("exit\n");
            break;
        }
        else {
            printf("Wrong command...\n");
        }
        printf("\n");
    }

    return 0;
}