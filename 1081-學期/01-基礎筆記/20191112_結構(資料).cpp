//  Created by Yu-Zhuang Lin on 2019/10/2.
//結構(資料): struct data

#include <stdio.h>
int main(void){
    
    struct data{ //結構資料 (data是結構名稱
        char name[10];
        int math;
    }student;//student是結構變數 (設初值: student={"John",80};)
    
    gets(student.name); //input
    scanf("%d",&student.math);
    
    printf("%s %d\n",student.name,student.math); //output
    
    return 0;
}
//+可將struct當作一種自訂資料型態+
//宣告變數時: struct 結構名稱 結構變數1,結構變數2;
// struct data student1, student2;
//給定出初始值: struct data student1={"John",80};
