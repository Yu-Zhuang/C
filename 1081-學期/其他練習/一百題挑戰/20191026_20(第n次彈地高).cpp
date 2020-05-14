//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:一球從 100 米高度自由落下，每次落地後反跳回原高度的一半;再落下，求它在 第 10 次落地時，共經過多少米?第 10 次反彈多高?
#include <stdio.h>
int main (void)
{
    int i=1;
    double high=100;
    double sum=100;
    int n;
    
    printf("第幾次落地: "); //input
    scanf("%d", &n);
    
    if (n==1) //conpution
    {
        sum=100;
        high=50;
    }
        
    else
    {
        for (i=1;i<n;i++)
        {
            sum+=high;
            high=high/2;
        }
        high=high/2;
    }

    printf("第%d次落地時高共經歷: %lf 公尺\n", n, sum); //output
    printf("第%d次落地彈起高度為: %lf 公尺\n", n, high);
    
    printf("\n");
    return 0;
}
