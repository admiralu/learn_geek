#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

extern char *optarg;
extern int optind, opterr, optopt;

#define DEBUG_PRINT(X) \
    printf("%s\n", X); \
    printf("FUNC %s ", __func__); \
    printf("LINE %d ", __LINE__); \
    printf("FILE %s ", __FILE__); \
    printf("DATE %s ", __DATE__); \
    printf("TIME %s\n", __TIME__); \

void help(const char *appname);
void print_type(struct stat *st, int sch_dir);
void print_dir_contents(const char *strdir, bool all, int sch_dir);

int main(int argc, char **argv)
{

#ifdef DEBUG
    DEBUG_PRINT("Start of program");
#endif

    int ret;
    bool print_all = false;
    char *dir;
    int sch_dir = 0;

    if (argc == 1) {
        help(argv[0]);
        return 0;
    }

    while ((ret = getopt(argc, argv, "had:")) != -1) {
        switch(ret) {
            /* Print help */
            case 'h' : {
                help(argv[0]);
                return 0;
            }
            /* Print all contents(including .. and .) */
            case 'a' : {
                print_all = true;
                break;
            }
            /* Specify directory to open */
            case 'd' : {
                dir = optarg;
                break;
            }
        }
    }

    print_dir_contents(dir, print_all, sch_dir);

#ifdef DEBUG
    DEBUG_PRINT("END of program");
#endif
}


void help(const char *appname)
{
    printf("usage: %s [path]\n", appname);
}



void print_type(struct stat *st, int sch_dir)
{
    switch (st->st_mode & S_IFMT) {
       case S_IFBLK:  printf("block device ");            break;
       case S_IFCHR:  printf("character device ");        break;
       case S_IFDIR:  printf("directory    ");
       sch_dir = 1;
                   break;
       case S_IFIFO:  printf("FIFO/pipe ");               break;
       case S_IFLNK:  printf("symlink ");                 break;
       case S_IFREG:  printf("regular file ");            break;
       case S_IFSOCK: printf("socket ");                  break;
       default:       printf("unknown? ");                break;
    }
}

void print_dir_contents(const char *strdir, bool all, int sch_dir)
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    char *full_name;

    full_name = (char*)malloc(255);

    dir = opendir(strdir);

    if (dir != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] == '.' && !all) {
                continue;
            }
            memset(full_name, 0, 255);
            sprintf(full_name, "%s/%s", strdir, entry->d_name);
            full_name[254] = '\0';
            if (stat(full_name, &file_info) == 0) {
                print_type(&file_info, sch_dir);
                printf("sz %10ld ", file_info.st_size);
            }
            printf(" %s\n", full_name);
            if (sch_dir = 1)
              {
                printf("    /n");
                strdir=full_name;
                return print_dir_contents(const char *strdir, bool all, int sch_dir);
                sch_dir =0;
               }
        }
        closedir(dir);
    }

    free(full_name);
}
