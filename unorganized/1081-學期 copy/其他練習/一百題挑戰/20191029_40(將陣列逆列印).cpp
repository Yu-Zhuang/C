//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:題目:將一個陣列逆序輸出。
#include <stdio.h>
void output(int n[]);
void revop(int n[]); //陣列 逆著 印出的 函數
int main(void){
    int num[15]={1,2,3,4,6,7,8,9};
    int i,j;
    int temp;
    int flag=1;
    int count=0;
    
    printf("請輸入1~9的數字: ");
    scanf("%d", &num[8]);
    
    for (i=0;i<=7&&(flag);i++){
        flag=0;
        count+=1;
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
    
    output(num);
    revop(num); //output 陣列 逆著 印出
    
    printf("\n結束\n");
    return 0;
}

void output(int n[]){
    int i;
    
    for (i=0;i<=8;i++){
        printf("%d ", n[i]);
    }
    printf("\n");
    return;
}

void revop(int n []){ //陣列 逆著 印出的 函數
    int i;
    for(i=0;i<=8;i++){
        printf("%d ",n[(i*-1)+8]);
    }
    printf("\n");
    return;
}
