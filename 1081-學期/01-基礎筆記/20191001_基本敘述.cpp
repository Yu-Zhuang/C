//
//  main.cpp
//  20191001_基本敘述
//
//  Created by Yu-Zhuang Lin on 2019/10/1.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h> //input output標頭檔
#include<stdlib.h> //system pause標頭檔
int main(void) //main function 帶入void 型別為int, return 0
{
    int num_1; // 宣告ㄧ個 整數 變數, 還有double, char...型別可以宣告
    
    printf("hello C\n"); // ‘\n’跳脫字元 換行, ’;‘此行程式執行到這裡, ""字串, ‘’字元
    
    printf("enter a number: "); // 第二個程式
    scanf("%d", &num_1); //input function, 將輸入的"%d" 值 指派(&)給變數num_1
    printf("the number is %d\n", num_1); //輸出 %d 值以 變數 num_1
    
    system("pause");
    return(0);
}
