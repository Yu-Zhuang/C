//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:猴子吃桃問題:猴子第一天摘下若干個桃子，當即吃了一半，還不癮，又多吃了 一個第二天早上又將剩下的桃子吃掉一半，又多吃了一個。以後每天早上都吃了前一天 剩下的一半零一個。到第 10 天早上想再吃時，見只剩下一個桃子了。求第一天共摘了 多少。
#include <stdio.h>
int main (void)
{
    int i=1;
    int sum=1;

    for (i=9;i>=1;i-=1)
    {
        sum=2*(sum+1);
    }
    
    printf("第一天桃子有%d個", sum);
    
    printf("\n");
    return 0;
}
