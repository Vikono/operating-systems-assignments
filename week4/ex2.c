#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
//#include<signal.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    int u[120], v[120], n, right, left = 0, result;
    FILE *fptr = fopen("file.txt", "w+");
    time_t t;
    srand((unsigned) time(&t));
    printf("Enter a number: ");
    scanf("%d", &n);
    for (int i = 0; i < 120; i++) {
        u[i] = rand() % 100;
        v[i] = rand() % 100;
    }
    right = 120 / n;
    pid_t pid = getpid();
    for (int i = 0; i < n; ++i) {
        right = right + 120 / n * (i == 0 ? 0 : 1);
        left = left + 120 / n * (i == 0 ? 0 : 1);
        result = 0;
        if (getpid() == pid && fork() == 0) {
            break;
        }
    }
    while (left < right && getpid() != pid) {
        result = result + u[left] * v[left];
        left++;
    }
    if (getpid() != pid) {
        fprintf(fptr, "%d\n", result);
        exit(0);
    }
    for (int i = 0; i < n; ++i) {
        wait(NULL);
    }
    fseek(fptr, 0, SEEK_SET);
    int item;
    int answer = 0;
    fscanf(fptr, "%d", &item);
    while (!feof(fptr)) {
        answer += item;
        fscanf(fptr, "%d", &item);
    }

    printf("%d", answer);
    fclose(fptr);
    //}
    return 0;

}

