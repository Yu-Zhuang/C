//
//  20191020.cpp
//  20191020
//
//  Created by Yu-Zhuang Lin on 2019/10/20.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
void sum(int), fac(int);
int main(void)
{
    sum(5);
    printf("\n");
    fac(5);
    
    printf("\n");
    system("pause");
    return 0;
}

void sum(int n)
{
    int i=1;
    int j=0;
    
    for (i;i<=n;i++)
    {
        j+=i;
    }
    printf("1+2+...+%d=%d", n, j);
    
    return ;
}

void fac(int n)
{
    int i=1;
    int k=1;
    
    for (i;i<=n;i++)
    {
        k*=i;
    }
    
    printf("1x2x...x%d=%d", n, k);
    return;
}

