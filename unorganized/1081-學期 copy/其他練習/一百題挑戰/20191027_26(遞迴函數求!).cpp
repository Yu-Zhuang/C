//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:利用遞迴方法求 5!。
#include <stdio.h>
int func (int);
int main (void)
{
    int n;
    
    printf("請輸入要計算幾!: "); //input n!
    scanf("%d", &n);
    
    printf("%d!為: %d", n, func(n)); //用func遞迴函數計算 並output n!.
    
    printf("\n");
    return 0;
}

int func(int base) //conpution 遞迴函數運算 n!
{
    if (base>=1)
        return base*func(base-1);
    else
        return 1;
}
