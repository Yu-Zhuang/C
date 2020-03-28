//
//  20191006.cpp
//  20191002
//
//  Created by Yu-Zhuang Lin on 2019/10/6.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h>
int main(void)
{
    int input;
    int i=2;
    
    printf("～歡迎來到判斷質數的工具～\n");
    printf("請輸入任意整數："); //input
    scanf("%d", &input);
    
    while (input<=1) //防呆
    {
        printf("請輸入大於1的正整數：");
        scanf("%d", &input);
    }
       
     //運算與輸出
    while (i<=input)
    {
        if (i==input)
        {
            printf("此數為質數\n");
            break;
        }
        else if (input%i!=0)
        {
            i+=1;
            continue;
        }
        else if (input%i==0)
        {
            printf("此數不是質數\n");
            break;
        }

    }
    
    return 0;
}
