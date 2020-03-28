//  Created by Yu-Zhuang Lin on 2019/10/2.
//題目:射箭計分
#include <stdio.h>
int main(void){
    int i,j; //for loop
    int m; //variable for 組數的input
    double x[1000]; //儲存各組x軸座標值的input
    double y[1000]; //儲存各組y軸座標值的input
    double lenth; // lenth=a*a+b*b (直角三角型斜邊公式 斜邊c*c = a*a+b*b
    int count=0; //用來儲存輸出各組的分數
    
    printf("有幾組測試資料："); //input 共有幾筆基料
    scanf("%d", &m);
    
    while(m<1){ //FPD
        printf("輸入錯誤，請重新輸入\n");
        printf("有幾組測試資料：");
        scanf("%d", &m);
    }
    
    for(i=0;i<m;i++){ //input 每一組資料的x,y座標
        printf("請輸入%d號的x座標: ",i+1);
        scanf("%lf", &x[i]);
        printf("請輸入%d號的y座標: ",i+1);
        scanf("%lf", &y[i]);
    }
    
    printf("\n分數統計:\n");
    for(i=0;i<m;i++){ //conpution and output
        count=0; //每輸出一組成績後 將分數歸零
        lenth=(x[i]-10)*(x[i]-10)+(y[i]-10)*(y[i]-10); //算出 三角形 c*c=a*a+b*b 中的 a*a+b*b
        
        for(j=1;j<=10;j++){
            if (lenth<=j*j){ // 判斷 c*c <=> a*a+b*b
                count+=11-j; //並進行各組 分數統計
                break;
            }
        }
        printf("%d號的分數是%d\n",i+1,count); //output出分數
    }
    
    printf("\n結束\n");
    return 0;
}
