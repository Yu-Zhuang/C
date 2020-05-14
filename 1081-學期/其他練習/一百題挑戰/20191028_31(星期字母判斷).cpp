//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:請輸入星期幾的第一個字母來判斷一下是星期幾，如果第一個字母一樣，則繼續 判斷第二個字母。
#include <stdio.h>
int main(void){
    char day[1];
    
    printf("請輸入星期第一個字母(需大寫,四是H,六是A): "); //input
    gets(day);
    
    while(day[0]!='S'&&day[0]!='M'&&day[0]!='T'&&day[0]!='W'\ //FPD
          &&day[0]!='H'&&day[0]!='F'&&day[0]!='A'){
        printf("輸入錯誤!請重新輸入\n");
        printf("請輸入星期第一個字母(需大寫,四是H,六是A): ");
        gets(day);
    }
    
    switch (day[0]){ //conpution and ouput
        case 'S':
            printf("星期天\n");
            break;
        case 'M':
            printf("星期一\n");
            break;
        case 'T':
            printf("星期二\n");
            break;
        case 'W':
            printf("星期三\n");
            break;
        case 'H':
            printf("星期四\n");
            break;
        case 'F':
            printf("星期五\n");
            break;
        case 'A':
            printf("星期六\n");
            break;
    }
    
    return 0;
}
