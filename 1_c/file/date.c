#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};
//�ж�ƽ���꺯��
int fun1(struct date a) {
	int result=0;//ƽ��

	if(a.year%4==0&&a.year%100!=0 || a.year%400==0) {
		result=1;
	}
	return result;
}
int main() {
	struct date today;
	struct date tomorrow;

	printf("�������ڣ�");
	
	scanf("%d",&today.year);
	
	
		// ��������
	int a[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	if(fun1(today)) {
		a[1]=29;
	}
	
	//�·ݲ����� 12  ���ڸ��ݾ��·��Զ��ж�
	scanf("%d",&today.month);
	while(today.month>12) {
		printf("�·ݲ��������������룺");
		scanf("%d",&today.month);
	}
	scanf("%d",&today.day);
	while(today.day>a[today.month-1]) {
		printf("���ڲ���������������");
		scanf("%d",&today.day);
	}
printf ("�����������Ϊ:%d-%d-%d\n",today.year,today.month,today.day);



	if(today.day==31&&today.month==12) {
		tomorrow.year=today.year+1;
		tomorrow.month=1;
		tomorrow.day=1;
	} else if(today.day==a[today.month-1]) {

		tomorrow.year=today.year;
		tomorrow.month=today.month+1;
		tomorrow.day=1;

	} else {
		tomorrow.year=today.year;
		tomorrow.month=today.month;
		tomorrow.day=today.day+1;
	}

	printf("���������Ϊ��%d-%d-%d",tomorrow.year,tomorrow.month,tomorrow.day);
	return 0;
}


