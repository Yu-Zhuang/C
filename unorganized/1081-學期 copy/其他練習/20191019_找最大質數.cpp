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
    int input; //variable
    int i=2;
    int j=2;
    int count=0;
    
    printf("請輸入一個正整數: "); //input
    scanf("%d", &input);
    
    for(i=2;i<=input;i++) //找出input內的質數
    {
        for (j=2;j<=i;j++)
        {
            if (j==i)
            {
                count=j;
            }
            else if (i%j!=0)
            {
                continue;
            }
            else if (i%j==0)
            {
                break;
            }
        }
    }
    printf("%d",count); //output

    printf("\n");
    return 0;
}

