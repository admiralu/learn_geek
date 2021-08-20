#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

void dirout(DIR *cdir, char *path);

int main (int argc, char **argv)
{
DIR * dir;
if (argc < 2) { //проверка на кол-во введенных параметров
fprintf (stderr, "Too few arguments\n");
return 1;
}
dir = opendir (argv[1]); //открытие каталога
if (errno==ENOTDIR){
perror("opendir");
return 1;
}
dirout(dir,argv[1]); //Выводит содержимое каталога указанного в argv[1] и всех его подкаталогов
closedir (dir);
return 0;
}

void dirout(DIR *cdir, char *path)
{
DIR *hdir;
//char var[255] = {0}; //Заносится путь подкаталога
struct dirent *entry;
//int flag=0; // Используется для определения был ли открыт каталог, и дальнейшего его закрытия
while ((entry = readdir (cdir)) != NULL)
{
if ((hdir=opendir(entry->d_name))!= NULL && (strcmp(".", entry->d_name)) != 0 && (strcmp("..", entry->d_name)) != 0)
{
printf("dir %s\n", entry->d_name);
dirout(hdir,entry->d_name);
closedir (hdir);
//return 1;
}
else
//var == (entry->d_name);
//hdir = opendir(entry->d_name);
//if (errno == ENOTDIR)
//sprintf(var,"%s%s",path,entry->d_name); //присваивает переменной путь подкаталога для дальнейшего его использования в рекурсии
printf("file %s\n", entry->d_name);
//hdir=opendir(var); // Пытаемся открыть как каталог элемент на который указывает entry
//if (errno == ENOTDIR) //если возникает ошибка (элемент не каталог),
//printf ("%s\n", entry->d_name); //то он выводится,
//else{
//dirout(hdir,var); //если каталог, повторяем действия рекурсивно.
//flag=1;
//}
//}
//if (flag==1)
//closedir(hdir);
}
}
