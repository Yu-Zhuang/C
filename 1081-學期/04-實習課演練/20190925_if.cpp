//
//  main.cpp
//  20190925
//
//  Created by Yu-Zhuang Lin on 2019/9/25.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int number1;
    int number2;
    int number3;
    int number4;
    printf("請輸入一個整數：");
    scanf("%d", &number1);
    printf("請輸入第二個整數：");
    scanf("%d", &number2);
    if (number1%number2==0)
    {
        printf("%d是%d的倍數\n", number1, number2);
    }
    if (number1%number2!=0)
    {
        printf("%d不是%d的倍數\n", number1, number2);
    }
    //第二個程式碼
    printf("請輸入一個整數：");
    scanf("%d", &number3);
    printf("請輸入第二個整數：");
    scanf("%d", &number4);
    if (number3>number4)
    {
        printf("%d是比較大的數\n", number3);
    }
    if (number4==number3)
    {
        printf("兩個數一樣大\n");
    }
    if (number4>number3)
    {
        printf("%d是比較大的數\n", number4);
    }
    system("pause");
    return 0;
}
