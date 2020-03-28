//
//  20191005_運算子符.cpp
//  20191002
//
//  Created by Yu-Zhuang Lin on 2019/10/5.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    double for_input; //宣告要輸入的資料型態為一個倍精數
    double for_output;
    
    printf("請輸入一個數字： "); //輸入前的敘述
    scanf("%lf", &for_input);
    //輸入 double型態時用%lf，＆儲存至變數（ int 用%d, char 用%c, 字串用%s
    
    for_output=for_input*5+6/3;
    //運算 %餘數計算, &&且, ||或, 括號內先運算, ==等於, !=不等於, >=大於等於
    printf("您輸入的數字乘以5加2點為：%lf \n", for_output); //輸出
    
    system("pause");
    return 0;
}
