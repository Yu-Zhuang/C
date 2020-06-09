# include <iostream>
# include <cstdlib>
# include <time.h>
using namespace std;

typedef struct node{
	int val;
	struct node *next;
}NODE;

NODE* NODE_CREATE(int element){
	// create node
	NODE *node = (NODE*)malloc(sizeof(NODE));
	node->val = element;
	node->next = NULL;
	// return new node
	return node;
}

void ADD(NODE *head, int element){
	NODE *tmp = head;
	// find rear
	while(tmp->next != NULL)
		tmp = tmp->next;
	// add newnode to rear
	tmp->next = NODE_CREATE(element);
}

void REVER_PRINT(NODE *head){
	// not rear
	if(head != NULL){
		// 帶入next遞迴自己
		REVER_PRINT(head->next);
		// 印出
		cout <<head->val<< endl;
	}
	// if its rear just return 
}

int main(void){
	srand(time(NULL));
	NODE *head = NODE_CREATE(0);
	// create linke list
	for(int i=1;i<20;i++)
		ADD(head, rand()%20);
	// print linked list
	NODE *tmp = head;
	while(tmp != NULL){
		cout <<tmp->val<< endl;
		tmp = tmp->next;
	}
	cout <<"reverse:";
	// reverse print
	REVER_PRINT(head);

    return 0;
}