//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.

//輸入某年某月某日 輸出這是今年的第幾天
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int year; //variable
    int month;
    int date;
    int count;
    
    printf("請輸入年份: "); //input
    scanf("%d", &year);
    printf("請輸入月份: ");
    scanf("%d", &month);
    printf("請輸入日期: ");
    scanf("%d", &date);
    
    while (year<0||month<=0||date<=0) //FPD
    {
        printf("年份必須大於等於0. 月份, 日期 必須大於0\n");
        printf("請重新輸入\n");
        printf("請輸入年份: ");
        scanf("%d", &year);
        printf("請輸入月份: ");
        scanf("%d", &month);
        printf("請輸入日期: ");
        scanf("%d", &date);
    }

    if (year%4==0) //運算 閏年
    {
        switch(month)
        {
            case 1:
                count=0;
                break;
            case 2:
                count=31;
                break;
            case 3:
                count=60;
                break;
            case 4:
                count=91;
                break;
            case 5:
                count=121;
                break;
            case 6:
                count=152;
                break;
            case 7:
                count=182;
                break;
            case 8:
                count=213;
                break;
            case 9:
                count=244;
                break;
            case 10:
                count=274;
                break;
            case 11:
                count=305;
                break;
            case 12:
                count=335;
                break;
        }
    }
    
    else    //非閏年
    {
        switch(month)
        {
            case 1:
                count=0;
                break;
            case 2:
                count=31;
                break;
            case 3:
                count=59;
                break;
            case 4:
                count=90;
                break;
            case 5:
                count=120;
                break;
            case 6:
                count=151;
                break;
            case 7:
                count=181;
                break;
            case 8:
                count=212;
                break;
            case 9:
                count=243;
                break;
            case 10:
                count=273;
                break;
            case 11:
                count=304;
                break;
            case 12:
                count=334;
                break;
        }
    }
    
    count+=date;
    
    printf("這是今年的第 %d 天", count); //output
    
    printf("\n");
    system("pause");
    return 0;
}
