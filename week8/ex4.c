#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main(){
	int *arr;
	struct rusage res;
	for(int i=0; i< 10; ++i){
		arr=malloc(10*1024*1024* sizeof(int));
		memset(arr+i, 0, 10*1024*1024);
		getrusage(RUSAGE_SELF, &res);
		printf("%ld \n", res.ru_maxrss);
		sleep(1);
	}
	free(arr);
	return 0;
}
	
