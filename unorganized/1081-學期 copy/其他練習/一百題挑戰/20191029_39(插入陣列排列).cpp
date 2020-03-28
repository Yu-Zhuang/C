//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:有一個已經排好序的陣列。現輸入一個數，要求按原來的規律將它插入陣列中
#include <stdio.h>
void output(int n[]); //output 函數: 印出陣列
int main(void){
    int num[15]={1,2,3,4,6,7,8,9}; //有排序的陣列
    int i,j;
    int temp;
    int flag=1; //用來控制外層迴圈
    
    printf("請輸入1~9的數字: "); // input
    scanf("%d", &num[8]);
    
    for (i=0;i<=7&&(flag);i++){ //conpution
        flag=0;
        for(j=0;j<=7;j++){
            temp=num[j];
            if (temp>num[j+1]){
                num[j]=num[j+1];
                num[j+1]=temp;
                flag=1;
            }
            else
                continue;
        }
    }
    
    output(num); //output
    
    printf("\n結束\n");
    return 0;
}

void output(int n[]){ //output 函數: 印出陣列
    int i;
    
    for (i=0;i<=8;i++){
        printf("%d ", n[i]);
    }
    return;
}
