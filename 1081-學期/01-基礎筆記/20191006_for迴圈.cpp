//
//  20191006.cpp
//  20191002
//
//  Created by Yu-Zhuang Lin on 2019/10/6.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i;
    int sum=0;//宣告變數
    
    for (i=1;i<=10;i++)//for迴圈 起始值;最終值(條件判斷);增加值
        sum+=i;
    
    printf("1+2+3...+10=%d\n", sum);//輸出
    
    system("pause");
    return 0;
}

