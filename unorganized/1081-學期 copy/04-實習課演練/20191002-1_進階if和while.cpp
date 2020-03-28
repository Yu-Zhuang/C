//
//  106711129-3-1.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int age;
    int ident;
    
    printf("～歡迎使用購票系統～\n");
    printf("請輸入年齡： "); //輸入年齡
    scanf("%d", &age);
    while (age<0) //防呆
    {
        printf("\n你的年齡輸入錯誤！");
        printf("請重新輸入年齡： ");
        scanf("%d", &age);
    }
    
    printf("請輸入身份別(學生請輸入‘1’, 非學生請輸入‘2’)："); //輸入身份
    scanf("%d", &ident);
    while (ident!=1&&ident!=2) //防呆
    {
        printf("\n你輸入錯誤！");
        printf("請重新輸入(1 or 2)： ");
        scanf("%d", &ident);
    }
                //執行輸出
    if (age<=6||age>=60)
    {
        printf("\n你的票價為 120 元\n");
    }
    else if ((ident==1&&age>=6)||(ident==1&&age<=20))
    {
        printf("\n你的票價為 160 元\n");
    }
    else
    {
        printf("\n你的票價為 200 元\n");
    }
    
        system("pause");
        return 0;
}
