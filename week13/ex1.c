#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int Num_of_lines = -2;
int resourses = 0;

int resourse_menager(int n, int m, bool *processes, int *A, int **Cur_Matrix, int **Rec_Matrix) {
    for (int i = 0; i < n; ++i) {
        if (processes[i]) {
            continue;
        }
        bool IsCurrent = true;
        for (int j = 0; j < m; ++j) {
            if (Rec_Matrix[i][j] > A[j]) {
                IsCurrent = false;
                break;
            }
        }
        if (IsCurrent) {
            for (int j = 0; j < m; ++j) {
                A[j] = A[j] + Cur_Matrix[i][j];
                Cur_Matrix[i][j] = 0;
                Rec_Matrix[i][j] = 0;
            }
            processes[i] = true;
            return i;
        }

    }
    return -1;
}


char **split(char *str, char *delimiter) {
    int len = strlen(str);
    char *strCopy = (char *) malloc(
            (len + 1) * sizeof(char));
    strcpy(strCopy, str);
    for (int i = 0; strCopy[i] != '\0'; i++) {
        for (int j = 0; delimiter[j] != '\0'; j++) {
            if (strCopy[i] == delimiter[j]) {
                strCopy[i] = '\0';
                //Num_of_lines ++;
                break;
            }
        }
    }
    char **res = (char **) malloc((len + 2) * sizeof(char *));
    len++;
    int resI = 0;
    for (int i = 0; i < len; i++) {
        res[resI++] = strCopy + i;
        while (strCopy[i] != '\0') {
            i++;
        }
    }
    if (Num_of_lines == -2)
        Num_of_lines = resI - 1;
    else
        resourses = resI;
    res[resI] = NULL;


    return res;

}

int counter(char *str, char symb, int lenn) {
    int c = 0;
    for (int i = 0; i < lenn; ++i) {
        if (str[i] == symb)
            c++;
    }
    return c;
}

int main() {
    FILE *input = fopen("input.txt", "r");
    int *Exists = (int *) malloc(256 * sizeof(int));
    int *Avail = (int *) malloc(256 * sizeof(int));
    int **Cur_matrix = (int **) malloc(256 * sizeof(int *));
    int **Res_matrix = (int **) malloc(256 * sizeof(int *));
    char *data = NULL;
    size_t len;
    ssize_t bytes_read = getdelim(&data, &len, '\0', input);
    char **str = (char **) malloc(256 * sizeof(char *));

    str = split(data, "\n");

    /*int lenn = strlen(str[0]);
    int spaces = counter(str[0], ' ', lenn);*/
    char **st = (char **) malloc(resourses * sizeof(char *));
    st = split(str[0], " ");
    //printf("%d", resourses);
    for (int i = 0; i < resourses; ++i) {
        Exists[i] = atoi(st[i]);
    }
    st = split(str[2], " ");
    for (int i = 0; i < resourses; ++i) {
        Avail[i] = atoi(st[i]);
    }
    for (int i = 4; i < (Num_of_lines - 5) / 2 + 4; i++) {
        st = split(str[i], " ");
        Cur_matrix[i - 4] = (int *) malloc(resourses * sizeof(int));
        for (int j = 0; j < resourses; ++j) {
            Cur_matrix[i - 4][j] = atoi(st[j]);

        }
    }
    for (int i = 5 + (Num_of_lines - 5) / 2; i < Num_of_lines; i++) {
        st = split(str[i], " ");
        Res_matrix[i - 5 - (Num_of_lines - 5) / 2] = (int *) malloc(resourses * sizeof(int));
        for (int j = 0; j < resourses; ++j) {
            Res_matrix[i - 5- (Num_of_lines - 5) / 2][j] = atoi(st[j]);
        }
    }
    int n= (Num_of_lines-5)/2;
    int m= resourses;
    bool processes[n];
    for (int i = 0; i < n; ++i) {
        processes[i]= false;
    }
    while(1){
        if(resourse_menager(n, m, processes, Avail, Cur_matrix, Res_matrix)==-1)
            break;
    }
    int dl =0;
    for (int i = 0; i < n; ++i) {
        if(!processes[i]){
            printf("%d proccess ", i+1);
            printf("is in deadlock\n");
            dl++;
        }
    }
    printf("Number of deadlocks: %d", dl);
    return 0;
}

