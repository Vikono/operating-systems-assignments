#include <stdio.h>
#include <math.h>
#include <string.h>
long long int convert(long long int x, int s, int t){
    long long int res=0;
    long long int decimal=0;
    int i=0;
    while(x>0){
        decimal+=(x%10)*pow(s,i);
        i++;
        x/=10;
    }
    i=0;
    while(decimal>0){
        res+=(decimal%t)*pow(10,i++);
        decimal/=t;
    }
    return res;
    
}
int main()
{
    long long int n, temp;
    int osn1, osn2;
    printf("Enter a number: ");
    scanf("%lld", &n);
    printf("Enter a numeral system of that number: ");
    scanf("%d", &osn1);
    printf("Enter a desired numeral system: ");
    scanf("%d", &osn2);
    if(osn1>10 || osn1<2 || osn2>10 || osn2<2){
        printf("Cannot convert!");
        return 0;
        
        
    }
    else{
        long long int copy=n;
        while(copy>0){
            if(copy%10>=osn1){
                printf("Cannot convert!");
                return 0;}
            copy/=10;
        }
    }
    temp=convert(n, osn1, osn2);
    printf("Number in a new numeral system: %lld", temp);
    return 0;
}
