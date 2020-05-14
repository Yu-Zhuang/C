//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:求 1+2!+3!+...+20!的和
#include <stdio.h>
int main (void)
{
    int i,j; //variable
    int sum=1;
    int n=0;
    
    for (i=1;i<=20;i++) //conpution
    {
        sum=1;
        for (j=1;j<=i;j++)
        {
            sum=sum*j;
        }
        n+=sum;
    }
    
    printf("1!+2!+3!+...20!總和為: %d", n); //output
    
    printf("\n");
    return 0;
}
