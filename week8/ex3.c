#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// Similarly to the previous exercise, 10 MB of memory is too small.
// We will not be able to see a process with "top" comand if it is not in top (at least it is hard to see, but not impossible).	
// With 1 GB - CPU usage: 38.3%
// 	       Memory usage: 88.3%
//	       RES: 3.4 g 	 	 				
int main(){
	int *arr;
	for(int i=0; i< 10; ++i){
		arr=malloc(1024*1024*1024);
		memset(arr, 0, 1024*1024*1024);
		sleep(1);
	}
	free(arr);
	return 0;
}

