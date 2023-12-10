#include <stdio.h>

struct date {
	int year;
	int month;
	int day;
};
//判断平闰年函数
int fun1(struct date a) {
	int result=0;//平年

	if(a.year%4==0&&a.year%100!=0 || a.year%400==0) {
		result=1;
	}
	return result;
}
int main() {
	struct date today;
	struct date tomorrow;

	printf("今天日期：");
	
	scanf("%d",&today.year);
	
	
		// 定义日历
	int a[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
	if(fun1(today)) {
		a[1]=29;
	}
	
	//月份不超过 12  日期根据据月份自动判断
	scanf("%d",&today.month);
	while(today.month>12) {
		printf("月份不合理请重新输入：");
		scanf("%d",&today.month);
	}
	scanf("%d",&today.day);
	while(today.day>a[today.month-1]) {
		printf("日期不合理请重新输入");
		scanf("%d",&today.day);
	}
printf ("您输入的日期为:%d-%d-%d\n",today.year,today.month,today.day);



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

	printf("明天的日期为：%d-%d-%d",tomorrow.year,tomorrow.month,tomorrow.day);
	return 0;
}


