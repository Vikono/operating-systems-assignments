#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/wait.h>
int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        printf("Error");
        return 1;
    };
    int id = getpid();
    fork();
    if (id != getpid()) {
        close(fd[0]);
        while (1) {
            char arr[1024];
            fgets(arr, 1024, stdin);
            write(fd[1], arr, 1024);
            
        }
    } else {
        close(fd[1]);
        while (1) {
            char arr[1024];
            read(fd[0], arr, 1024);
            printf("Recieved from the publisher: %s\n", arr);
            
        }
        
    }
    return 0;
}

