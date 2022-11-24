#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <linux/input.h>
int main(){
int fd = open("/dev/input/by-path/platform-i8042-serio-0-event-kbd", O_RDONLY);
struct input_event event;
while(1){
	read(fd, &event, sizeof(event));
	if(event.type==EV_KEY){
		if(event.value == 1)
			printf("%s 0x%04X (%d) \n", "PRESSED", event.code, event.code);
		if(event.value == 0)
			printf("%s 0x%04X (%d) \n", "RELEASED", event.code, event.code);
	//printf("%hu\n", event.code);
	}
}}
