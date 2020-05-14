#include<stdio.h>
#include<stdlib.h>

typedef struct quene{
    int data;
    struct quene *next;
}Quene;

void Enquene (Quene*,int);
void Dequene (Quene*,int*);
void PrintQuene (Quene*);

int main(void){
    int list[10],newlist[10]={0};
    for(int i=0;i<10;i++) list[i]=1+i;
    Quene *team=(Quene*)malloc(sizeof(Quene));
    team->next=NULL; team->data=NULL;
    printf("Enquene:\n"); //en
    for(int i=0;i<10;i++) Enquene(team,list[i]);
    PrintQuene(team);
    printf("\n");
    
    printf("Dequene:\n"); //de
    for(int i=0;i<5;i++) {Dequene(team,&newlist[i]);}
    PrintQuene(team);
    printf("\nnewlist:\n");
    for(int i=0;i<10;i++) printf("%d ",newlist[i]);
    
    return 0;
}

void Enquene (Quene* Q,int n){
    Quene *newnode=(Quene*)malloc(sizeof(Quene));
    newnode->data=n;
    while(Q->next!=NULL) Q=Q->next;
    newnode->next=Q->next;
    Q->next=newnode;
}
void Dequene (Quene* Q,int* num){
    Quene* clear=Q;
    *num=Q->next->data;
    Q->next=Q->next->next;
    clear=NULL;
}

void PrintQuene(Quene* Q){
    while(Q->next!=NULL) {printf("%d ",Q->next->data); Q=Q->next;}
}



