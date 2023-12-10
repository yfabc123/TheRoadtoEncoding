#include<stdio.h>
int main(int argc,char*argv[]){
	FILE*fp_a=fopen(argv[1],"r");
	FILE*fp_b=fopen(argv[2],"w");
	char temp=fgetc(fp_a);//read a
	if(temp==EOF){
		perror("fgetc");
	}
	while(temp!=EOF){
		fputc(temp,fp_b);//write b 
		temp=fgetc(fp_a);//read a
	}
	fclose(fp_a);
	fclose(fp_b);



}
