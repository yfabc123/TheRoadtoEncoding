#include<stdio.h>
#include<string.h>

int f1(const char *a,const char* b) {
	int index=0;
	int temp=a[index]-b[index];
	while(a[index]!='\0'&&a[index]==b[index]) {
		index++;
	}
	return  temp;

}
int main( ) {

	char *s="abcd";
	s[3]='\0';
	printf("%c\n",s[3]);
	printf("%c\n",s[3]);
	printf("%s\n",s);
	
	printf("%c\n",s[4]);
	char* p=strchr(s,'a');
	printf("%p\n",s);

	p++;
	printf("%p\n",p);
	p++;
	printf("%p\n",p);
//while(p!=NULL){
//    printf("%p\n",p);
//    p++;
//    p=strchr(p,'a');
//}




}

