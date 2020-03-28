//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.
//input:一個正整數, output:該數是幾位數
#include<stdio.h>
int main(void){
    long input;
    int i;
    long nine=9,ten=100;
    int output;
    
    scanf("%ld",&input); //input
    
    if(input>0&&input<10){ //input==個位數
        output=1;
        printf("%d\n",output);
    }
        
    else{ //input>個位數
        for(i=2;i<=18;i++){ //至多18位數
            if(input>nine&&input<ten){
                output=i;
                printf("%d\n",output);
                break;
            }
            nine=nine*10+9;
            ten=ten*10;
        }
    }
    
    return 0;
}

//寫成函式 int count(long input);
#include<stdio.h>
int count(long input);
int main(void){
    long input;
    
    scanf("%ld",&input); //input
    
    printf("%d",count(input)); //output
    
    return 0;
}

int count(long input){ //運算input是幾位數
    int i,output=0;
    long nine=9,ten=100;
    
    if(input>0&&input<10){
        output=1;
    }
    else{
        for(i=2;i<=18;i++){
            if(input>nine&&input<ten){
                output=i;
                break;
            }
            nine=nine*10+9;
            ten=ten*10;
        }
    }
    return output;
}
