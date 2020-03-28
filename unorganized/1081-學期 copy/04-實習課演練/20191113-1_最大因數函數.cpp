//  Created by Yu-Zhuang Lin on 2019/10/2.
//寫一個找出最大公因數的function
#include<stdio.h>
int gcd(int num1, int num2);
int main(void){
    int input_1,input_2;
    char temp;
    
    start:
    printf("請輸入一正整數: ");//input
    scanf("%d",&input_1);
    while(input_1<0){ //FPD
        printf("輸入錯誤 請重新輸入\n");
        printf("請輸入一正整數: ");
        scanf("%d",&input_1);
    }
    
    printf("請輸入另一正整數: ");//input
    scanf("%d",&input_2);
    while(input_2<0){//FPD
        printf("輸入錯誤 請重新輸入\n");
        printf("請輸入另一正整數: ");
        scanf("%d",&input_2);
    }
    
    printf("%d\n",gcd(input_1, input_2)); //output
    
    printf("繼續請按y,其他鍵結束: "); //end or not
    getchar();
    scanf("%c",&temp);
    if(temp=='y')
        goto start;
    
    return 0;
}

int gcd(int num1, int num2){ //找最大公因數
    int i;
    int ans;
    int max;
    
    if(num1<num2) //選最小的當作max
        max=num1;
    else
        max=num2;
    
    for(i=1;i<max;i++){ //1~max依序判斷
        if(num1%i==0&&num2%i==0){ //是公因數就指派給變數ans
            ans=i;
        }
    }
    return ans; //output
}
