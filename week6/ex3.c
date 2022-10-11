#include<stdio.h>
#include<stdlib.h>

void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int remm(int *ost, int n){
    int rem=0;
    for (int i = 0; i < n; ++i) {
        rem+=ost[i];
    }
    return rem;
}
int main() {
    int n, cur_t, counter=0, q, c_terminated=0;
    int *n_pr;
    int *at;
    int *bt;
    int *ft;
    int *tat;
    int *wt;
    int *ost;
    double tat_av;
    double wt_av;
    scanf("%d", &n);
    scanf("%d", &q);
    n_pr = malloc(n * sizeof(int *));
    at = malloc(n * sizeof(int *));
    ft = malloc(n * sizeof(int *));
    tat = malloc(n * sizeof(int *));
    wt = malloc(n * sizeof(int *));
    bt = malloc(n * sizeof(int *));
    ost = malloc(n * sizeof(int *));
    for (int i = 0; i < n; ++i) {
        scanf("%d", at + i);
        n_pr[i] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", bt + i);
        ost[i]=bt[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (at[j] > at[j + 1]) {
                swap(at + j, at + j + 1);
                swap(bt + j, bt + j + 1);
                swap(n_pr + j, n_pr + j + 1);
                swap(ost + j, ost + j + 1);
            }/* else if (at[j] == at[j + 1]) {
                if (bt[j] > bt[j + 1]) {
                    swap(bt + j, bt + j + 1);
                    swap(n_pr + j, n_pr + j + 1);
                }
            }*/

        }
    }
    cur_t = at[0];
    int i=0;
    while(c_terminated!=n){
        if(ost[i]<=q && ost[i]>0){
            cur_t+=ost[i];
            int k=ost[i];
            ost[i]=0;
            counter=1;}
        else if(ost[i]>0){
            ost[i]-=q;
            cur_t+=q;
        }
        if(counter==1){
            c_terminated++;
            tat[i]=cur_t-at[i];
            ft[i]=cur_t;
            tat_av+=tat[i];
            wt[i]= tat[i]-bt[i];
            wt_av+=wt[i];
            counter=0;
        }
        if(i==n-1)
            i=0;
        else if(at[i+1]<=cur_t)
            i++;
        else {
            if(at[i+1]>cur_t && remm(ost, i+1)==0)
                cur_t=at[i+1];
            i = 0;

        }


    }
    for (int j = 0; j < n; ++j) {
        printf("Number of process: %d, Arriving time: %d, Burst time: %d, Completion time: %d, Turn around time: %d, Waiting time: %d\n\n", n_pr[j], at[j], bt[j], ft[j], tat[j], wt[j]);
    }
    printf("Average Turn Around time: %f\n", tat_av / n);
    printf("Average Waiting time: %f\n", wt_av / n);

    return 0;
}
