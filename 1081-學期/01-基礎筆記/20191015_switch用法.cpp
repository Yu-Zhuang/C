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
    int input;

    
    printf("請輸入任意整數："); //input
    scanf("%d", &input);
    
    switch (input) { //switch運算與output
        case 1:
            printf("number = 1");
            break;
            
        default:
            printf("number != 1");
            break;
    }
    
    system("pause");
    return 0;
}
