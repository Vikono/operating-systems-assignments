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
    int n, id;
    sscanf(argv[1],"%d", &n);
    sscanf(argv[2],"%d", &id);
    printf("Subscriber number %d.\n", id);
    while (strcmp(arr, "exit\n")) {
        printf("<< ");
        int fd = open("/tmp/ex1", O_RDONLY);
        if (fd == -1) {
            return 1;
        }
        // We have opened the fifo
        // for writing from another process
        // so we can read from it
        if (read(fd, arr, 1024) == -1) {
            return 2;
        }
        sleep(n+1);
        //printf("Received %d\n", arr[i]);
        printf("Recieved message: %s\n", arr);
        close(fd);
    }
    return 0;
}

