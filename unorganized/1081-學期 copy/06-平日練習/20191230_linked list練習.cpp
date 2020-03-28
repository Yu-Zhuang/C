#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int data;
    struct link* next;
}Link;

Link* createLink(int*, int);
void PrintL(Link*);
void insertLink(Link*,int,int);
void deleteLink(Link*,int);
void reverseLink(Link*);

int main(void){
    Link *link;
    int list[7],i;
    for(i=0;i<7;i++) list[i]=i+1;
    
    printf("1. create Linked list: ");
    link=createLink(list,7);
    PrintL(link);
    printf("2. insert Linked list: ");
    insertLink(link,4,9); //(link, Nth, num), Nth's range=1~8(in this case);
    PrintL(link);
    printf("3. delete Linked list: ");
    deleteLink(link,3);
    PrintL(link);
    printf("4. reverse Linked list: ");
    reverseLink(link);
    PrintL(link);
  
    return 0;
}
Link* createLink(int* nums, int numsSize){
    Link *first=(Link*)malloc(sizeof(Link)),*current;
    first->data=NULL; first->next=NULL;
    current=first;
    for(int i=0;i<numsSize;i++){
        Link *newnode=(Link*)malloc(sizeof(Link));
        newnode->data=nums[i];
        newnode->next=NULL;
        current->next=newnode;
        current=newnode;
    }
    return first;
}
void insertLink(Link* L,int Nth,int num){
    Link* newnode=(Link*)malloc(sizeof(Link));
    newnode->data=num;
    for(int i=0;i<Nth-1;i++) L=L->next;
    newnode->next=L->next;
    L->next=newnode;
    
}
void deleteLink(Link* L,int Nth){
    for(int i=0;i<Nth-1;i++) L=L->next;
    L->next=L->next->next;
}
void reverseLink(Link* L){
    Link* last=(Link*)malloc(sizeof(Link)),*next;
    last=NULL;
    while(L->next){
        next=L->next->next;
        L->next->next=last;
        last=L->next;
        L->next=next;
    }
    L->next=last;
}
void PrintL(Link* L){
    L=L->next; 
    while(L) {printf("%d ",L->data); L=L->next;}
    printf("\n");
}

/*
 linked list的首節點(first node)都不放任何資料;
 
 */
