#include<stdio.h>
#include<stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

int main() {
    int n, cur_t, ft, tat, wt;
    int *n_pr;
    int *at;
    int *bt;
    double tat_av;
    double wt_av;
    scanf("%d", &n);
    n_pr = malloc(n * sizeof(int *));
    at = malloc(n * sizeof(int *));
    bt = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        scanf("%d", at + i);
        n_pr[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", bt + i);
        
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (at[j] > at[j + 1]) {
                swap(at + j, at + j + 1);
                swap(bt + j, bt + j + 1);
                swap(n_pr + j, n_pr + j + 1);
            } else if (at[j] == at[j + 1]) {
                if (bt[j] > bt[j + 1]) {
                    swap(bt + j, bt + j + 1);
                    swap(n_pr + j, n_pr + j + 1);
                }
            }

        }
    }
    cur_t = at[0];
    for (int i = 0; i < n; ++i) {
        if (cur_t > at[i])
            ft = cur_t + bt[i];
        else
            ft = at[i] + bt[i];
        tat = ft - at[i];
        tat_av += tat;
        wt = tat - bt[i];
        wt_av += wt;
        cur_t = ft;
        printf("Number of process: %d, Arriving time: %d, Burst time: %d, Completion time: %d, Turn around time: %d, Waiting time: %d\n\n",
               n_pr[i], at[i], bt[i], ft, tat, wt);

    }

    printf("Average Turn Around time: %f\n", tat_av / n);
    printf("Average Waiting time: %f\n", wt_av / n);

    return 0;
}
