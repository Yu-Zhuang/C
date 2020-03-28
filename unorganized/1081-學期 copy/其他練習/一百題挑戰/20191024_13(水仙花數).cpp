//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//列印出所有的“水仙花數”，所謂“水仙花數”是指一個三位元數，其各位數字 立方和等於該數本身。例如:153 是一個“水仙花數”，因為 153=1 的三次方+5 的三 次方+3 的三次方。
#include <stdio.h>
int main(void)
{
    int i;
    int f;
    int m;
    int l;
    
    for (i=100;i<1000;i++)
    {
        f=i/100;
        m=(i/10)%10;
        l=i%10;
        if (i==f*f*f+m*m*m+l*l*l)
            printf("%d ", i);
        else
            continue;
    }
    
    printf("\n結束\n");
    return 0;
}

