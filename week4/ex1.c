#include<unistd.h>
#include <stdio.h>
#include<time.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    clock_t tmain = clock();

    pid_t First_child, Second_child;

    First_child = fork();
    clock_t t1 = clock();

    if (First_child == 0) {

        printf("First child process-> pid: %d, ppid: %d, time: %f ms\n", getpid(), getppid(), (float)(clock()-t1)/CLOCKS_PER_SEC*1000);
        exit(0);
    } else {
        Second_child = fork();
        clock_t t2 = clock();

        if (Second_child == 0) {
            //clock_t end2=clock();
            printf("Second child process-> pid: %d, ppid: %d, time: %f ms\n", getpid(), getppid(), (float)(clock()-t2)/CLOCKS_PER_SEC*1000);
            exit(0);
        } else {
            for(int i=0 ;i <2; i++) {
                wait(NULL);
            }
            printf("Main process-> pid: %d, ppid: %d, time: %f ms\n", getpid(), getppid(), (float)(clock()-tmain)/CLOCKS_PER_SEC*1000);
            exit(0);

        }
    }
}

