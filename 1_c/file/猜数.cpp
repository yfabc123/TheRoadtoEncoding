#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	srand((unsigned int)time(NULL));
	int ret = rand()% 10;//��10ȡ��ɵõ�10���ڵ��� 
	printf("%d\n", ret);


	int a;
	int num=1;
	printf("��������µ���:") ;
	scanf("%d",&a);

while(a!=ret){
	if(a<ret){
		printf("��С��");
	}
	else if(a>ret){
	printf("�´���");
	} 
	printf("����������:");
	scanf("%d",&a); 
	num++;
	
}
printf ("��ϲ�����ڲ¶���,����%d",num
);
	return 0;

}

