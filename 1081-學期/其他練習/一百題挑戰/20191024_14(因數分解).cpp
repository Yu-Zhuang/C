//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:將一個正整數分解質因數。例如:輸入 90,列印出 90=2*3*3*5
#include <stdio.h>
int main(void)
{
    int num;
    int i=2;
    int j=2;
    int sum;
    
    printf("請輸入一個正整數: ");
    scanf("%d", &num);
    
    printf("%d因式分解為: ", num);
    for (i=2;i<=num;i++)
        for (j=2;j<=i;j++)
        {
            if (i==j)
            {
                if (num%i==0)
                {
                    num=num/i;
                    printf("%d*", i);
                    i=1;
                    j=1;
                    break;
                }
                else
                    continue;
            }
            else if (i%j!=0)
                continue;
            else if (i%j==0)
                break;
        }

    printf("\n結束\n");
    return 0;
}

