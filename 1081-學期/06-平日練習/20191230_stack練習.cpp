#include<stdio.h>
#include<stdlib.h>
typedef struct stack{
    int val;
    struct stack *next;
}Stack;

void Pop(Stack*,int);
void Push(Stack*,int*);
void PrintStack(Stack*);

int main(void){
    Stack *stack=(Stack*)malloc(sizeof(Stack));
    int list[7], output[7]={0};
    
    for(int i=0;i<7;i++) list[i]=i+1;
    stack->val=NULL; stack->next=NULL;
    
    for(int i=0;i<7;i++) Pop(stack,list[i]);
    PrintStack(stack);

    for(int i=0;i<4;i++) Push(stack,&output[i]);
    PrintStack(stack);
    for(int i=0;i<7;i++) printf("%d ",output[i]);
    
    printf("\n");
    return 0;
}
void Pop(Stack* S,int num){
    Stack *newnode=(Stack*)malloc(sizeof(Stack));
    newnode->val=num;
    newnode->next=S->next;
    S->next=newnode;
}
void Push(Stack* S,int* nums){
    *nums=S->next->val;
    S->next=S->next->next;
}
void PrintStack(Stack* S){
    S=S->next;
    while(S) {printf("%d ", S->val); S=S->next;}
    printf("\n");
}

/*
 linked list的首節點(first node)都不放任何資料;
*/
