//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct ident{
    char str[2];
    int nums[9];
}IdenNum;

int seq[26]={10,11,12,13,14,15,16,17,34,18,19,20,21,22,
    35,23,24,25,26,27,28,29,32,30,31,33}; //字母序號

void NumCode(int s);

int main(void){ //main
    srand(time(NULL));
    int input=0,n; //性別
    int flag=1;
    printf("+身分證字號產生器+\n");
    while(flag){
        printf("請輸入性別(男1,女2): ");
        scanf("%d",&input);
        printf("要產生幾個: ");
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            printf("第%d組: ",i+1);
            NumCode(input);
        }
        printf("繼續輸入1, 結束輸入0: ");
        scanf("%d", &flag);
        printf("\n");
    }
    return 0;
}

void NumCode(int s){ //input 性別
    IdenNum x;
    int from,from_n;
    from=rand()%26+65; //開頭字母65~90
    x.str[0]=from;
    from_n=from-65; //帶入seq
    
    x.nums[0]=s; //性別元
    
    int i,check_1=0, check_2,j=7;
    for(i=1;i<8;i++){
        x.nums[i]=rand()%10;
        check_1+=(x.nums[i]*j);
        j--;
    }
    check_1+=x.nums[0]*8;
    
    check_2=seq[from_n];
    int tmp=check_2;
    check_2=(tmp%10)*9+(tmp/10);
    
    x.nums[8]=(10-((check_1+check_2)%10))%10;
    
    printf("%c",x.str[0]); //output
    for(i=0;i<9;i++){
        printf("%d",x.nums[i]);
    }
    printf("\n");
}

