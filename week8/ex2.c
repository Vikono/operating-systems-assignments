#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// allocating only 10 MB of memory is too litle to perform swapping. So, "si" and "so" parameters are always zero. 
// If we will allocate 1 GB of memory the vmstat shows:
//    si    so
//    45    1610
//    0     0
//    - - - -
//    0     17268
//    - - - - 
// The more memory needed, the more swapping actions is performed				
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
		
