#include<stdio.h>  
#include<stdlib.h>  
int recursionF(int);  
int main(void){  
    int input=0, output=0;  
    //input number
    scanf("%d", &input);  
    //use recursion ()
    output=recursionF(input);  
    printf("%d\n", output);  
    return 0;  
}  
int recursionF(int num){  
	// if(n=0 or n=1) n+=1;
    if(num<2&&num>-1) num+=1;  
    // if(n>1) use recursion ();
    else num=recursionF(num-1)+recursionF(num/2);  
    return num;  
} 