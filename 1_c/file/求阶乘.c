#include <stdio.h>
//���� ȷ���������ֵĳ��� 
int main()
{


int a=0;
int i=0;

scanf("%d",&a);

do{
	i++;
	a=a/10;
	
	
}while(a>0); 
printf("a�ĳ�����%d",i) ;

return 0; 

}
