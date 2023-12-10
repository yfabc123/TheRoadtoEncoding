#include "array.h"
#include <stdio.h>
#include <stdlib.h>

//���� ����һ����̬���� ���ҳ�������д����
//typedef struct{
//    int *array;
//    int size;
//} Array ;
//  Array array_creat(int init_size);
//  void array_free(Array *a);
//  int array_size(const Array *a);
//  int* array_at(Array *a,int index);
//   void array_inflate(Array *a,int more_size);

//����һ������ṹ
Array array_creat(int init_size) {

	Array a;
	a.size=init_size;
	a.array=(int*)malloc((sizeof(int))*a.size);
	return a;
}
//�������Ŀռ��ͷ�
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
	int temp=0;//����������
	int index=0;
	while(index!=-1) {
		printf("��������Ҫд�������");
		scanf("%d",&index);
		if(index!=-1) {
			printf("��������Ҫ�ڸ�������д���ֵ");
			scanf("%d",&temp);
			*array_at(&a,index)=temp;
		}


	}
	printf("�����̬���������ֵ��\n");
	for(int i=0; i<array_size(&a); i++) {
		printf("%d\n",*array_at(&a,i));
	}

	array_free(&a);
	return 0;


}


