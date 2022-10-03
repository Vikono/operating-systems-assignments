#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>

#define N 5

typedef struct thread
{
    pthread_t thread_id;
    int thread_num;
    char message[256];
} Thread;


void *thread_start(void *thread)
{
    Thread *my_data = (Thread *)thread;
    int order = my_data->thread_num;
    printf("Thread %i is created\n", order);
    printf("%li %s\n", my_data->thread_id, my_data->message);
    pthread_exit(0);
    // there is no guarantee that prints will be in order
    //   we will use its initial thread->num ,cause it differs for each thread
    // plus you will see how threads will behave
    //int order = my_data->thread_num;
    // printf("%i) before num T: %i\n", order, my_data->thread_num);
    // printf("%i) after assignment num T: %i\n", order, my_data->thread_num);

    return NULL;
}

// char *my_itoa(int num, char *str)
// {
//         if(str == NULL)
//         {
//                 return NULL;
//         }
//         sprintf(str, "%d", num);
//         return str;
// }


int main(int argc, char *argv[])
{
    int i;
    int * i_ad = &i;
    Thread thread[N];
    for (i = 0; i < N; i++)
    {
        thread[i].thread_num = i;
        strcpy(thread[i].message, "Hello from thread ");
        char*temp =(char*)malloc(8);
        sprintf(temp, "%d", i);
    

        strcpy(thread[i].message, strcat(thread[i].message, temp));
        pthread_create(&(thread[i].thread_id), NULL, thread_start, (void *)(thread + i));
        pthread_join(thread[i].thread_id, NULL);
        
    }
    return 0;
}

