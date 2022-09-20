#include <stdio.h>
int foo(int age){
	return 2022-age;
}
int main(){
	const int x=10;
	const int *q=&x;
	const int * const p=(const int*)malloc(sizeof(const int)*5);
	int * k= p;
	for(int i=0;i <5; i++){
		*(k+i)=x;}
	for(int i=0; i<5; i++){
		printf("%p\n", k+i);
	}
	for(int i=0;i<5; i++){
		scanf("%d", k+i);}
	for(int i=0; i<5; ++i){
		*(k+i)=foo(*(k+i));}
	for(int i=0; i<5; ++i){
		printf("%d\n", *(k+i));
	}
	free(p);
	
}
		
	
		
