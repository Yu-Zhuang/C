//  Copyright © 2019 Yu-Zhuang Lin. All rights reserved.

#include<stdio.h>
#include<stdlib.h>
typedef struct list{ //宣告定義NODE
    int data;
    struct list *next;
}NODE;
int main(void){
    NODE *first,*current,*previous,*List;
    int i,nums[5]={1,3,4,6,8};
    
    for(i=0;i<5;i++){ //建立鏈結串列
        current=(NODE*)malloc(sizeof(NODE));
        current->data=nums[i];
        if(i==0)
            first=current;
        else
            previous->next=current;
        current->next=NULL;
        previous=current;
    }
    List=first;
    while(List!=NULL){ //印出鏈結串列
        printf("%d ", List->data);
        List=List->next;
    }
    printf("\n");
    
    //reverse;
    NODE *last,*next;
    last=NULL;
    
    while(first){ //反轉鏈結串列
        next=(NODE*)malloc(sizeof(NODE));
        
        next=first->next;
        first->next=last;
        last=first;
        first=next;
    }
    
    while(last!=NULL){ //印出反轉結果
        printf("%d ", last->data);
        last=last->next;
    }
    printf("\n");
    return 0;
}
