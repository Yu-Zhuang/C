//
//  20191019.cpp
//  20191019
//
//  Created by Yu-Zhuang Lin on 2019/10/19.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include<stdio.h>
#include<stdlib.h>
void start(void); //宣告函數, 如果把函數寫在main前面則不需要宣告函數
int main(void)
{
    start(); //使用(呼叫)函數
    printf("使用函數\n");
    start(); //使用(呼叫)函數
    
    printf("\n");
    system("pause");
    return 0;
}

void start(void) //函數的定義
{
    printf("+++++++++\n");
    return;
}
/*  int add(int, int)
 
 #include<stdio.h>
 #include<stdlib.h>
 int add(int, int);
 int main(void)
 {
     int sum;
     int a=5;
     int b=3;
     
     sum=add(a, b); //使用函數
     printf("%d+%d=%d\n", a, b, sum);
     
     system("pause");
     return 0;
 }

 int add(int num1, int num2) //函數
 {
     int a;
     a=num1+num2;
     
     return a;
 }
 */

/* 函數練習1
 #include<stdio.h>
 #include<stdlib.h>
 void display(char, int);
 int main(void)
 {
     char ch;
     int times;

     printf("請輸入要列印的字元: ");
     scanf("%c", &ch);
     printf("請輸入要列印多少次：");
     scanf("%d", &times);

     display(ch, times);
     
     printf("\n");
     system("pause");
     return 0;
 }

 void display(char ch, int times)
 {
     int i=0;
     
     for (i;i<times;i++)
     {
         printf("%c", ch);
     }
     return;
 }

 */

/* 函數練習2。絕對值
 #include<stdio.h>
 #include<stdlib.h>
 void abv(int);
 int main(void)
 {
     int input;

     printf("請輸入一個數字: ");
     scanf("%d", &input);

     abv(input);
     
     printf("\n");
     system("pause");
     return 0;
 }

 void abv(int input)
 {
     if (input<0)
     {
         input=input*(-1);
         printf("該數的絕對值為：%d", input);
     }
     else
         printf("該數的絕對值為：%d", input);
     return;
 }
 */

/* 函數練習3。次方運算
 #include<stdio.h>
 #include<stdlib.h>
 void spv(int, int);
 int main(void)
 {
     int input;
     int sp;
     
     printf("請輸入一個整數: ");
     scanf("%d", &input);
     printf("請輸入幾次方: ");
     scanf("%d", &sp);
     
     spv(input, sp);
     
     printf("\n");
     system("pause");
     return 0;
 }

 void spv(int base, int n)
 {
     int i=1;
     int j=base;
     
     for (i;i<n;i++)
     {
         j*=base;
     }
     
     printf(" %d 的 %d 次方是：%d", base, n, j);
     
     return ;
 }

 */
/* 遞迴函數
 #include<stdio.h>
 #include<stdlib.h>
 int power(int, int); //function
 int main(void)
 {
     int base; // variable
     int n;
     
     printf("請輸入一個底數: "); //input
     scanf("%d", &base);
     printf("請輸入幾次方: ");
     scanf("%d", &n);
     
     printf(" %d的%d次方為: %d", base, n, power(base, n)); //ouput


     printf("\n");
     system("pause");
     return 0;
 }

 int power(int base, int n) //function
 {
     if (n>0)
         return base*power(base, n-1); //遞迴函數
     else
         return 1;
 }
 */
