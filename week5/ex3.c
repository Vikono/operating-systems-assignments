#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int is_prime(int n) {
    if (n <= 1)
        return 0;
    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int primes_count_in_interval(int start, int finish) {
    int ret = 0;
    for (int i = start; i < finish; i++)
        if (is_prime(i) != 0)
            ret++;
    return ret;
}

typedef struct prime_counter_request {
    int start, finish;
} prime_counter_request;

void *prime_counter(void *arg) {
    prime_counter_request *my_data = (prime_counter_request *) arg;
    int left = my_data->start;
    int right = my_data->finish;
    int *p = malloc(sizeof(int));
    *p = primes_count_in_interval(left, right);
    return p;
}

int main(int argc, char *argv[]) {
    int n, n_threads;
    n=atoi(argv[1]);
    n_threads = atoi(argv[2]);
    //scanf("%d %d", &n, &n_threads);
    int segment_size = n / n_threads;

    pthread_t *threads = malloc(n_threads * sizeof(pthread_t));

    prime_counter_request *requests = malloc(n_threads * sizeof(prime_counter_request));

    void **results = malloc(n_threads * sizeof(void *));
    int l = 0;
    int r = segment_size;
    int amount;

    for (int i = 0; i < n_threads; i++) {
        l = segment_size * i;
        r = segment_size * (i+1);
        prime_counter_request temp = {l, r};
        requests[i] = temp;
        pthread_create(&threads[i], NULL, prime_counter, (void *) (requests + i));
    }

    for (int i = 0; i < n_threads; i++) {
        pthread_join(threads[i], &results[i]);
    }

    int total_result = 0;
    for (int i = 0; i < n_threads; i++) {
        total_result += *(int *) results[i];
    }


    free(results);
    printf("%d\n", total_result);

    exit(EXIT_SUCCESS);
}

