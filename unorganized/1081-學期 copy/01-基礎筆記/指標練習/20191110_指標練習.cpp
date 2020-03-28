//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//練習一
#include <stdio.h>
int main(void){
    int* pot;
    int input;
    
    scanf("%d",&input);
    pot=&input;
    printf("%d\n", *pot);
    *pot+=5;
    printf("%d %d\n",*pot,input);
    return 0;
}
/*
 input:5
 output:
 5
 5
 10
 */
//練習二: 指向陣列的指標
#include <stdio.h>
int main(void){
    int* pot;
    int input[3]={3,6,8};
    int i;
    
    pot=input;
    
    for(i=0;i<3;i++){
        printf("%d %d\n", *(pot+i),input[i]);
    }

    return 0;
}
/*
 output:
 3 3
 6 6
 8 8
 // *(pot+i)==pot[i];
所以亦可寫:
     for(i=0;i<3;i++){
         printf("%d %d\n", pot[i],input[i]);
     }
 */

//練習三:陣列指標傳入函數(leetcode題目)
//nums[i]形式改寫成*(nums+i)   ((一樣可以跑))
#include <stdio.h>
int singleNumber(int* , int);
int main(void){
    int input[5]={6,8,7,6,8};
    int ans;
    ans=singleNumber(input,5);
    printf("%d\n",ans);
    
    return 0;
}

int singleNumber(int* nums, int numsSize){
    int i,j;
    int temp=0;
    int con;
    
    for(i=0;i<numsSize;i++){
        temp=0;
        for(j=0;j<numsSize;j++){
            con=nums[i];
            if(nums[i]==nums[j]){
                temp+=1;
            }
        }
        if (temp<2)
            break;
    }
    return con;
}
/*
 output:
 7
 */

//
