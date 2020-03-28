#include<stdio.h>
#include<stdlib.h>

int findP(char*, int);

int main(void){
    int times=0,len=0;
    
    scanf("%d", &times);
    
    for(int i=0;i<times;i++){
        scanf("%d", &len);
        char nums[len*2];
        getchar();
        scanf("%[^\n]", nums);
        printf("%d\n",findP(nums,len*2-1));
    }
  
    return 0;
}

int findP(char *nums, int numsSize){
    int i=0, max=0, sum=1,tmp=nums[0];
    for(i=1;i<numsSize;i++){
        if(nums[i]==' ') continue;
        else if(nums[i]==tmp) sum++;
        else if(nums[i]!=tmp) {sum=1;tmp=nums[i];}
        if(sum>max) max=sum;
    }
    return max;
}
/*
 題目：Q_1.jpg;
 */
