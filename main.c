#include <stdio.h>
#include "dir.h"

int main(void)
{
    Dir* dir1 = create_directory("home");
    printf("%p\n", dir1);
    printf("list_head(main.c): %p\n", dir1->list_head);
    printf("haha\n");
    create_file(dir1, 1);
    create_file(dir1, 3);
    create_file(dir1, 5);
    create_file(dir1, 7);
    printf("hoho\n");
    show_files(dir1);

    return 0;
}