#include<stdio.h>
#include<stdlib.h>

typedef struct tree{ //tree
    int val;
    struct tree *lchild, *rchild;
}BiTree;
typedef struct quene{ //quene
    int data;
    struct quene *next;
}Quene;
BiTree* ptr; //ptr==當前要加入element的parent;

void insertTree (BiTree*,Quene*,int); //insert element in tree;
void PreorderSearch (BiTree*, int); //將ptr指向要加element的parent;
void PrintTree (BiTree*); //print tree (preorder, inorder, postorder);
void preorder(BiTree*);void inorder(BiTree*);void postorder(BiTree*); //for print;

void Enquene (Quene*,int); //enquene;
void Dequene (Quene*); //dequene;

int main(void){ //main
    BiTree *root=(BiTree*)malloc(sizeof(BiTree)); //宣告root;
    Quene *quene=(Quene*)malloc(sizeof(Quene)); //宣告queue;
    int list[7],i; //宣告array and i;
    
    root->val=NULL; root->lchild=NULL; root->rchild=NULL; //初始化 root;
    quene->data=NULL; quene->next=NULL; //初始化 quene;
    for(i=0;i<7;i++) list[i]=1+i; //初始化要存入binary tree的資料list[];
    
    for(i=0;i<7;i++) insertTree(root,quene,list[i]);//construct binary tree;
    PrintTree(root);//print binary tree (preorder, inorder, postorder);

    return 0; //end;
}
//insertTree function;
void insertTree(BiTree* tree,Quene* Q,int num){//insert element in tree
    if(!tree->val&&!tree->lchild&&!tree->rchild){ //if tree is empty;
        tree->val=num;
        Enquene(Q,num);
    }else{
        PreorderSearch(tree, Q->next->data);//將ptr指向要加element的parent;
        if(ptr->lchild==NULL){ //左子樹empty 時執行;
            BiTree* newchild=(BiTree*)malloc(sizeof(BiTree)); //建新樹;
            newchild->val=num; newchild->lchild=NULL; newchild->rchild=NULL;
            ptr->lchild=newchild; //左子樹接newchild;
            Enquene(Q,num); //將element放入quene中 待之後搜尋要加element的parent;
        }else if(ptr->rchild==NULL){ //右子樹empty 時執行;
            BiTree* newchild=(BiTree*)malloc(sizeof(BiTree));
            newchild->val=num; newchild->lchild=NULL; newchild->rchild=NULL;
            ptr->rchild=newchild;
            Enquene(Q,num);
            Dequene(Q); //右子樹接完後左右皆有子樹,則dequene,往下一個要加子樹的parent;
        }
    }
}
void PreorderSearch (BiTree* tree, int num){ //將ptr指向要加element的parent;
    if(tree!=NULL){
        if(tree->val==num) {ptr=tree;goto end;} //找到後將ptr指向欲加子樹的node 並跳出遞迴;
        PreorderSearch(tree->lchild,num);
        PreorderSearch(tree->rchild,num);
    }
    end: ;
}
//quene;
void Enquene (Quene* Q,int n){
    Quene *newnode=(Quene*)malloc(sizeof(Quene));
    newnode->data=n;
    while(Q->next!=NULL) Q=Q->next;
    newnode->next=Q->next;
    Q->next=newnode;
}
void Dequene (Quene* Q){
    Q->next=Q->next->next;
}
//PrintTree
void PrintTree (BiTree* tree){ //print tree (preorder
    printf("preorder: "); preorder(tree);
    printf("\ninorder: "); inorder(tree);
    printf("\npostorder: "); postorder(tree); printf("\n");
}
void preorder(BiTree* tree){
    if(tree!=NULL){
        printf("%d ",tree->val); preorder(tree->lchild); preorder(tree->rchild);
    }
}
void inorder(BiTree* tree){
    if(tree!=NULL){
        inorder(tree->lchild); printf("%d ",tree->val); inorder(tree->rchild);
    }
}
void postorder(BiTree* tree){
    if(tree!=NULL){
        postorder(tree->lchild); postorder(tree->rchild); printf("%d ",tree->val);
    }
}
