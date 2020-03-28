//  Created by Yu-Zhuang Lin on 2019/10/2.
#include<stdio.h>
#include<stdlib.h>
int main(void){ //結構i
    struct date{
        int month;
        int day;
    };
    
    struct data{ //結構ii
        char name[10];
        int math;
        struct date birthday; //巢狀結構
    }s1={"john",74,{10,16}}; //給定初值
    
    printf("學生姓名: %s\n",s1.name); //output
    printf("生日%d月%d日\n",s1.birthday.month,s1.birthday.day);
    printf("數學成績: %d\n",s1.math);
    
    return 0;
}

//應用: 鏈結串列 (資料結構)
#include<stdio.h>
int main(void){
    struct data{
        int grade;
        char name[10];
        struct data* next;
    }student;
    
    scanf("%d", &student.next->grade);
    scanf(" %[^\n]", student.next->name);
    printf("grade of \"%s\" is: %d\n", student.next->name, student.next->grade);
    
    scanf("%d", &student.next->next->grade);
    scanf(" %[^\n]", student.next->next->name);
    printf("grade of \"%s\" is: %d\n", student.next->next->name,student.next->next->grade);
    
    return 0;
}
