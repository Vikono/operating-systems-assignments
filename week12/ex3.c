#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/input.h>
int count(int *arr){
	int count=0;
	for(int i=0; i<200;++i){
		if(arr[i]==1)
			count++;}
	return count;}
int main(){
	int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
	struct input_event event;
	int isVisited[200];
	for(int i=0; i<200; i++){
		isVisited[i]=0;}
	printf("available shortcuts:\n");
	printf("P+E: \"I passed the Exam!\"\n");
	printf("C+A+P: \"Get some cappuchino!\"\n");
	printf("C+V: \"Copy and paste\"\n");
	while(1){
		read(fd, &event, sizeof(event));
		if(event.type==EV_KEY){
			if(event.value == 2){
				//sleep(0.5);
				if(isVisited[25] && isVisited[18] && count(isVisited)==2){
					printf("I passed the Exam!\n");}
				else if(isVisited[46] && isVisited[30] && isVisited[25] && count(isVisited)==3){
					printf("Get some cappuchino!\n");}
				else if(isVisited[46] && isVisited[47] && count(isVisited)==2){
					printf("Copy and paste\n");
					}
				}
			if(event.value == 0)
				isVisited[event.code]=0;
			if(event.value == 1)
				isVisited[event.code]=1;
			
		//printf("%hu\n", event.code);
		}
	}
}
