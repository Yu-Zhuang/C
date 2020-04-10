#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>  
int main(void){  
    char A[129], B[513];  
    int ret=0, len_A=0, len_B=0, i=0, k=0, tmp=0;  
    scanf("%s",A); scanf("%s", B);  
    len_A=strlen(A); len_B=strlen(B);  
    for(i=0;i<len_B;i++){  
        k=0; tmp=i;  
        while(B[tmp]==A[k]&&A[k]!='\0') { k++; tmp++; }  
        if(k==len_A) ret++;  
    }  
    printf("%d\n", ret);  
    return 0;  
} 