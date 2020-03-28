#include<stdio.h>
#include<stdlib.h>
typedef struct queue{
    int data;
    struct queue *next;
}Queue;
Queue *queue,*rear; //rear指向queue最後一個node;

void Enqueue(Queue*,int);
void Dequeue(Queue*,int*);
void PrintQ(Queue*);

int main(void){
    queue=(Queue*)malloc(sizeof(Queue));
    int input[7],output[7]={0};
    queue->data=NULL; queue->next=NULL;
    for(int i=0;i<7;i++) input[i]=i+1;
    
    for(int i=0;i<7;i++) Enqueue(queue,input[i]);
    PrintQ(queue);
    
    for(int i=0;i<3;i++) Dequeue(queue,&output[i]);
    PrintQ(queue);
    for(int i=0;i<7;i++) printf("%d ",output[i]);
    
    return 0;
}

void Enqueue(Queue* Q,int num){
    Queue *newnode=(Queue*)malloc(sizeof(Queue));
    newnode->data=num;
    newnode->next=NULL;
    if(Q->next==NULL){ //queue為空時執行,第一個位置不存data;
        Q->next=newnode;
        rear=newnode;
    }
    rear->next=newnode;
    rear=newnode;
}
void Dequeue(Queue* Q,int* nums){
    Queue *clear=Q->next; //因第一個位置不存data,所以從第二個開始;
    *nums=Q->next->data;
    Q->next=Q->next->next;
    free(clear);
}

void PrintQ(Queue* Q){
    Q=Q->next; //因第一個位置不存data,所以從第二個開始;
    while(Q){
        printf("%d ",Q->data);
        Q=Q->next;
    }printf("\n");
}

/*
 linked list的首節點(first node)都不放任何資料;
*/
