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
    int i=0;
    int sum=0;
    
    start: //goto的start
    i+=1;
    sum+=i;
    printf("%d", i);
    
    if (i<10)
    {
        printf("+");
        goto start; //goto
    }
    

    system("pause");
    return 0;
}

