#include<stdio.h>
#include<stdlib.h>

void add(int a,int b);

int main(void){
	void (*ad)(int a, int b) = &add;
	
	(*ad)(5,3);

	return 0;
}

void add(int a,int b){ 
	printf("%d\n", a+b); 
}
