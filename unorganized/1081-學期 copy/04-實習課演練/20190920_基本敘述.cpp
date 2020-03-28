//
//  main.cpp
//  20190920
//
//  Created by Yu-Zhuang Lin on 2019/9/20.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    double height;
    double mass;
    double BMI;
    double avrg;
    printf("請輸入你的身高(公尺): ");
    scanf("%lf", &height);
    printf("請輸入你的體重(公斤): ");
    scanf("%lf", &mass);
    BMI=mass/(height*height);
    printf("\n你的BMI是%lf\n", BMI);
    avrg=(height+mass+BMI)/3;
    printf("project2 answer=%lf\n",avrg);
    system("pause");
    return 0;
}
