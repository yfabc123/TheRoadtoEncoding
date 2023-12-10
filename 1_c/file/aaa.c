#include "array.h"
#include <stdio.h>
#include <stdlib.h>

//需求 创建一个动态数组 并且持续往里写数据
//typedef struct{
//    int *array;
//    int size;
//} Array ;
//  Array array_creat(int init_size);
//  void array_free(Array *a);
//  int array_size(const Array *a);
//  int* array_at(Array *a,int index);
//   void array_inflate(Array *a,int more_size);

//创建一个数组结构
Array array_creat(int init_size) {

	Array a;
	a.size=init_size;
	a.array=(int*)malloc((sizeof(int))*a.size);
	return a;
}
//将借来的空间释放
void array_free(Array *a) {
	free(a);
	a->size=0;
	a->array=0;
}

int array_size(const Array *a) {
	return a->size;
}

int* array_at(Array *a,int index) {
	if(a->size<=index) {
		array_inflate(a,index+1-a->size) ;
	}

	return &(a->array[index]);
}

void array_inflate(Array *a,int more_size) {
	int *p=(int*)malloc((a->size+more_size)*4);
	for(int i=0; i<a->size; i++) {
		p[i]=a->array[i];

	}
	free(a->array);
	a->array=p;
	a->size=a->size+more_size;


}

int main() {
	Array a=array_creat(3);
	int temp=0;//存放输入的数
	int index=0;
	while(index!=-1) {
		printf("请输入你要写入的索引");
		scanf("%d",&index);
		if(index!=-1) {
			printf("请输入你要在该索引上写入的值");
			scanf("%d",&temp);
			*array_at(&a,index)=temp;
		}


	}
	printf("输出动态数组的所有值：\n");
	for(int i=0; i<array_size(&a); i++) {
		printf("%d\n",*array_at(&a,i));
	}

	array_free(&a);
	return 0;


}


