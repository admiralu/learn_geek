#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>


extern char *optarg;
extern int optind, opterr, optopt;

void print_dir_contents(const char *strdir);

int main(int argc, char **argv)
{
    const char *opts = "d:h::";
    char path[255] = { 0 };
    int ret;
    
    
    while ((ret = getopt(argc, argv, opts)) != -1)
     {
          switch(ret)
          {
          case 'd' :
           {
           printf("d=%s\n", optarg);
           print_dir_contents(optarg);
           break;
           }
           case 'h' :
            {
            printf("enter path\n");
            break;
            }
          }
      }
     return 0;
}



void print_dir_contents(const char *strdir)
  {
    
    DIR *dir;
    DIR *dir_v;
    struct dirent *entry;
    //struct stat file_info;

    dir = opendir(strdir);
    
    if (dir) 
         {
           while (entry = readdir(dir)) 
              {
               if ((dir_v=opendir(entry->d_name))!= NULL && (strcmp(".", entry->d_name)) != 0 && (strcmp("..", entry->d_name)) != 0)
                  {
                    printf("dir %s\n", entry->d_name);
                    print_dir_contents(entry->d_name);
                    closedir (dir_v);
                  }
              else
                printf("file %s\n", entry->d_name);      
              }
          }
     closedir(dir);
   }
