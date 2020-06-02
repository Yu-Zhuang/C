# include <stdlib.h>
# include <stdio.h>
# include <string.h>

int ADD(int n){
	if(n == 1)
		return n;
	else
		return n+ADD(n-1);
}

int MULTI(int n){
	if(n == 1)
		return n;
	else
		return n*MULTI(n-1);
}

int main(void){
	int n = 0;
	do{
		printf("enter N: ");
		scanf("%d", &n);
		if(n<=0)
			printf("n should > 0!\n");
	}while(n<0);
	printf("add result: %d\n", ADD(n));
	printf("multiply result: %d\n", MULTI(n));
	return 0;
}