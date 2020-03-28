//
//  20191019.cpp
//  20191019
//
//  Created by Yu-Zhuang Lin on 2019/10/19.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#define SIZE 4
void show(int arr[]); //宣告一個可傳入整數形態陣列 的函數
int main(void)
{
    int A[SIZE]={5,3,6,1}; //陣列
    printf("陣列的內容: ");
    show(A); //將陣列A(*的位址) 傳入函數
    
    return 0;
}

void show(int arr[]) //一個可傳入整數形態陣列(*的位址) 的函數
{
    int i;
    for (i=0;i<SIZE;i++) //function: 將傳入的陣列內容列印出來
        printf("%d ", arr[i]);
    
    printf("\n");
    return;
}
