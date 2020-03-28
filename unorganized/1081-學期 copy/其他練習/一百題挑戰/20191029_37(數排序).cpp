//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:對 10 個數進行排序
#include <stdio.h>
void bubble(int nums[]); //氣泡排序 函數
void pnums(int nums[]); //印出一維陣列 函數
int main(void){
    int num[10]; //將數input至此陣列
    int i;
    
    printf("排序程式，請依序輸入10個數\n");
    
    for (i=0;i<=9;i++){             //input
        printf("請輸入第%d個數: ", i+1);
        scanf("%d",&num[i]);
    }
    
    printf("未排序前數列:\n");
    pnums(num); // ouput 排序前陣列
    
    bubble(num); // compution 將陣列 傳至 排序函數
    
    printf("\n排序後數列(小到大):\n");
    pnums(num); // ouput 排序後陣列
    
    printf("\n結束\n");
    return 0;
}

void bubble(int nums[]){ // 氣泡排序函數 由小到大
    int i,j;
    int temp;
    
    for (i=0;i<=8;i++)
        for (j=0;j<=8;j++){
            temp=nums[j];
            if (temp>nums[j+1]){
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    return;
}

void pnums(int nums[]){ //印出 一維陣列 函數
    int i;
    for (i=0;i<=9;i++){
        printf("%d ", nums[i]);
    }
    return;
}
