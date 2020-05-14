//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* sortArray(int* nums, int numsSize, int* returnSize); //sort

int main(){
    int i;
    int ret=10;
    int data[10];
    srand(time(NULL));
    for(i=0;i<10;i++){ //給 陣列 儲存 亂數
        data[i]=rand()%100;
    }
    printf("befor\n");
    for(i=0;i<10;i++){ //印出 排序前
        printf("%d ",data[i]);
    }
    printf("\nafter\n");
    sortArray(data,10,&ret); //sort
    for(i=0;i<10;i++){ //印出 排序後
        printf("%d ",data[i]);
    }
    printf("\n");
    return 0;
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    int i=0,j=numsSize-1;
    int* ret;
    *returnSize=numsSize;
    ret=(int*)malloc(sizeof(int)*numsSize);

    for(i=0;i<numsSize-1;i++){
        for(j=numsSize-1;j>i;j--){
            if(nums[i]>nums[j]){
                nums[i]^=nums[j];
                nums[j]^=nums[i];
                nums[i]^=nums[j];
            }
        }
    }
    ret=nums;
    return ret;
}
