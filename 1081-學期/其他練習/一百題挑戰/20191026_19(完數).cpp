//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:一個數如果恰好等於它的因數之和，這個數就稱為“完數”(perfect Number)。 例如 6=1+2+3.程式設計找出 1000 以內的所有完數。
#include <stdio.h>
int main (void)
{
    int i;
    int j;
    int sum=0;
    
    printf("以下是1000以內的所有完數: ");
    
    for (i=2;i<=1000;i++) // 2~1000的數
    {
        sum=0;
        for (j=1;j<i;j++) // 每一個數的因式相加
        {
            if (i%j==0)
            {
                sum+=j;
            }
            else
                continue;
        }
        if (sum==i) //判斷相加後是否等於該數 (即為完數)
        {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    return 0;
}
