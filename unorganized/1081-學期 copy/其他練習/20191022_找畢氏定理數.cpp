//
//  20191022.cpp
//  20191022
//
//  Created by Yu-Zhuang Lin on 2019/10/22.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
void find(int n);
int main(void)
{
    int num;
    
    printf("請輸入一個正整數: "); //input
    scanf("%d", &num);
    
    find(num); // output

    printf("\n");
    system("pause");
    return 0;
}

void find(int n)
{
    int a;
    int b;
    int c;
    int count=0; //計算有幾組
    
    for(a=1;a<=n;a++)
    {
        for (b=a;b<=n;b++)
        {
            for (c=(b+1);c<=n;c++)
            {
                if (c*c==b*b+a*a)
                {
                    printf("(%d,%d,%d)\n", a, b, c); //ouput
                    count+=1; //計算有幾組
                }
                else
                    continue;
            }
        }
    }
    
    printf("%d", count); //計算有幾組
    
    return;
}
