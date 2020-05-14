//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//寫一個function: input今天日期 ; output今天星期幾 (非閏年).
//  1/1日是 星期二
#include<stdio.h>
int toDay(int*);
int main(void){
    int date[2];
    int i;
    for(i=0;i<2;i++){
        scanf("%d",&date[i]);
    }
    printf("這天是禮拜%d\n", toDay(date));
    return 0;
}
int toDay(int* ptr){
    int days[12]={0,31,59,90,120,151,181,212,243,273,304,334};
    return (days[ptr[0]-1]+ptr[1])%7+1;
}


/*之前寫法
 int toDay(int* ptr){
     int output;
     int day=0;
     int days[12]={0,31,59,90,120,151,181,212,243,273,304,334};
         
     day=days[ptr[0]-1];
     output=(day+ptr[1])%7+1;
     
     return output;
 }
 //
 int toDay(int* ptr){
     int i,output;
     int day=0;
     int days[12]={0,31,59,90,120,151,181,212,243,273,304,334};
     
     for(i=0;i<12;i++){
         if(i==ptr[0]-1)
             day=days[i];
     }
     for(i=0;i<7;i++){
         if((day+ptr[1])%7==i){
             output=i+1;
             break;
         }
     }
     return output;
 }
 */

