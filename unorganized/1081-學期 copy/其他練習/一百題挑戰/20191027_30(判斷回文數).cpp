//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:一個 5 位數，判斷它是不是回文數。即 12321 是回文數，個位與萬位相同，十位 與千位相同。
#include <stdio.h>
int main (void)
{
    char input[5];
    
    printf("請輸入一個5位的正整數: ");
    scanf("%s", &input);
    
    if (input[0]==input[4]||input[1]==input[3])
    {
        printf("%s", input);
        printf("為一個回文數");
    }
        
    else
        printf("%s不是一個回文數", input);
    
    printf("\n");
    return 0;
}
