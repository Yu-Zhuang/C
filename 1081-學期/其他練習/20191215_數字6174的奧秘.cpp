//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.

#include<stdio.h>
#include<stdlib.h>
#define SIZE 4
int Big(int);
int Small(int);
void bubble(int a[]);
int main(void){
    int input,c=0;
    int flag=0;
    do{
        printf("請輸入一個四位數:");
        scanf("%d", &input);
        flag=input;
        while(flag!=6174){
            printf("big is: %d\n", Big(flag));
            printf("small is: %d\n", Small(flag));
            flag=Big(flag)-Small(flag);
            printf("big - small = %d\n",flag);
            printf("========\n");
        }
            printf("繼續請按1,結束請按0:");
            scanf("%d",&c);
    }while(c==1);
    return 0;
}

int Big(int num){
    int nums[4];
    nums[0]=num/1000;
    num=num-nums[0]*1000;
    nums[1]=num/100;
    num=num-nums[1]*100;
    nums[2]=num/10;
    nums[3]=num%10;
    bubble(nums);
    return nums[3]*1000+nums[2]*100+nums[1]*10+nums[0];
}

int Small(int num){
    int nums[4];
    nums[0]=num/1000;
    num=num-nums[0]*1000;
    nums[1]=num/100;
    num=num-nums[1]*100;
    nums[2]=num/10;
    nums[3]=num%10;
    bubble(nums);
    return nums[0]*1000+nums[1]*100+nums[2]*10+nums[3];
}
void bubble(int a[]){
    int i, j, temp;
     for (i=0;i<SIZE;i++)
         for (j=0;j<(SIZE-1);j++){
            if (a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
         }
}
