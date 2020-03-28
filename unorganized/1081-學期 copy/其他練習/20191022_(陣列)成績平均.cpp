//
//  20191021.cpp
//  20191021
//
//  Created by Yu-Zhuang Lin on 2019/10/21.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int max=10;
    int i;
    int j;
    int score[max]; //陣列
    int count=0;
    int sum;
    double avr;
    
    for (i=0;i<=max;i++) //input
    {
        printf("請輸入成績(結束數入0): ");
        scanf("%d", &score[i]);
        count+=1;
        max+=1;
        if (score[i]==0)
            break;
    }
    
    for (j=0;j<=(count-2);j++) //conpution 成績相加
    {
        sum+=score[j];
    }
    
    avr=(float)sum/(count-1); //算平均
    
    printf("成績平均為: %lf", avr); //output
    
    printf("\n");
    system("pause");
    return 0;
}
