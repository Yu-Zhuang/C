//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.

//一個整數，加上 100 或加上 168 是一個完全平方數， 請問該數是多少?
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int i;
    int j;
    int k;
    
    for (i=1;i<=1000;i++)
    {
        for (j=1;j<=1000;j++)
        {
           if ((i+100)==j*j)
               for (k=1;k<=1000;k++)
               {
                   if ((i+168)==k*k)
                   {
                       printf("加上 100 或加上 168 是一個完全平方數， 該數是%d\n", i);
                       printf("%d\n", j);
                       printf("%d", k);
                   }
                   else
                       continue;
               }
            else
                continue;
        }
    }

    
    printf("\n");
    system("pause");
    return 0;
}

//一個整數，它加上 100 後是一個完全平方數，再加上 168 又是一個完全平方數， 請問該數是多少?
/*
 
 //一個整數，它加上 100 後是一個完全平方數，再加上 168 又是一個完全平方數， 請問該數是多少?
 #include <stdio.h>
 #include <stdlib.h>
 int main(void)
 {
     int i;
     int j;
     int k;
     
     for (i=1;i<=1000;i++)
     {
         for (j=1;j<=1000;j++)
         {
            if ((i+100)==j*j)
                for (k=1;k<=1000;k++)
                {
                    if ((i+268)==k*k)
                    {
                        printf("加上 100 後是一個完全平方數，再加上 168 又是一個完全平方數%d\n", i);
                        printf("%d\n", j);
                        printf("%d\n", k);
                    }
                    else
                        continue;
                }
             else
                 continue;
         }
     }

     
     printf("\n");
     system("pause");
     return 0;
 }
 */


/*該提的解答
 #include <stdio.h>
 #include <math.h>
 int main(void)
 {
 long int i,x,y,z;
     
 for (i=1;i<100000;i++)
     {
         x=sqrt(i+100);
         y=sqrt(i+268);
         if(x*x==i+100&&y*y==i+268)
             printf("\n%ld\n",i);
     }

 }*/
