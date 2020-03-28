//


//
//Stack
//用linked list 建構Stack
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
    int data;
    struct Stack *next;
}STACK;
void Push(STACK*,int);
void Pop(STACK*,int*);

int main (){
    int nums[5]={1,3,4,7,9},i;
    STACK S;
    S.next=NULL;
    for(i=0;i<5;i++){
        Push(&S,nums[i]);
    }
    for(i=0;i<5;i++){
        Pop(&S,&nums[i]);
    }
    for(i=0;i<5;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}

void Push(STACK* S,int num){
    STACK *nS=(STACK*)malloc(sizeof(STACK));
    nS->data=num;
    nS->next=S->next;
    S->next=nS;
}

void Pop(STACK* S,int* num){
    if(S->next==NULL)
        printf("stack is empty\n");
    else{
        *num=S->next->data;
        S->next=S->next->next;
    }
}
======================
//Quene_用array建立
#include<stdio.h>
#include<stdlib.h>
#define Size 5
typedef struct quene{
    int data[Size];
    int front=-1;
    int rear=-1;
}Quene;
bool Enquene(Quene*, int);
bool Dequene(Quene*, int*);

int main (){
    int nums[Size]={1,3,4,6,9},ret[Size]={0};
    int i;
    Quene Q;
    for(i=0;i<Size;i++){
        Enquene(&Q, nums[i]);
        printf("%d ",nums[i]);
    }
    printf("\n");
    for(i=0;i<Size;i++){
        Dequene(&Q, &ret[i]);
        printf("%d ",ret[i]);
    }
    return 0;
}

bool Enquene(Quene* q, int n){
    if(q->rear==Size-1)
        return false;
    q->rear+=1;
    q->data[q->rear]=n;
    return true;
}

bool Dequene(Quene* q, int *n){
    if(q->rear==q->front)
        return false;
    q->front+=1;
    *n=q->data[q->front];
    return true;
}
================================
 
