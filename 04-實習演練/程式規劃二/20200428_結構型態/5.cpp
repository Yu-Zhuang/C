#include<stdio.h>  
#include<stdlib.h>  
int main(void){  
    int ret[8]={0}, a=1, b=0, input=0, flag=1;  
    // input
    scanf("%d", &input);  
    if(input<0) { flag=0; input*=-1; }  
    // compution
    for(int i=0;i<8;i++){  
        if(input){  
            ret[i]=input%2;  
            input/=2;  
        }  
        else if(flag)  //該數為正號 後面補0
            ret[i]=b;  
        else  
            ret[i]=a;  //該數為負號 後面補1
    }  
    // 印出結果
    for(int j=7;j>=0;j--) printf("%d", ret[j]);  
    printf("\n");  
    return 0;  
} 