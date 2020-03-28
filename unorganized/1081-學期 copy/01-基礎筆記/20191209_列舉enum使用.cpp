//  Created by Yu-Zhuang Lin on 2019/10/2.
========================================================
#include<stdio.h>
#include<stdlib.h>
enum color{ //enum 可增加程式可讀性
    red, //預設值為0
    green, //1
    blue  //2
}shirt; //shirt是變數. red,green,blue是變數中可以使用的值
//enum 像自定義的型別(ex: int), 裡面的東西如值(ex: -1200 ~ +1200);
int main(){
    printf("sizeof(shirt)=%d\n", sizeof(shirt));
    printf("red=%d\n",red);
    printf("green=%d\n", green);
    printf("blue=%d\n",blue);
    shirt=green; //用法
    if(shirt==green) //用法
        printf("shirt is green\n");
    else if(shirt==red)
        printf("shirt is red\n");
    else
        printf("shirt is blue\n");
    
    return 0;
}
/*output:
 
 sizeof(shirt)=4
 red=0
 green=1
 blue=2
 shirt is green
 
 */

