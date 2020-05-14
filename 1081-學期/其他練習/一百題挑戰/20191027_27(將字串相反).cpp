//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:利用遞迴函數調用方式，將所輸入的 5 個字元，以相反順序列印出來。
#include <stdio.h>
int main (void)
{
    int i;
    char noun[5];
    
    printf("請輸入5個字元: "); //input
    scanf("%s", &noun);
    
    for (i=4;i>=0;i-=1) //output
    {
        printf("%c", noun[i]);
    }

    printf("\n");
    return 0;
}
/* 用遞迴函數的解法
 
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
