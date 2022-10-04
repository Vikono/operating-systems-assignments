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
        if (read(fd, arr, 1024) == -1) {
            return 2;
        }
        sleep(n+1);
        printf("A message from publisher: %s\n", arr);
        close(fd);
    }
    return 0;
}
