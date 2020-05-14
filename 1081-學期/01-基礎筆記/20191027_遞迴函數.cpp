//
//  20191019.cpp
//  20191019
//
//  Created by Yu-Zhuang Lin on 2019/10/19.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//題目:有 5 個人坐在一起，問第五個人多少歲?他說比第 4 個人大 2 歲。問第 4 個人歲 數，他說比第 3 個人大 2 歲。問第三個人，又說比第 2 人大兩歲。問第 2 個人，說比 第一個人大兩歲。最後 問第一個人，他說是10歲。請問第五個人多大?
#include <stdio.h>
int age(int);
int main(void)
{
    printf("%d",age(5));
    
    printf("\n");
    return 0;
}

int age(int n)
{
    int c;
    if (n==1)
        c=10;
    else
        c=age(n-1)+2;
    return c;
}

/* 遞迴函數
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
*/

/* 例題二
 #include "stdio.h"
 void palin(int n);
 int main(void)
 {
     int i=5;

     printf("請輸入5個字元:");
     palin(i);
     
     printf("\n");
     return 0;
 }

 void palin(int n)
 {
     char next;
     if(n<=1)
     {
        next=getchar();
        printf("\n:");
        putchar(next);
     }
     else
     {
        next=getchar();
        palin(n-1);
        putchar(next);
     }
 }
 */
