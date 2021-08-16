#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <dz11_v1.h>

void print_dir_contents(const char *strdir);

int main(int argc, char **argv)
{
    char path[255] = { 0 };
    printf("enter path directory\n");
    scanf("%s", &path);
    printf("path = %s\n", path);
    print_dir_contents(path);
return 0;
}
