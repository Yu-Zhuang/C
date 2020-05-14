//
//  20191006.cpp
//  20191002
//
//  Created by Yu-Zhuang Lin on 2019/10/6.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h>
int main(void)
{
    int i=0;
    
    for (i;i<1000;i++) //找一個符合 除3於1, 除5於3, 除7於2 的最小數
    {
        if (i%3==1&&i%5==3&&i%7==2){ // 運算
            printf("%d ", i); // output
            break;
        }
    }
    
    printf("\n");
    system("pause");
    return 0;
}
