#include "HWFS.h"

int main(void)
{
    Dir* dir1 = create_directory("home");
   
    int data_int1 = 25;
    File file1 = {"my_age", "int", &data_int1};
    const char* data_str2 = "HeeWoong";
    File file2 = {"my_name", "string", data_str2};
    const char* data_str3 = "010-9449-7017";
    File file3 = {"my_number", "string", data_str3};

    create_file(dir1, &file1);
    create_file(dir1, &file2);
    create_file(dir1, &file3);

    show_files(dir1);

    return 0;
}