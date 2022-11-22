#include <stdio.h>
#include <dirent.h>

int main(){
   struct dirent *file;
   DIR *dir = opendir("/");
   while ((file = readdir(dir)) != NULL)
  	 printf("%s\n", file->d_name);
   closedir(dir);
   return 0;
}
