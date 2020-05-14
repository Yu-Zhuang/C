//
//  20191021.cpp
//  20191021
//
//  Created by Yu-Zhuang Lin on 2019/10/21.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int i;
    int score[4]; //宣告陣列: 陣列名稱[個數]
                 // 不同型別的陣列: float temp[7]; char name[12]
    
    score[0]=78; // 設定陣列的 第n個元素 為 多少
    score[1]=25;
    score[2]=60;
    score[3]=90;
    /*    亦可於"宣告"時 直接給定陣列的值 :
            int score[4]={78,25,60,90}
            
     如想將陣列皆設為同一個值: int score[5]={3} //內容值皆為 3
     */
    
    for (i=0;i<=3;i++) // 印出陣列內容
    {
        printf("score_%d=%d\n", i, score[i]); // 印出陣列內容
    }
    
    system("pause");
    return 0;
}
