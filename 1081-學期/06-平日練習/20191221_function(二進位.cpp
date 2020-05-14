//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void binary(int);
int main(void){ //main
    int input,flag=1;
    while(flag){
        printf("輸入一整數: ");
        scanf("%d",&input);
        printf("%d用二進位表示成: ",input);
        binary(input);
        printf("\n");
        printf("\n繼續按1, 結束按0: ");
        scanf("%d",&flag);
    }

    return 0;
}

void binary(int num){
    if(num>0){
        binary(num/2);
    }
    if(num%2==0){
        printf("0");
    }else if(num%2==1){
        printf("1");
    }
}
