//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//輸入三個整數 x,y,z，請把這三個數由小到大輸出
#include <stdio.h>
#include <stdlib.h>
int main (void)
{
    int num[3];
    int i;
    int j;
    int k;
    
    printf("請輸入一個正整數: ");
    scanf("%d", &num[0]);
    printf("請再輸入一個正整數: ");
    scanf("%d", &num[1]);
    printf("請再輸入另一個正整數: ");
    scanf("%d", &num[2]);
    
    while (num[0]==num[1]||num[0]==num[2]||num[1]==num[2])
    {
        printf("三個數必須不一樣\n");
        printf("請輸入一個正整數: ");
        scanf("%d", &num[0]);
        printf("請再輸入一個正整數: ");
        scanf("%d", &num[1]);
        printf("請再輸入另一個正整數: ");
        scanf("%d", &num[2]);
    }

    for(i=0;i<=2;i++)
        for(j=0;j<=2;j++)
            for(k=0;k<=2;k++)
            {
                if (num[i]<num[j]&&num[j]<num[k])
                {
                    printf("%d < %d < %d", num[i], num[j], num[k]);
                }
                else
                    continue;
            }

    printf("\n");
    system("pause");
    return 0;
}
