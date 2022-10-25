#include <stdio.h>
#include <stdlib.h>

void *own_realloc(void *arr, size_t old_n, size_t new_n){
	void * arr2 = malloc(new_n);
	if(arr2==NULL) return NULL;
	if(new_n>old_n) memcpy(arr2, arr, old_n);
	else memcpy(arr2, arr, new_n);
	free(arr);
	return arr2;
int main(){

return 0;
}
	
