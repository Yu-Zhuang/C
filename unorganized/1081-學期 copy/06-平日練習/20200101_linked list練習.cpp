#include<stdio.h>
#include<stdlib.h>

typedef struct link{
    int val;
    struct link *next;
}Link;

void insertLink(Link*,int);
void insertNth(Link*,int,int);
void deleteLink(Link*,int);
void reverseLink(Link*);
void printLink(Link*);

int main (void){
    Link *link=(Link*)malloc(sizeof(Link));
    int list[7],i;
    
    link->val=NULL; link->next=NULL;
    for(i=0;i<7;i++) list[i]=i+1;
    
    for(i=0;i<7;i++) insertLink(link,list[i]);
    printLink(link);
    
    insertNth(link,7,9);
    printLink(link);
    
    deleteLink(link,7);
    printLink(link);
    
    reverseLink(link);
    printLink(link);
    
    return 0;
}
void insertLink(Link* L,int num){
    Link *newnode=(Link*)malloc(sizeof(Link));
    static Link *ptr; //static type每次呼叫可保上次的值, const type值不能變;
    newnode->val=num; newnode->next=NULL;
    if(!L->next) ptr=L; //if L is empty;
    ptr->next=newnode; ptr=newnode;
}
void insertNth(Link* L,int Nth, int num){
    Link *tmp=L, *newnode=(Link*)malloc(sizeof(Link));
    newnode->val=num;
    while(Nth-1) {tmp=tmp->next;Nth--;}
    newnode->next=tmp->next;
    tmp->next=newnode;
}
void deleteLink(Link* L,int Nth){
    Link *tmp=L;
    while(Nth-1) {tmp=tmp->next;Nth--;}
    tmp->next=tmp->next->next;
}
void reverseLink(Link* L){
    Link *last=NULL, *next;
    while(L->next){
        next=L->next->next;
        L->next->next=last;
        last=L->next;
        L->next=next;
    }
    L->next=last;
}
void printLink(Link* L){
    L=L->next;
    while(L) {printf("%d ",L->val);L=L->next;}
    printf("\n");
}
