#include<stdio.h>
#include<stdlib.h>
typedef struct link{
    int val;
    struct link *next;
}LINK;

void createLink(LINK*,int*,int);
void printLink(LINK*);
void reverseLink(LINK*);

int main(void){
    LINK* link=(LINK*)malloc(sizeof(LINK));
    int list[5]={1,3,5,6,7};
    
    link->val=NULL; link->next=NULL;
    
    createLink(link,list,5);
    printLink(link);
    
    reverseLink(link);
    printLink(link);
    
    return 0;
}
void createLink(LINK *L,int *nums, int size){
    LINK *tmp=L;
    for(int i=0;i<size;i++){
        LINK *newnode=(LINK*)malloc(sizeof(LINK));
        newnode->next=NULL; newnode->val=nums[i];
        tmp->next=newnode; tmp=newnode;
    }
}
void reverseLink(LINK* L){
    LINK *next,*last=NULL;
    while(L->next){
        next=L->next->next;
        L->next->next=last;
        last=L->next;
        L->next=next;
    }
    L->next=last;
}

void printLink(LINK *L){
    L=L->next;
    while(L){
        printf("%d ",L->val);
        L=L->next;
    }printf("\n");
}

