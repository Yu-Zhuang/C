//  Created by Yu-Zhuang Lin on 2019/10/2.
========================================================
//開啟 並 讀取檔案
#include<stdio.h>
#include<stdlib.h>
int main(void){
    FILE *fptr; //指向檔案的指標
    char ch; //接收讀取字元
    int count=0;
    
    fptr=fopen("/Users/yuzhuanglin/Desktop/main.cpp","r"); // fopen("檔案位址","動作")
    if(fptr!=NULL){ //開啟成功
        while((ch=getc(fptr))!=EOF){ //讀取到檔尾
            printf("%c",ch); //一次印出一個字元
            count++; //計算字數
        }
        fclose(fptr); //關閉開啟的檔案
        printf("\nthere have %d char.\n",count);
    }
    else //開啟失敗
        printf("fail to open\n");
    
    return 0;
}

//

