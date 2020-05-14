//
//  20191021.cpp
//  20191021
//
//  Created by Yu-Zhuang Lin on 2019/10/21.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
void rev(int); //宣告相反數 的 函數
int main (void)
{
    int num; //variable
    
    printf("請輸入一個數: "); //input
    scanf("%d", &num);
    
    rev(num); //conpution, ouput
    
    printf("\n");
    system("pause");
    return 0;
}

void rev(int n) //相反數 的 函數
{
    int k; //variable
    
    while (n>=1) //運算
    {
        k=n%10;
        printf("%d", k);
        n=n/10;
    }
    return;
}
