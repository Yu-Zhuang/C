#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>
// DEFINE struct
typedef struct node{
	int val;
	void (*chose)(struct node*, int, int);
	struct node *next;
}NODE;

enum func{
	F_insert,
	F_remove,
	F_print,
	F_empty
}chose;
// FUNCTION annoucement
void CHOSE(NODE *head, int chose, int element);

void LINK_INSERT(NODE *head, int element);
void LINK_PRINT(NODE *head);
void LINK_REMOVE(NODE *head, int target);
void LINK_EMPTY(NODE *head);
// MAIN
int main(void){  
	NODE head;
	head.chose = &CHOSE;
	head.next = NULL;
	// insert
	for(int i=0;i<11;i++) head.chose(&head, F_insert, i);
	// print
	head.chose(&head, F_print, NULL);
	// remove
	for(int j=4;j<7;j++) head.chose(&head, F_remove, j);
	// print
	head.chose(&head, F_print, NULL);
	// clear link
	head.chose(&head, F_empty, NULL);
// END_MAIN
    return 0;  
}
// FUNCTION
void CHOSE(NODE *head, int chose, int element){
	switch(chose){
		case 0:
			LINK_INSERT(head, element);
			break;
		case 1:
			LINK_REMOVE(head, element);
			break;
		case 2:
			LINK_PRINT(head);
			break;
		default:
			LINK_EMPTY(head);
			break;
	}
}
void LINK_INSERT(NODE *head, int element){
	NODE *newnode = (NODE*)malloc(sizeof(NODE));
	newnode->val = element; newnode->next = NULL;

	while(head->next!=NULL) head = head->next;
	head->next = newnode;
}
void LINK_REMOVE(NODE *head, int target){
	NODE *pre=head;
	while(head->val != target && head) { pre=head; head=head->next; }
	pre->next = head->next;
}
void LINK_PRINT(NODE *head){
	head=head->next;
	while(head) { printf("[%d]->", head->val); head=head->next; }
	printf("|\n");
}
void LINK_EMPTY(NODE *head){
	head = head->next;
	NODE *tmp=head;
	while(head){
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
