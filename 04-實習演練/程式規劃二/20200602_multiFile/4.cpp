#include<stdio.h>    
#include<stdlib.h> 

int F(int num){    
    // if(n=0 or n=1) n+=1;  
    if(num<2&&num>-1)
    	return num+=1;   
    // if(n>1) use recursion ();  
    else    
    	return F(num-1)+F(num/2);    
}    

int main(void){    
    int input=0, output=0;    
    //input number  
    scanf("%d", &input);    
    //use recursion ()  
    output=F(input);    
    printf("%d\n", output);    
    return 0;    
}    
