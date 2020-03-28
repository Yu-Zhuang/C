#include<stdio.h>
#include<stdlib.h>
int main(void){
	int input,sum=0;
	scanf("%d", &input);
	for(int i=0;i<=input;i++){
		if(i%3==0){
			sum+=i;
		}
	}
	printf("%d\n", sum);
	return 0;
}