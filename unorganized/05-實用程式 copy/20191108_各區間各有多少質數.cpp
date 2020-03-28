//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//
#include <stdio.h>
#include <math.h>
int main(void){
    long i,j;
    long begin,end;
    long count,sum=0;
    long temp=100;
    long add;
    
    printf("請輸入初始值: ");
    scanf("%ld", &begin);//開始值
    printf("請輸入終止值: ");
    scanf("%ld", &end);//結束(最大)值
    
    count=begin;
    add=begin;
    
    for(i=begin;i<=end;i++){ //查找質數
        for(j=2;j<=i;j++){
            if(i==j){
                sum+=1; //質數統計
                break;
            }
            else if(i%j!=0)
                continue;
            else if(i%j==0)
                break;
        }
        count+=1;
        if(count%temp==0) //每執行100個數就執行
        {
            printf("%ld到%ld中有%ld個質數\n",add,count,sum);
            add+=100;
            sum=0; //每執行100個數 質數歸零 重新統計
        }
    }
    return 0;
}
