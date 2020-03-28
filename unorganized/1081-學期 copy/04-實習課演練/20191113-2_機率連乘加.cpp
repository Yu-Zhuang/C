//  Created by Yu-Zhuang Lin on 2019/10/2.
#include<stdio.h>
#include<math.h>

float Cride(float nums1[5]);
float Lride(float nums2[5]);
float cosin_1(float num3[4]);

int main(void){
    float input1[5];
    float input2[5];
    float input3[4];
    int i,s; // s 用來判斷要run哪個function
    char se; // s 用來判斷繼續與否
    
    start: //end or not
    
    printf("1.計算5個機率乘積\n2.計算5個機率log10相加\n3.計算兩個向量夾角cosine\n");
    printf("輸入選單: "); //input 要選擇哪個funtion
    scanf("%d", &s);
    while(s!=2&&s!=1&&s!=3){
        printf("輸入錯誤請重新輸入:");
        scanf("%d", &s);
    }
    
    if(s==1){ //run 連加函數
        printf("請依序輸入5個機率:\n");
        for(i=0;i<5;i++){
            scanf("%f",&input1[i]); //input 要連加的數
            while(input1[i]<0){ //FPD
                printf("輸入錯誤 請重新輸入:");
                scanf("%f",&input1[i]);
            }
        }
        printf("%f\n", Cride(input1)); //output
    }
    
    else if(s==2){ //run連乘log10函數
        printf("請依序輸入5個機率:\n");
        for(i=0;i<5;i++){
            scanf("%f",&input2[i]); //input 要運算的數
            while(input2[i]<0){ //FPD
                printf("輸入錯誤 請重新輸入:");
                scanf("%f",&input2[i]);
            }
        }
        printf("%f\n",Lride(input2));
    }
    else if(s==3){ //run 運算兩數cosine function
        printf("請依序輸入向量(x1,y1,x2,y2):\n");
        for(i=0;i<4;i++){
                scanf("%f",&input3[i]);
            }
        printf("%f\n",cosin_1(input3)); //output
    }
    
    printf("繼續請按y,其他鍵離開: "); //end or not
    getchar();
    scanf("%c",&se);
    if(se=='y')
        goto start;
    
    return 0;
}

float Cride(float nums1[5]){ //連乘函數
    int i;
    float ans=1;
    for(i=0;i<5;i++){
        ans=ans*nums1[i];
    }
    return ans;
}

float Lride(float nums2[5]){  //連加log10函數
    int i;
    float ans=0;
    for(i=0;i<5;i++){
        ans+=log10(nums2[i]);
    }
    return ans;
}

float cosin_1(float num3[4]){ //找出兩向量cosine
    float m,n;
    float ans;
    int i;

    m=num3[0]*num3[2]+num3[1]*num3[3];
    n=sqrt(num3[0]*num3[0]+num3[1]*num3[1])*\
        sqrt(num3[2]*num3[2]+num3[3]*num3[3]);
    
    ans=m/n;
    return ans;
}

