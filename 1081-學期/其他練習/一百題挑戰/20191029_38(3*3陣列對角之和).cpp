//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:求一個 3*3 矩陣對角線元素之和
#include <stdio.h>
void pnums(int n[][3]); //output3*3陣列的函數
int main(void){
    int num[3][3]={{1,2,3},{4,5,6},{7,8,9}}; //3*3陣列
    int i,j;
    int sum1=0,sum2=0;
    int count=0;
    
    pnums(num); //output 3*3陣列
    
    for(i=0;i<=2;i++) //conpution
        for(j=0;j<=2;j++){
            count+=1;
            if(count==1||count==5||count==9)
                sum1+=num[i][j];
            if(count==3||count==5||count==7)
                sum2+=num[i][j];
        }
    
    printf("%d\n", sum1); //output 對角和
    printf("%d\n", sum2);
    
    printf("\n結束\n");
    return 0;
}

void pnums(int n[][3]){ //output3*3陣列的函數
    int i,j;

    for(i=0;i<=2;i++){
        for(j=0;j<=2;j++){
            printf("%d ", n[i][j]);
        }
        printf("\n");
    }
    return;
}
