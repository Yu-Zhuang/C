//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int salary;
    
    printf("～薪資計算～\n");
    printf("該月業績："); //輸入業績
    scanf("%d", &salary);
    while(salary<0) //防止輸入錯誤
    {
        printf("您輸入錯誤，請重新輸入：");
        scanf("%d", &salary);
    }
            //執行輸出
    if(salary>=100000 && salary<=200000)
    {
        printf("這個月薪水為%d\n", salary/10+15000);
    }
    else if(salary>=200000)
    {
        printf("這個月薪水為: %d\n", salary/5+15000);
    }
    else
    {
        printf("這個月薪水為:15000\n");
    }
    
    system("pause");
    return 0;
}
