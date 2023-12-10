#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main(int argc,char*argv[]){
	FILE *fp1=fopen(argv[1],"r");
	char buff[64];
	char*temp=fgets(buff,sizeof(buff),fp1);

	while(temp==buff){
	fputs(buff,stdout);
	temp=fgets(buff,5,fp1);
	}
	fclose(fp1);
}
