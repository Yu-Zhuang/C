//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//判斷 101-200 之間有多少個質數(prime )，並輸出所有質數。
#include <stdio.h>
int main(void)
{
    int m;
    int n;
    int i;
    int j;
    int count=0;
    
    start:
    printf("請輸入一個數正整數: "); //input
    scanf("%d", &m);
    printf("請輸入另一個正整數: ");
    scanf("%d", &n);
    
    while (m<0||n<0) //FPD
        goto start;
    
    for (i=m;i<=n;i++) //conpution and output
    {
        for (j=2;j<=i;j++)
        {
            if (i==j)
            {
               printf("%d, ", i);
                count+=1;
            }
                
            else if (i%j!=0)
                continue;
            else if (i%j==0)
                break;
        }
    }
    printf("\n%d到%d間共有%d個質數\n", m, n, count);
    
    printf("\n結束\n"); //end
    return 0;
}
