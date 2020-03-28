//  Created by Yu-Zhuang Lin on 2019/10/2.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void answer(int*);
int hilo(int, int);

int main(void){
    int ans=0,input=0,count=0;
    answer(&ans); //給定答案
    printf("~猜數字遊戲~\n請猜:");
    scanf("%d", &input); //input
    while(hilo(input,ans)<=0&&count!=20){//猜對或猜20次以上跳出
        count+=1; //統計猜幾次
        if(hilo(input,ans)==0){
            printf("Too high\n");
        }
        else if(hilo(input,ans)==-1){
            printf("Too low\n");
        }
        printf("再猜一次:");
        scanf("%d", &input);
    }
    if(hilo(input,ans)>=0) //猜對的話
        printf("答對了! 您共猜了%d次\n",count);
    else //猜錯的話
        printf("+Game over+\n");
    
    return 0;
}

void answer(int* num){ //隨機方式給定答案
    srand(time(NULL));
    *num=rand()%1000; //答案range在0~999間
    return;
}

int hilo(int number, int ref){ //判別
    static int count=1;
    if(number>ref){ //大於的話 回傳0
        count+=1;
        return 0;
    }
    else if(number<ref){ //小於的話 回傳0
        count+=1;
        return -1;
    }
    return 2; //等於的話 回傳2
}
