//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.

//有 1、2、3、4 個數字，能組成多少個互不相同且無重複數字的三位元數?都是 多少?
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    int j;
    int k;
    
    for (i=1;i<=4;i++)
        for (j=1;j<=4;j++)
            for (k=1;k<=4;k++)
            {
                if (i==j||i==k||j==k)
                    continue;
                else
                    printf("(%d,%d,%d)\n", i, j, k);
            }

    
    printf("\n");
    system("pause");
    return 0;
}
