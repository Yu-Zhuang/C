//import header file
#include<stdio.h>
#include<stdlib.h>
//start 
int main(void){
	//variable announce
	int a=0, b=3; //interger, 4 byte, -2147483648 ~ +2147483648 (2^32);
	float c=1.2; //float, 4byte, 1.2e-38 ~ 3.4e38;
	double d=2.7; //double, 8 byte, 2.2e-308 ~ 1.8e308;
	char e='a'; //char, 1byte, 0~255;
	char f[]="hello world"; //string;

	//input, output
	printf("origin: %d %f %lf %c %s\n", a, c, d, e, f); //output : show origin variable value;
	scanf("%d %f %lf %c %s", &a, &c, &d, &e, f); //input
	printf("new: %d %f %lf %c %s", a, c, d, e, f); //output (after input new value);
	
	//operator and compution
	a=a+2; //+, -, *, /
	printf("%d", a); // output: 4
	a-=3; // +=, -=, *=, /=
	printf("%d", a); //output: 1

//end;
	return 0;
}