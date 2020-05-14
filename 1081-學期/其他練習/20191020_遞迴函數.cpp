//
//  20191020.cpp
//  20191020
//
//  Created by Yu-Zhuang Lin on 2019/10/20.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
int power(int, int); //function
int main(void)
{
    int base; // variable
    int n;
    
    printf("請輸入一個底數: "); //input
    scanf("%d", &base);
    printf("請輸入幾次方: ");
    scanf("%d", &n);
    
    printf(" %d的%d次方為: %d", base, n, power(base, n)); //ouput


    printf("\n");
    system("pause");
    return 0;
}

int power(int base, int n) //function
{
    if (n>0)
        return base*power(base, n-1); //遞迴函數
    else
        return 1;
}
