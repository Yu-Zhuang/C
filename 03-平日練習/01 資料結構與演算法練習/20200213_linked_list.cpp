#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct linked{
    int val;
    struct linked *next;
}LINK;

void createLink(LINK*,int*,int);
void printLink(LINK*);
void reverseLink(LINK*);

int main (void){
	srand(time(NULL));
    int list[7]={0};
    LINK *link=(LINK*)malloc(sizeof(LINK));

    link->val=NULL; link->next=NULL;
    for(int i=0;i<7;i++) {list[i]=rand()%10+1; printf("%d ",list[i]);}
    printf("\n");

    createLink(link,list,7);
    printf("linked list: ");
    printLink(link);

    reverseLink(link);
    printLink(link);

    return 0;
}
void createLink(LINK* node,int *nums,int numsSize){
    LINK *tmp=node;
    for(int i=0;i<numsSize;i++){
        LINK *newnode=(LINK*)malloc(sizeof(LINK));
        newnode->val=nums[i]; 
        tmp->next=newnode;
        tmp=newnode;
    }
    tmp->next=NULL;
}
void printLink(LINK* link){
    link=link->next;
    while(link){
        printf("%d ",link->val);
        link=link->next;
    }printf("\n");
}
void reverseLink(LINK *node){
    LINK *end=NULL, *tmp=node->next->next;
    while(tmp){
        node->next->next=end;
        end=node->next;
        node->next=tmp;
        tmp=tmp->next;
    }
    node->next->next=end;
}




