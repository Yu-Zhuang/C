//
//  20191006.cpp
//  20191002
//
//  Created by Yu-Zhuang Lin on 2019/10/6.
//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i=0;
    int sum=0;//宣告變數
    
    while (i<=9) //while 迴圈 (條件判斷)
    {
        i+=1;
        sum+=i;
    }
    
    printf("1+2+3...+10=%d\n", sum);//輸出
    
    system("pause");
    return 0;
}

/*   以下至do while迴圈的使用
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int i=0;
    int sum=0;//宣告變數
    
    do          //do while 迴圈結構 會先執行do 在進行判斷
    {
        i+=1;
        sum+=i;
    }
    while (i<=9);
 
    
    printf("1+2+3...+10=%d\n", sum);//輸出
    
    system("pause");
    return 0;
}
*/
