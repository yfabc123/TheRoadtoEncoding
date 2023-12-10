#include <stdio.h>

char* f1(char *a,const char* b) {

	char *temp=a;
	while( *a++=*b++) {
	}
	*a='\0';
	return temp;
}
int main() {
	char b[]="abcd";
	char *a=(char*)malloc(strlen(b)+1);
	printf("%s",f1(a,b));
	return 0;
}


