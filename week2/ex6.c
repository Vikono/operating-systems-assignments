#include <stdio.h>
void triangle1(int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            printf("%c", '*');
        }
        printf("\n");
        
    }
}
void triangle2(int n){
    int t=0;
    if(n%2==0)
       t=n/2;
    else
        t=n/2+1;
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < i+1; j++) {
            printf("%c", '*');
        }
        printf("\n");
        
    }
    for (int i = t; i < n; i++) {
        for (int j= n-i; j >0; j--) {
            printf("%c", '*');
        }
        printf("\n");
    }
}
void rectangle(int n){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("*");
        }
        printf("\n");
    }
}
int main()
{
    int num, n, b;
    printf("Enter the number of the pattern from the range 1-3 : ");
    scanf("%d", &num);
    if(num==1){
        printf("Enter number of lines : ");
        scanf("%d", &n);
        triangle1(n);
    }
    else if(num == 2){
        printf("Enter number of lines : ");
        scanf("%d", &n);
        triangle2(n);
    }
    else if(num ==3){
        printf("Enter number of lines : ");
        scanf("%d", &n);
        rectangle(n);
    }
    else{
        printf("Wrong input");
    }

    return 0;
}

