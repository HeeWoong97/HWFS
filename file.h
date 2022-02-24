#ifndef __FILE_H__
#define __FILE_H__

typedef struct File File;
struct File
{
    const char* name;
    const char* type;
    void* data;
};

#endif