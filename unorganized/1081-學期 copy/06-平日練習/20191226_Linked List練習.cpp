#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode {
     int data;
     struct ListNode *next;
}List;

List* createList(int*,int); //建立
void printList(List*); //印出
List* reverseList(List*); //反轉
List* insertList(List*,int Nth,int num); //Nth 插入位置, num插入元素;
List* deleteList(List*,int Nth); // Nth 刪除位置;

int main(void){
    int nums[10];
    for(int i=1;i<11;i++) nums[i-1]=i;
    
    List *one=createList(nums,10); //create
    printList(one); //print
    
    printf("\nafter reverse:\n");
    
    List *two=reverseList(one); //reverse
    printList(two); //print
    
    printf("\nafter insert:\n");
    List *three=insertList(two,1,7); //insert
    printList(three); //print
    
    printf("\nafter delete:\n");
    printList(deleteList(three,2)); //delete //print
    
    return 0;
}

List* createList(int* nums,int numsSize){ //用Stack的方式建立linked list;
    List *first=(List*)malloc(sizeof(List));
    first->next=NULL;
    for(int i=numsSize-1;i>=0;i--){ //因此將資料陣列nums 反著存入便會負負得正;
        List *newnode=(List*)malloc(sizeof(List));
        newnode->data=nums[i];
        newnode->next=first->next;
        first->next=newnode;
    }
    first=first->next;
    return first;
}

void printList(List* L){ //print
    while(L!=NULL) {printf("%d ",L->data); L=L->next;}
}

List* reverseList(List* L){ //reverse
    List *last=NULL,*tmp=L;
    while(L!=NULL){
        tmp=tmp->next;
        L->next=last;
        last=L;
        L=tmp;
    }
    L=last;
    return last;
}

List* insertList(List* L,int Nth,int num){ //insert: Nth 插入位置, num插入元素;
    List *tmp=L, *newnode=(List*)malloc(sizeof(List));
    newnode->data=num;
    if(Nth<=0);
    else if(Nth==1) {newnode->next=tmp;return newnode;}
    else{
        while(Nth!=2){Nth--; tmp=tmp->next;}
        newnode->next=tmp->next;
        tmp->next=newnode;
    }
    return L;
}

List* deleteList(List* L,int Nth){ //delete: Nth 刪除位置;
    if(Nth==1) {L=L->next;return L;}
    List *ptr=L;
    while(Nth>2){
        Nth--;
        ptr=ptr->next;
    }ptr->next=ptr->next->next;
    return L;
}
