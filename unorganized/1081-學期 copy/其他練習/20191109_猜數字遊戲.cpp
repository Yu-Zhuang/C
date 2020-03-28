//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
#include <stdio.h>
int main(void){
    char an[5]="1436";
    char input[5];
    int i,j;
    int A=0,B=0;
    
    do{
        printf("請輸入一四位正整數(各位數不得重複): ");
        scanf("%s",input);
        
        A=0;
        B=0;
        
        for(i=0;i<=3;i++){
            for(j=0;j<=3;j++){
                if(an[i]==input[j]&&i==j)
                    A+=1;
                if(an[i]==input[j]&&i!=j)
                    B+=1;
            }
        }
        printf("%dA%dB\n",A,B);
    }while(A!=4);
    
    printf("you got it!\n");
    return 0;
}

