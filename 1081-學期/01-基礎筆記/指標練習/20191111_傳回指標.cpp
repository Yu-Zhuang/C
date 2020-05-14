//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
#include <stdio.h>
int* twosum(int* nums,int target, int Size);
//找出指定target數 由陣列的哪兩個位子的數相加的函數
int main(void){
    int nums[4]={2,1,5,8};
    int target;
    
    scanf("%d",&target);
   
    printf("%d %d\n",*twosum(nums,target,4)\
       ,*(twosum(nums,target,4)+1));
    
    return 0;
}

int* twosum(int* nums,int target, int Size){
    int i,j,temp=1;;
    int ret[2];
    int *ptr;
    for(i=0;i<Size;i++){
        for(j=i+1;j<Size;j++){
            if(nums[i]+nums[j]==target){
                temp=0;
                ret[0]=i;
                ret[1]=j;
                break;
            }
            else
                continue;
        }
        if(temp==0)
            break;
    }
    ptr=ret;
    return ptr;
}
