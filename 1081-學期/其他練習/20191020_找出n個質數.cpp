//
//  20191020.cpp
//  20191020
//
//  Created by Yu-Zhuang Lin on 2019/10/20.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
void find(int); //找幾個質數的函數
int main (void)
{
    int num;
    
    printf("要找幾個質數: "); //input
    scanf("%d", &num);
    
    while (num<1) //FPD
    {
        printf("請輸入大於0的正整數\n");
        printf("請輸入大於0的正整數，要找幾個質數: ");
        scanf("%d", &num);
    }
    
    printf("%d個質數: ", num); //output
    find(num); //使用函數找出n個質數
    
    printf("\n");
    system("pause");
    return 0;
}

void find(int n) //找幾個質數的函數
{
    int i=2;
    int j=10000;
    int k=2;
    int count=0;
    
    for (i;i<=j;i++)
    {
        k=2;
        if (n==count)
            break;
        for (k;k<=i;k++)
        {

            if (k==i)
            {
                printf("%d ", i);
                count+=1;
            }
            else if (i%k!=0)
                continue;
            
            else if (i%k==0)
                break;
        }
        j+=10000;
    }
    return;
}

/*  數一個範圍內有幾個質數
 #include<stdio.h>
 #include<stdlib.h>
 int main(void)
 {
     int m; //宣告變數
     int n;
     int i;
     int j;
     int k=2;
     int count=0;
     
     start: //FPD
     
     printf("請嶿入一個正整數m: "); //input
     scanf("%d", &m);
     
     while (m<1) { //FPD
         goto start;
     }
     
     printf("請輸入另一個正整數n： "); //input
     scanf("%d", &n);
     
     while (n<1) { //FPD
         goto start;
     }
     
     while (m>n) //FPD
     {
         printf("m必須小於n\n");
         printf("請重新輸入\n");
         printf("請嶿入一個正整數m: ");
         scanf("%d", &m);
         printf("請輸入另一個正整數n： ");
         scanf("%d", &n);
     }
     
     i=m; //for use
     j=n+1;
     
     printf("%d到%d之間的質數有：",m ,n); //output
     
     for (i;i<j;i++) //compution
     {
         k=2;
         while (k<=i)
         {
             if (i==k)
             {
                 count+=1; //output
                 break;
             }
             if (i%k!=0)
             {
                 k+=1;
                 continue;
             }
             else if (i%k==0)
                 break;
         }
     }
     
     printf("%d 個質數",count);
     
     printf("\n");
     system("pause");
     return 0;
 }

 */
