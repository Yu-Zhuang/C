//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//古典問題:有一對兔子，從出生後第 3 個月起每個月都生一對兔子，小兔子長到 第三個月後每個月又生一對兔子，假如兔子都不死，問每個月的兔子總數為多少?1,1,2,3,5,8,13,21...
#include <stdio.h>
int main (void)
{
    int b1=0;
    int b2=1;
    int sum;
    int n;
    int i;

    
    printf("幾個月: "); //input
    scanf("%d", &n);
    
    printf("1, "); //output
    for (i=1;i<n;i++)
    {
        sum=b1+b2;
        printf("%d, ", sum);
        b1=b2;
        b2=sum;
    }
    
    printf("\n結束\n");
    return 0;
}
