//  Created by Yu-Zhuang Lin on 2019/10/2.
//指標: 基本
#include <stdio.h>
int main(void){
    int *ptr; //宣告指標：指標指向的型態 *指標名
    int num=20;
    
    ptr=&num; //將指標指向變數num的位址: 指標名=&變數名  /*或是在宣告市時: int *ptr=&num; */
    
    printf("num=%d, &num=%p\n",num,&num);
    printf("*ptr=%d, &num=%p, &ptr=%p\n", *ptr, ptr, &ptr);//指標輸出:printf("%型態",*指標名);
/*printf("%p, %p, %p, %d, %d"  &變數, &指標, 指標, 變數, *指標); 印出 變數位址, 指標位址, 指標指向位址, 變數值, 指標指向位址的值.*/
    printf("end\n"); //end
    return 0;
}

//指標：傳遞 指標 到 函數 裡
#include <stdio.h>
void address(int *); //宣告可傳入指標的函數: 型態 函數名 (型態 *);
int main(void){
    int num=20;
    int *ptr=&num;
    
    address(&num); //傳入變數 函數名(&變數名);
    address(ptr); //傳入指標 函數名(指標名);

    
    printf("end\n"); //end
    return 0;
}

void address (int *p1){
    printf("於位址%p內, 儲存的變數內容為%d\n",p1,*p1);
    return;
}

//應用I 交換a, b: 傳遞 指標 到 函數 裡
#include <stdio.h>
void swap_1 (int, int); //函數I
void swap_2 (int *, int *); //函數II
int main(void){
    int a=5, b=20;
    
    printf("交換前\n");
    printf("a=%d, b=%d\n", a, b); // ouput: a=5; b=20
    
    swap_1(a, b); //函數I
    printf("swap_1交換後\n");
    printf("a=%d, b=%d\n", a, b); //output: a=5; b=20
    
    swap_2(&a, &b); //函數II
    printf("swap_2交換後\n");
    printf("a=%d, b=%d\n", a, b); //output: a=20; b=5
    
    return 0;
}
void swap_1 (int a, int b){ //函數I：變數a與b數值交換 的有效區只在函數I裡面 不會到main
    int temp;
    temp=a;
    a=b;
    b=temp;
    return;
}
void swap_2 (int *a, int *b){ //函數II: 變數a與b的位址互換 有效區會到main
    int *temp;
    *temp=*a;
    *a=*b;
    *b=*temp;
    return;
}

//由函數傳回指標
#include <stdio.h>
int* max(int *, int *); //引數 可為兩個指向整數的指標 or兩個指數的位址; 傳回值為 指向整數的指標 or 整數的位址
int main(void){
    int a=12,b=17,*ptr;
    ptr=max(&a,&b);
    printf("max=%d\n", *ptr);
    
    return 0;
}

int *max(int *p1, int *p2){
    if (*p1>*p2)
        return p1;
    else
        return p2;
}

//realloc 用法
//指標變數=(型別*)realloc(指標變數, sizeof(型別)*新大小);
ret=(int*)realloc(ret,sizeof(int)*count);





