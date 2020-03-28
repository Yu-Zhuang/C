//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:求 s=a+aa+aaa+aaaa+aa...a 的值，其中 a 是一個數字。例如 2+22+222+2222+22222(此時共有 5 個數相加)，幾個數相加有鍵盤控制。
#include <stdio.h>
int main (void)
{
    int i; //variable
    int num;
    int times;
    int squ=1;
    int sum=1;
    int total[100000];
    int suma=0;
    
    printf("請輸入1~9其中一個數: "); //input
    scanf("%d", &num);
    printf("請輸入要相加多少次: ");
    scanf("%d", &times);
    

    total[0]=1;
    for (i=1;i<times;i++) //建立陣列 1, 1 11, 1 11 111, ...
    {
        squ=squ*10;
        sum+=squ;
        total[i]=sum;
    }
    
    for (i=0;i<(times-1);i++) // output 1+11, 2+22, ...
    {
        printf("%d+", (total[i]*num));
    }
    
    
    for (i=0;i<times;i++) //conpution 計算 1+11, 2+22, ...
    {
        suma+=num*(total[i]);
    }
    
    printf("%d=%d", total[times-1]*num, suma); //output +111=123, +222=246,..
    
    printf("\n");
    return 0;
}
