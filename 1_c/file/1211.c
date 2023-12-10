#include <stdio.h>

int devide(int a,int b,int  *result) {
	int ret=1;
	if(b==0) {
		ret=0;
	} else {
		*result=a/b;
		return ret;

	}
}
	int main() {
		int a=1;
		int b=0;
		int c;
		if(devide(a,b,&c)){
		    printf("%d/%d=%d\n",a,b,c);
        }

		return 0;
}


