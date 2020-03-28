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
    int input; //variable
    int input_1=0;
    int input_2=0;
    int input_3=0;
    int total=0;
    
    start: //for switch
    
    printf("請問你要吃什麼：(1)豪華壽司便當 (3)養生菇便當 (3)繽紛炒飯 (-1)結束："); //input
    scanf("%d", &input);
    
    while (input!=1&&input!=2&&input!=3&&input!=-1) //FPD
    {
        printf("您輸入錯誤，請重新輸入\n");
        printf("請問你要吃什麼：(1)豪華壽司便當（2)養生菇便當 (3)繽紛炒飯 (-1)結束：");
        scanf("%d", &input);
    }
    
    switch (input) //compution
    {
        case 1:
            input_1+=1;
            total+=1;
            goto start;
            break;
        case 2:
            input_2+=1;
            total+=1;
            goto start;
            break;
        case 3:
            input_3+=1;
            total+=1;
            goto start;
            break;
        default:
            break;
    }
    
    printf("\n"); //output
    printf("以下是您的便當訂購單：\n");
    printf("共有 %d 人訂餐\n", total);
    printf("共 %d 人訂購豪華壽司便當\n", input_1);
    printf("共 %d 人訂購養生菇便當\n", input_2);
    printf("共 %d 人訂購繽紛炒飯\n", input_3);
    
    system("pause");
    return 0;
}
/* 用do while寫
 
 #include<stdio.h>
 #include<stdlib.h>
 int main(void)
 {
     int input; //variable
     int input_1=0;
     int input_2=0;
     int input_3=0;
     int total=0;
     
     
     do
     {
         printf("請問你要吃什麼：(1)豪華壽司便當 (3)養生菇便當 (3)繽紛炒飯 (-1)結束："); //input
         scanf("%d", &input);
     
         while (input!=1&&input!=2&&input!=3&&input!=-1) //FPD
         {
             printf("您輸入錯誤，請重新輸入\n");
             printf("請問你要吃什麼：(1)豪華壽司便當（2)養生菇便當 (3)繽紛炒飯 (-1)結束：");
             scanf("%d", &input);
         }
     
         switch (input) //compution
         {
             case 1:
                 input_1+=1;
                 total+=1;
                 break;
             case 2:
                 input_2+=1;
                 total+=1;
                 break;
             case 3:
                 input_3+=1;
                 total+=1;
                 break;
             default:
                 break;
         }
     }
     while (input!=-1);
         
     printf("\n"); //output
     printf("以下是您的便當訂購單：\n");
     printf("共有 %d 人訂餐\n", total);
     printf("共 %d 人訂購豪華壽司便當\n", input_1);
     printf("共 %d 人訂購養生菇便當\n", input_2);
     printf("共 %d 人訂購繽紛炒飯\n", input_3);
     
     system("pause");
     return 0;
 }
 */
