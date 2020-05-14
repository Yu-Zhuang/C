//  Created by Yu-Zhuang Lin on 2019/10/2.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void Add();
void Cut();
void Multiply();
void Divid();
int Right=0,Wrong=0,n=0;

int main(void){
    int choise;
    srand(time(NULL));
    printf("|十題遊戲數學|\n");
    while(Right+Wrong!=10){ //遊戲進行10次
        n+=1;
        choise=rand()%4+1; //題目是+-*/是random的
        switch(choise){
            case 1:
                Add();
                break;
            case 2:
                Cut();
                break;
            case 3:
                Multiply();
                break;
            case 4:
                Divid();
                break;
        }
    }
    printf("~您答對了%d題, 錯了%d題~\n",Right,Wrong); //output
    return 0;
}

void Add(void){
    int a,b,ans;
    srand(time(NULL));
    a=rand()%100; //題目數字random
    b=rand()%100;
    
    printf("%d. %d+%d=",n,a,b);
    scanf("%d", &ans);
    if(ans==a+b){
        printf("答對了\n");
        Right+=1;
    }
    else{
        printf("答錯了,答案是%d\n",a+b);
        Wrong+=1;
    }
    return;
}

void Cut(void){
    srand(time(NULL));
    int a,b,ans;
    do{
        a=rand()%100; //題目數字random
        b=rand()%100;
    }while(a<b);
    
    printf("%d. %d-%d=",n,a,b);
    scanf("%d", &ans);
    if(ans==a-b){
        printf("答對了\n");
        Right+=1;
    }
    else{
        printf("答錯了,答案是%d\n",a-b);
        Wrong+=1;
    }
    return;
}

void Multiply(void){
    srand(time(NULL));
    int a,b,ans;
    a=rand()%10; //題目數字random
    b=rand()%10;
    
    printf("%d. %d*%d=",n,a,b);
    scanf("%d", &ans);
    if(ans==a*b){
        printf("答對了\n");
        Right+=1;
    }
    else{
        printf("答錯了,答案是%d\n",a*b);
        Wrong+=1;
    }
    return;
}

void Divid(void){
    srand(time(NULL));
    int a,b,ans;
    do{
        b=rand()%10; //題目數字random
        a=b*(rand()%10);
    }while(a/b==0);
    printf("%d. %d/%d=",n,a,b);
    scanf("%d", &ans);
    if(ans==a/b){
        printf("答對了\n");
        Right+=1;
    }
    else{
        printf("答錯了,答案是%d\n",a/b);
        Wrong+=1;
    }
    return;
}



