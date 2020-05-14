//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int m; //宣告變數
    int n;
    int i;
    int j;
    int k=2;
    
    start: //FPD
    
    printf("請嶿入一個正整數m: "); //input
    scanf("%d", &m);
    
    while (m<1) { //FPD
        goto start;
    }
    
    printf("請輸入另一個正整數n： "); //input
    scanf("%d", &n);
    
    while (n<1) { //FPD
        goto start;
    }
    
    while (m>n) //FPD
    {
        printf("m必須小於n\n");
        printf("請重新輸入\n");
        printf("請嶿入一個正整數m: ");
        scanf("%d", &m);
        printf("請輸入另一個正整數n： ");
        scanf("%d", &n);
    }
    
    i=m; //for use
    j=n+1;
    
    printf("%d到%d之間的質數有：",m ,n); //output
    
    for (i=m;i<j;i++) //compution
    {
        k=2;
        while (k<=i)
        {
            if (i==k)
            {
                printf("%d ", i); //output
                break;
            }
            if (i%k!=0)
            {
                k+=1;
                continue;
            }
            else if (i%k==0)
                break;
        }
    }
    
    printf("\n");
    system("pause");
    return 0;
}
/*  數一個範圍內有幾個質數
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int m; //宣告變數
    int n;
    int i;
    int j;
    int k=2;
    int count=0;
    
    start: //FPD
    
    printf("請嶿入一個正整數m: "); //input
    scanf("%d", &m);
    
    while (m<1) { //FPD
        goto start;
    }
    
    printf("請輸入另一個正整數n： "); //input
    scanf("%d", &n);
    
    while (n<1) { //FPD
        goto start;
    }
    
    while (m>n) //FPD
    {
        printf("m必須小於n\n");
        printf("請重新輸入\n");
        printf("請嶿入一個正整數m: ");
        scanf("%d", &m);
        printf("請輸入另一個正整數n： ");
        scanf("%d", &n);
    }
    
    i=m; //for use
    j=n+1;
    
    printf("%d到%d之間的質數有：",m ,n); //output
    
    for (i;i<j;i++) //compution
    {
        k=2;
        while (k<=i)
        {
            if (i==k)
            {
                count+=1; //output
                break;
            }
            if (i%k!=0)
            {
                k+=1;
                continue;
            }
            else if (i%k==0)
                break;
        }
    }
    
    printf("%d 個質數",count);
    
    printf("\n");
    system("pause");
    return 0;
}

*/



/*  全用for寫判斷質數
 #include<stdio.h>
 #include<stdlib.h>
 int main(void)
 {
     int m; //宣告變數
     int n;
     int i;
     int j;
     int k=2;
     
     start: //FPD
     
     printf("請嶿入一個正整數m: "); //input
     scanf("%d", &m);
     
     while (m<1) { //FPD
         goto start;
     }
     
     printf("請輸入另一個正整數n： "); //input
     scanf("%d", &n);
     
     while (n<1) { //FPD
         goto start;
     }
     
     while (m>n) //FPD
     {
         printf("m必須小於n\n");
         printf("請重新輸入\n");
         printf("請嶿入一個正整數m: ");
         scanf("%d", &m);
         printf("請輸入另一個正整數n：");
         scanf("%d", &n);
     }
     
     i=m; //for use
     j=n+1;
     
     printf("%d到%d之間的質數有：",m ,n); //output
     
     for (i;i<j;i++) //compution
     {
         k=2;
         if (i>=2)
         {
             for (k;k<=i;k++)
             {
                 if (i==k)
                 {
                     printf("%d ", i); //output
                     break;
                 }
                 else if (i%k!=0)
                 {
                     continue;
                 }
                 else if (i%k==0)
                     break;
             }
         }
         else if (i==1)
             continue;
     }
     
     printf("\n");
     system("pause");
     return 0;
 }
 */
