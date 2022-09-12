#include <stdio.h>
#include <string.h>

void count(char str[], char l){
	int counter=0;
	for(int i=0; i<strlen(str); i++){
		if(str[i]==l){
			counter++;
		}
	}
	printf("%c%c%d", l,':',counter);
}

void countAll(char str[]){
    for (int i = 0; i < strlen(str); i++) {
        if(i==0)
            count(str, str[i]);
        else{
            printf("%s", ", ");
            count(str, str[i]);}
    } 
}

			

int main(){
	char str[256];
    	char message[256];
    	char l;
    	int j=0;
    	int b=0;
	fgets(str, 256, stdin);
	for (int i = 0; i < strlen(str); i++) {
	    if(str[i]<97 && str[i]!=' ' && str[i]!=',')
	        str[i]+=32;
	}
	l=str[strlen(str)-2];
	while(str[j]!=',' && j<strlen(str) && str[j]!='*'){
	    message[j]=str[j];
	    j++;
	}
	for(int i=0; i<strlen(str);++i){
		if(str[i]==',')
			b=1;}
	if(b!=1)
	    countAll(message);
	else
	    count(message, l);
}
	
	
	
