#include <stdio.h>
#include <string.h>
int main(){
	char str[256];
	int i=0;
	str[i]=getchar();
	while(str[i]!='\n' && str[i]!='.')
		str[++i]=getchar();
	printf("%c", '"');
	for(int k=strlen(str)-2; k>=0; k--){
		printf("%c", str[k]);
	}
	printf("%c", '"');
}
