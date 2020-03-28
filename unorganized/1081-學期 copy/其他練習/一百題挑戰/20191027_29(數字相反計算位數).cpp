//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:給一個不多於 5 位元的正整數，要求:一、求它是幾位數，二、逆序列印出各位數位。
#include <stdio.h>
int main (void)
{
    int i; //variable
    int input;
    int count=0;
    
    printf("請輸入一個小於等於5位的正整數: "); //input
    scanf("%d", &input);
    
    while (input<0&&input>99999) //FPD
    {
        printf("輸入錯誤 請重新輸入\n");
        printf("請輸入一個小於等於5位的正整數: ");
        scanf("%d", &input);
    }
    
    if (input>=0&&input<10) //conpution: for 0<=input<10
    {
        printf("%d", input); //ouput
        printf("\n總共1位數");  //output
    }
    
    else //conpution: for input>=10, <=99999
        for (i=0;i<=4;i++)
        {
            if (input<=99&&input>=10)
            {
                count+=2;
                printf("%d", input%10);  //output
                input=input/10;
                printf("%d", input%110);  //output
                printf("\n總共%d位數", count); //output
                break;
            }
            else
                printf("%d", input%10);  //output
                input=input/10;
                count+=1;
        }
    
    printf("\n");
    return 0;
}
