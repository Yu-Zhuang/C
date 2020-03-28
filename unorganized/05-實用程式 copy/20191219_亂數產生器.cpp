//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//input year.month.date;
//output Date today;
#include<stdio.h>
#include<stdlib.h>
typedef struct data{
    int year;
    int month;
    int date;
}Date;
int Today(Date);
int main(void){ //main
    Date input;
    
    printf("年: "); // input
    scanf("%d", &input.year);
    printf("月: ");
    scanf("%d", &input.month);
    printf("日: ");
    scanf("%d", &input.date);
    printf("今天星期: ");
    
    printf("%d\n", Today(input)); //output
    return 0;
}

int Today(Date input){ //function
    int ret=0;
    int i,year=2000,date=6,one=0;
    int day_0[12]={0,31,59,90,120,151,181,212,243,273,304,334};
    
    // 1.1 of the year = ?date
    if(input.year>=year){
        for(i=year;i<input.year;i++){
            if((i%4==0&&i%100!=0)||(i%400==0)){
                one+=2;
            }
            else{
                one+=1;
            }
        }
        one=(one%7+date)%7;
    }
    else{ //input<2000;
        for(i=year-1;i>=input.year;i--){
            if((i%4==0&&i%100!=0)||(i%400==0)){
                one+=2;
            }
            else{
                one+=1;
            }
        }
        one=date-one%7;
    }
    
    // m.d=?date
    if((input.year%4==0&&input.year%100!=0)||input.year%400==0){ //month 2 = 29
        if(input.month>=3){
            ret=((day_0[input.month-1]+input.date+1)%7+one-1)%7;
        }
        else
            ret=((day_0[input.month-1]+input.date)%7+one-1)%7;
    }
    else { //month 2 = 28
        ret=((day_0[input.month-1]+input.date)%7+one-1)%7;
    }
        
    return ret;
}
