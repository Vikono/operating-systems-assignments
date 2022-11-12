#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

	
int main() {
	DIR *dirp = opendir("tmp");
	struct dirent *dp=readdir(dirp);	
	struct stat sd;
	while (dp != NULL){
		if (dp->d_name[0] != '.') {
			char file_path[32];
			char sys_command[64];
			sprintf(file_path,"./tmp/%s",dp->d_name);
			stat(file_path,&sd);
			if (sd.st_nlink >= 2) {
				sprintf(sys_command, "echo %s -- ",dp->d_name);
				system(sys_command);
				sprintf(sys_command, "find -inum %lu", sd.st_ino);
				system(sys_command);
			}
		}
		sleep(1);
		dp=readdir(dirp);
	}
}
