//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//利用條件運算子的嵌套來完成此題:學習成績>=90 分的同學用 A 表示，60-89 分之 間的用 B 表示， 60 分以下的用 C 表示。
#include <stdio.h>
int main(void)
{
    int grade;
    
    start://FPD
    printf("請輸入分數: "); //input
    scanf("%d", &grade);
    
    while (grade<0) //FPD
    {
        printf("您輸入錯誤請重新輸入\n");
        goto start;
    }
        
    if (grade>=90) //compution and output
        printf("A");
    else if (grade>=60&&grade<=89)
        printf("B");
    else
        printf("C");

    printf("\n結束\n"); //end
    return 0;
}
