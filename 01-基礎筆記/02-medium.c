#include<stdio.h>
#include<stdlib.h>
/*
include:
1. flow control: if, else if, else, switch case;
2. loop: while(), for();
3. funciton;
*/
// function: returnType functionName (argumentType argument);
int HiFunction(int N);

int main(void){
	int a=0, flag=1, N=0;

//while loop;
	while(flag){ 
		printf("enter a number between 1~9(end enter 0): ");
		scanf("%d", &a);
		// operator: >, <, ==, <=, >=, &&, ||
		while(a < 0 || a>9) { printf("wrong input! input again: "); scanf("%d", &a); }
		//flow control: if, else if, else
		if(a < 5 && a > 0){
			printf("a < 5 && a > 0\n");
		}else if(a > 5){
			printf("a > 5\n");
		}else if(a == 5){
			printf("a == 5\n");
		}else{
			flag=0;
		}
		N++;
	}
	//for loop
	for(int i=0 ; i<N ; i++){
		printf("you run %d times\n", i+1);
	}

//function project:
	//function annouce (see line 4 and 5);
	if(HiFunction(N)) printf("function run success"); //use function which defined by youself;

	return 0;
}
//
int HiFunction(int N){
	printf("Hi , you run %d times\n",N);
	return 1;
}
