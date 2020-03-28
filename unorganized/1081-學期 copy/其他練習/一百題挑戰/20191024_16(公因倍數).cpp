//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//輸入兩個正整數 m 和 n，求其最大公因數和最小公倍數。
#include <stdio.h>
int main(void)
{
    int m;
    int n;
    int i;
    int j;
    int re[1000000];
    int count=0;
    
    printf("請輸入一個正整數: "); //input
    scanf("%d", &m);
    printf("請輸入另一個正整數: ");
    scanf("%d", &n);
    
    for (i=1;i<=m&&i<=n;i++) //conpution 找最大公因數
    {
        if (m%i==0&&n%i==0)
        {
            count+=1;
            re[count]=i;
        }
        else
            continue;
    }
    printf("%d與%d的最大公因數為: %d\n", m, n, re[count]); //最大公因數ouput
    
    if (m>n) //conpution 找最小公倍數
        j=m;
    else
        j=n;
    
    for (j;j<=m*n;j++)
    {
        if (j%m==0&&j%n==0)
        {
            printf("%d與%d的最大公倍數為: %d", m, n, j); //最大公倍數output
            break;
        }
        else
            continue;
    }
    
    printf("\n結束\n"); //end
    return 0;
}
