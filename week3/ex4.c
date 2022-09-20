#include <stdio.h>
#include <stdlib.h>


void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *));

void *addInt(const void *a, const void *b) { //corr
    int a1=(*(int*)a);
    int b1=(*(int*)b);
    int *z= malloc(sizeof (int));
    *z=(a1+b1);
    return z;
}

void *addDouble(const void *a, const void *b) {
    double a1=(*(double *)a);
    double b1=(*(double *)b);
    double *z= malloc(sizeof (double));
    *z=(a1+b1);
    return z;

}

void *mulInt(const void *a, const void *b) { // corr
    int a1=(*(int *)a);
    int b1=(*(int *)b);
    int *z= malloc(sizeof (int));
    *z=(a1*b1);
    return z;

}

void *mulDouble(const void *a, const void *b) {
    double a1=(*(double *)a);
    double b1=(*(double *)b);
    double *z= malloc(sizeof (double));
    *z=(a1*b1);
    return z;

}

void *meanInt(const void *a, const void *b) {
    int a1=(*(int *)a);
    int b1=(*(int *)b);
    int *z= malloc(sizeof (int ));
    *z=(a1/b1);
    return z;
}

void *meanDouble(const void *a, const void *b) {
    double a1=(*(double *)a);
    int b1=(*(int *)b);
    double *z= malloc(sizeof (double));
    *z=(a1/b1);
    return z;
}

void *aggregate(void *base, size_t size, int n, void *initial_value, void *(*opr)(const void *, const void *)) {

    void *output;

    if (size == sizeof(int)) {
        int *baseCopy = ((int *) base);
        int *array = (int *) malloc((n + 1) * (sizeof(int)));
        array[0] = *((int *) initial_value);
        for (int i = 1; i < n + 1; ++i) {
            array[i] = baseCopy[i - 1];
        }


        if (opr != meanInt) {
            for (int i = 1; i < n + 1; ++i) {
                array[0] = *((int *) opr(&array[0], &array[i]));
            }
            output = &array[0];
        } else {
            for (int i = 1; i < n + 1; ++i) {
                array[0] = *((int *) addInt(&array[0], &array[i]));
            }
            int *result =opr(&array[0],&n);
            output = result;
        }

    } else {
        double *baseCopy = ((double *) base);
        double *array = (double *) malloc((n + 1) * (sizeof(double )));
        array[0] = *((double *) initial_value);
        for (int i = 1; i < n + 1; ++i) {
            array[i] = baseCopy[i - 1];
        }


        if (opr != meanDouble) {
            for (int i = 1; i < n + 1; ++i) {
                array[0] = *((double *) opr(&array[0], &array[i]));
            }
            output = &array[0];
        } else {
            for (int i = 1; i < n + 1; ++i) {
                array[0] = *((double *) addDouble(&array[0], &array[i]));
            }
            double *result =opr(&array[0],&n);
            output = result;
        }

    }

    return output;
}


int main() {

    int *ints = malloc(sizeof(int) * 6);
    double *doubles = malloc(sizeof(double) * 6);

    //printf("Enter 5 numbers for array of int:\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &ints[i]);
    for (int i = 0; i < 5; i++)
        scanf("%lf", &doubles[i]);
    // Addition
    int *result1a;

    int *initValueZero = malloc(sizeof(int));
    *initValueZero = 0;
    result1a = aggregate(ints, sizeof(int), 5, initValueZero, addInt);
    printf("%d\n", *result1a);

    double *result2a;

    double *initValueZeroD = malloc(sizeof(double));
    *initValueZeroD = 0.0;
    result2a = aggregate(doubles, sizeof(double), 5, initValueZeroD, addDouble);

    printf("%lf\n", *result2a);


    // Multiplication

    int *result1m;

    int *initValueOne = malloc(sizeof(int));
    *initValueOne = 1;
    result1m = aggregate(ints, sizeof(int), 5, initValueOne, mulInt);


    printf("%d\n", *result1m);

    double *result2m;

    double *initValueOneD = malloc(sizeof(double));
    *initValueOneD = 1;
    result2m = aggregate(doubles, sizeof(double), 5, initValueOneD, mulDouble);


    printf("%lf\n", *result2m);



    // Mean

    int *result1mean;

    //int* initValueZero = malloc(sizeof(int));
    //*initValueZero = 0;
    result1mean = aggregate(ints, sizeof(int), 5, initValueZero, meanInt);


    printf("%d\n", *result1mean);

    double *result2mean;
    /*
        double* initValueZero = malloc(sizeof(double));
        *initValueZero = 0;*/
    result2mean = aggregate(doubles, sizeof(double), 5, initValueZeroD, meanDouble);


    printf("%lf\n", *result2mean);


    // free the pointers
    //<WRITE YOUR CODE HERE>;

    free(ints);
    free(doubles);
    free(initValueZero);
    free(initValueOne);
    free(result1a);
    free(result2a);
    free(result1m);
    free(result2m);
    free(result1mean);
    free(result2mean);
    return EXIT_SUCCESS;
}


