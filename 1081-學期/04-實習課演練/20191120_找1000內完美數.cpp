//  Created by Yu-Zhuang Lin on 2019/10/2.
#include<stdio.h>
#include<stdlib.h>
int perfect(int);
int divi(int,int);

int main(void){
    int i;
    for(i=1;i<=1000;i++){
        if(perfect(i)==1)
            printf("%d是完美數\n",i);
    }

    return 0;
}

int perfect(int num){
    int i,count=0;;
    for(i=1;i<num;i++){
        if(divi(num,i)==1){
            count+=i;
        }
    }
    if(count==num)
        return 1;
    else
        return 0;
    
}

int divi(int num1,int num2){
    if(num1%num2==0)
        return 1;
    else
        return 0;
}


