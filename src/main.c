#include <stdio.h>
#include <string.h>
#include "HWFS.h"
#include "mkfile.h"

int main(void)
{
    Dir* cur_dir = make_file();
    
    dbg_printf("\n");
    dbg_printf("cur_dir %p\n", cur_dir);
    dbg_printf("cur_dir->list_head->next %p\n", cur_dir->list_head->next);
    dbg_printf("cur_dir->list_head->next->data %p\n", cur_dir->list_head->next->data);
    dbg_printf("cur_dir->list_head->next->next->data %p\n", cur_dir->list_head->next->next->data);
    dbg_printf("cur_dir->list_head->next->next->next->data %p\n", cur_dir->list_head->next->next->next->data);
    dbg_printf("cur_dir->list_head->next->next->next->next->data %p\n", cur_dir->list_head->next->next->next->next->data);
    dbg_printf("cur_dir->list_head->next->next->next->next->next %p\n", cur_dir->list_head->next->next->next->next->next);
    dbg_printf("\n");

    while (true) {
        char input[20];
        dbg_printf("cur_dir->name %p\n", cur_dir->name);
        printf("[%s]$ ", cur_dir->name);
        scanf("%s", input);
        if (!strcmp(input, "ls")) {
            show_files_name(cur_dir);
        }
        else if (!strcmp(input, "ll")) {
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
                printf("/%s", dirs[i]);
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