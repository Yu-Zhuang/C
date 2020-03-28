//
//  106711129-3-2.cpp
//  
//
//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:兩個乒乓球隊進行比賽，各出三人。甲隊為 a,b,c 三人，乙隊為 x,y,z 三人。已 抽籤決定比賽名單。有人向隊員打聽比賽的名單。a 說他不和 x 比，c 說他不和 x,z 比， 請編程式找出三隊賽手的名單。
#include <stdio.h>
int main (void)
{
    char i, j, k; //variable
    
    for (i='x';i<='z';i++) //for a
    {
        for (j='x';j<='z';j++) //for b
        {
            for (k='x'; k<='z';k++) //for c
            {
                if (i=='x') //a not with x
                    continue;
                else if (k=='x'||k=='z') //c not with x and z
                    continue;
                if (i==j||i==k||j==k) //not z,z,y or x, y, x ...
                    continue;
                printf("(a, b, c)分別對上: (%c, %c, %c)", i, j, k); //output
            }
        }
    }
    
    printf("\n"); //end
    return 0;
}
