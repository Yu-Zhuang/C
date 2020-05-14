//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
#include <stdio.h>
//將陣列 指定位置 換為 指定數 的程式
int* replace(int* nums,int posi,int chnm); //該函數
int main(void){
    int nums[4]={2,1,5,8};
    int target;
    int changenum;
    int i;
    
    scanf("%d",&target); //input 指定位置
    scanf("%d",&changenum); //input 指定數字
    
    for(i=0;i<4;i++){ //output 更換後陣列結果
        printf("%d ",*(replace(nums,target,changenum)+i));
    }

    printf("\n");
    return 0;
}

int* replace(int* nums,int posi,int chnm){//該函數
    int* ptr;
    *(nums+posi-1)=chnm;
    ptr=nums;
    return ptr;
}
