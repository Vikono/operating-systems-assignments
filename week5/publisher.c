#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>
int main(int argc, char *argv[]) {
    char arr[1024];
    int n;
    sscanf(argv[1],"%d", &n);
    while (strcmp(arr, "exit\n")) {
        mkfifo("/tmp/ex1", 0666);
        printf(">> ");
        fgets(arr, 1024, stdin);
        int fd = open("/tmp/ex1", O_WRONLY);
        if (fd == -1) {
            return 1;
        }
        for(int i=0 ;i <n; ++i){
        if (write(fd, arr, 1024) == -1) {
            return 2;
        }
        sleep(1);
        }
        close(fd);
    }
    return 0;
}

