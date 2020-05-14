#include <stdio.h>   
int main(void){    
    int i=2, input=0, flag=0;  
    scanf("%d", &input);  
    while(i<=input){  
        if(i==input) { flag=1; break; }  
        if(input%i==0) break;  
        i++;  
    }  
    if(flag) printf("YES\n");  
    else printf("NO\n");  
    return 0;    
} 