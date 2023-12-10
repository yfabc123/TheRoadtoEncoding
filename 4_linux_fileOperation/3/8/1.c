#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
int main(int argc,char*argv[]){
	char buff[64];
	FILE*fp1=fopen(argv[1],"r");
	FILE*fp2=fopen(argv[2],"w");
	while(fgets(buff,sizeof(buff),fp1)!=NULL)  {
		fputs(buff,fp2);
	}
	fclose(fp1);
	fclose(fp2);

}
