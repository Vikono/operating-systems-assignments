#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>
#include <sys/wait.h>
int main() {
    int fd[2];
    //char she[10]=""
    // fd[0] - read end
    // fd[1] - write end
    if (pipe(fd) == -1) {
        printf("Error");
        return 1;
    };
    //system("sh ex1.sh");
    int id = getpid();
    fork();
    if (id != getpid()) {
        close(fd[0]);
        while (1) {
            //close(fd[0]);
            char arr[1024];
            fgets(arr, 1024, stdin);
            write(fd[1], arr, 1024);
            //close(fd[1]);
        }
        //kill(getpid(), 0);
    } else {
        close(fd[1]);
        while (1) {
            //close(fd[1]);
            char arr[1024];
            read(fd[0], arr, 1024);
            printf("Got from child process: %s\n", arr);
            //sleep(2);
            //close(fd[0]);
            //wait(NULL);
        }
        /*else
            kill(getpid(), 0);
*/
    }
// Important: Don't forget error checking
    return 0;
}

