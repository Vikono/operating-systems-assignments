#include <stdio.h>
int tribonachi(int n){
    int a=0;
    int b=1;
    int c=1;
    int res=0;
    for(int i=3; i<=n; i++){
        res=a+b+c;
        a=b;
        b=c;
        c=res;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", tribonachi(n));

    return 0;
}

