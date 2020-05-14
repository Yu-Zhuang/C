#include<stdio.h>
#include<stdlib.h>
typedef struct bitr{
    int val;
    struct bitr *right,*left;
}BiTree;

void insertBT(BiTree*, int);
void printBT(BiTree*);

int main(void){
    int list[7]={7,5,9,4,8,6,10};
    BiTree *root=(BiTree*)malloc(sizeof(BiTree));
    root->val=NULL; root->left=NULL; root->right=NULL;
    
    for(int i=0;i<7;i++) insertBT(root,list[i]);
    
    printBT(root);
    
    return 0;
}
void insertBT(BiTree* tree, int num){
    BiTree *ptr=tree, *newnode=(BiTree*)malloc(sizeof(BiTree));
    newnode->val=num; newnode->left=NULL; newnode->right=NULL;
    while(1){
        if(!tree->val) {tree->val=num; break;}
        else if(num>ptr->val){
            if(!ptr->right) {ptr->right=newnode; break;}
            else ptr=ptr->right;
        }else if(num<ptr->val){
            if(!ptr->left) {ptr->left=newnode; break;}
            else ptr=ptr->left;
        }
    }
}
void printBT(BiTree* tree){
    if(tree){
        printBT(tree->left);
        printf("%d ",tree->val);
        printBT(tree->right);
    }
}
