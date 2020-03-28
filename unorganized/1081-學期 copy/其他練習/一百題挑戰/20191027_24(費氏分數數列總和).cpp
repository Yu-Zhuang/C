//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:有一分數序列:2/1，3/2，5/3，8/5，13/8，21/13...求出這個數列的前 20 項 之和。
#include <stdio.h>
int main (void)
{
    int i,j;
    int base[20];
    int a=1, b=2;
    int sum;
    double total=0;
    
    base[0]=1; //費氏數列
    base[1]=2;
    for (i=2;i<=20;i++)
    {
        sum=a+b;
        base[i]=sum;
        a=b;
        b=sum;
    }
    
    for (i=1;i<=20;i++) //數列相加
    {
        j=i-1;
        printf("(%d/%d)\n", base[i], base[j]);
        total+=(double)base[i]/base[j];
    }
    
    printf("\n數列的總和為: %lf", total); //output
    
    printf("\n");
    return 0;
}
