//
//  20191019.cpp
//  20191019
//
//  Created by Yu-Zhuang Lin on 2019/10/19.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#define ROW 4
#define COL 3
void search(int a[][COL], int b[]); //可傳遞二維陣列的函數的a[][一定要有數]
int main (void)
{
    int a[ROW][COL]={{26,5,7},{10,3,47},{6,76,8},{40,4,32}}; //宣告二維陣列
    int i,j,b[2];
    
    printf("二維陣列內的元素: \n"); //列印出二維陣列內容
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COL;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    
    search(a, b); //將二維陣列a 與一維陣列b 傳到search函數
    
    printf("陣列中最大的數為%d\n", b[0]); // ouput
    printf("陣列中最小的數為%d\n", b[1]);
    
    return 0;
}

//能找出二維陣列a 最大最小數 並將結果指派給b一維陣列 的函數 search
void search(int a[][COL], int b[])
{
    int i, j;
    
    b[0]=a[0][0];
    b[1]=a[0][0];
    
    for (i=0;i<ROW;i++)
        for (j=0;j<COL;j++)
        {
            if (a[i][j]>b[0]&&a[i][j]>a[i][j+1])
                b[0]=a[i][j]; //將最大值指派給b[0]
            if (a[i][j]<b[1]&&a[i][j]<a[i][j+1])
                b[1]=a[i][j]; //將最小值指派給b[1]
        }
    return;
}
