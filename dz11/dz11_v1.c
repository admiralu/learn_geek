#include "dz11_v1.h"

void print_dir_contents(const char *strdir)
{
    
    DIR *dir;
    struct dirent *entry;
    
    dir = opendir(strdir);
    
    if (dir) {
        while (entry = readdir(dir)) {
            printf("file %s\n", entry->d_name);
                                     }
             }
}
