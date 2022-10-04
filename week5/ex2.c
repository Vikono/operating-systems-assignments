#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define N 4

typedef struct thread
{
    pthread_t thread_id;
    int thread_num;
    char message[256];
} Thread;


void *thread_start(void *thread)
{
    Thread *my_data = (Thread *)thread;
    printf("Thread %i is created\n", my_data->thread_num);

    pthread_exit(0);

    return NULL;
}


int main(int argc, char *argv[])
{
    int n= atoi(argv[1]);
    int i;
    Thread thread[n];
    for (i = 0; i < n; i++)
    {
        thread[i].thread_num = i;
        strcpy(thread[i].message, "Hello from thread ");
        char*temp =(char*)malloc(8);
        sprintf(temp, "%d", i);

        strcpy(thread[i].message, strcat(thread[i].message, temp));
        pthread_create(&(thread[i].thread_id), NULL, thread_start, (void *)(thread + i));
        pthread_join(thread[i].thread_id, NULL);
        printf("%li %s\n", thread[i].thread_id, thread[i].message);

    }
    return 0;
}

