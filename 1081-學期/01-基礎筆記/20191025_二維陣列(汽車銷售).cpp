//
//  20191022.cpp
//  20191022
//
//  Created by Yu-Zhuang Lin on 2019/10/22.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//二維陣列練習
#include <stdio.h>
int main (void)
{
    int i;
    int j;
    int sale[2][4]; //二維陣列 儲存 業務員1、2四個季的業績, 陣列名[列][行]
    int sum=0;
    
    for (i=0;i<=3;i++) //input 業務員1的業績
    {
        printf("業務員1的第%d季業績: ", (i+1));
        scanf("%d", &sale[0][i]);
    }
    for (i=0;i<=3;i++) //input 業務員2的業績
    {
        printf("業務員2的第%d季業績: ", (i+1));
        scanf("%d", &sale[1][i]);
    }
    
    printf("+++++OUTPUT+++++\n");
    
    printf("業務員1的業績: "); // output業務員1的業績
    for (j=0;j<=3;j++)
    {
        printf("%d ", sale[0][j]);
    }
    printf("\n");
    
    printf("業務員2的業績: "); // output業務員2的業績
    for (j=0;j<=3;j++)
    {
        printf("%d ", sale[1][j]);
    }
    printf("\n");
    
    for (i=0;i<=1;i++) // output總業績
        for (j=0;j<=3;j++)
        {
            sum+=sale[i][j];
        }
    printf("2019年總銷售量為%d", sum);
    printf("\n");
    
    return 0;
}
