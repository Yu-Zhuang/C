//
//  20191019.cpp
//  20191019
//
//  Created by Yu-Zhuang Lin on 2019/10/19.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#define SIZE 5
void show(int a[]), bubble(int a[]);
int main(void) //主程式
{
    int data[SIZE]={26,5,81,7,63}; //宣告函數data
    
    printf("排序前: \n");
    show(data); //印出氣泡排序前 陣列
    
    bubble(data); //將函數傳入 氣泡排序 函數
    
    printf("氣泡排序後: \n");
    show(data); //印出 排序後 陣列
    
    return 0;
}

void show(int a[]) //列印出陣列的函數
{
    int i;
    for (i=0;i<SIZE;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return;
}

void bubble(int a[]) //氣泡排序法的函數
{
    int m, n;
    int i;
    int count=SIZE;
    
    while (count>0){
        for (i=0;i<SIZE;i++){
            if (a[i]>a[i+1]){
                m=a[i];
                n=a[i+1];
                a[i]=n;
                a[i+1]=m;
            }
        }
        count-=1;
    }
    return;
}

/* 範例給的 氣泡排序函數 寫法
 void bubble(int a[]) //氣泡排序法的函數
 {
    int i, j, temp;
     
     for (i=0;i<SIZE;i++)
        for (j=0;j<(SIZE-1);j++)
            if (a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }


     return;
 }
 */
