//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:有 5 個人坐在一起，問第五個人多少歲?他說比第 4 個人大 2 歲。問第 4 個人歲 數，他說比第 3 個人大 2 歲。問第三個人，又說比第 2 人大兩歲。問第 2 個人，說比 第一個人大兩歲。最後 問第一個人，他說是10歲。請問第五個人多大?
#include <stdio.h>
int main (void)
{
    int i;
    int sum=10;
    
    for (i=2;i<=5;i++)
    {
        sum+=2;
    }
    
    printf("第五個人%d歲", sum);
    
    printf("\n");
    return 0;
}

/* 用遞迴函數的寫法
 #include <stdio.h>
 int age(int);
 int main(void)
 {
     printf("%d",age(5));
     
     printf("\n");
     return 0;
 }

 int age(int n)
 {
     int c;
     if (n==1)
         c=10;
     else
         c=age(n-1)+2;
     return c;
 }
 */
