//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//找出一數的A0 (例: 1234+123+12+1=1370 則 1234 便是 1370 的 A0 )
#include <stdio.h>
int main(void){
    int input, i, temp=0; //variable
    
    do{ //執行到input==0;
        printf("請輸入一個小於9999的正整數: "); //input
        scanf("%d",&input);

        while(input<0){ //FPD
            printf("請重新輸入: ");
            scanf("%d", &input);
        }

        for(i=0;i<=9999;i++){ //conpution and output
            if ((i+i/10+i/100+i/1000)==input){
                temp+=1;
                printf("%d\n",i);
                break;
            }
            else
                continue;
        }

        if (temp==0)
            printf("-1\n"); //都沒有該數的A0則輸出-1;
    }
    
    while(input!=0);//執行到input==0;
    
    
    return 0;
}
