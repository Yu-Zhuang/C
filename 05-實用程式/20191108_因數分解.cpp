//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
int main(void){
    int input;
    int i;
    int temp=0;
    int output;
    printf("請輸入一個正整數: "); //input
    scanf("%d", &input);
    output=input; //儲存最後輸出時要用
    
    do{ //做到temp==0
        temp=0; //temp歸零
        for(i=2;i<=input;i++){
            if(input%i==0){
                temp=1;  //找到因數temp==1 (至少有原數
                if(input/i==1){ //input數被除到剩1(代表因數都找完)
                    printf("%d=",i);
                    temp=0; //做到這裡temp==0
                    break; //找到因數後跳出 再重2開始檢驗
                }
                input=input/i;
                printf("%d*",i);
                break;
            }
            else
                continue;
        }
    }while(temp==1);
    printf("%d\n",output); 
    return 0;
}
