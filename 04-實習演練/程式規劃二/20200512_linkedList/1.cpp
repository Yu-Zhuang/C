# include <stdio.h>
# include <stdlib.h>

typedef struct link{
	int val;
	struct link *next;
}NODE;

int GET_VAL(void);
void LINK_ADD_FRONT(NODE **pStart, int val);
void LINK_ADD_REAR(NODE **pStart, int val);
void LINK_PRINT(NODE *pStart);

int main(void){
	// alloc link start ptr
	NODE *pStart = NULL;
	// input chose
	int chose = 1;
	while(chose){
		printf("\t@主選單@\n(1)add front node\n(2)add rear node\n(3)print link\n(0)end\nenter chose: ");
		scanf("%d", &chose);
		switch(chose){
			// 1: add front
			case 1: LINK_ADD_FRONT(&pStart, GET_VAL()); break;
			// 2: add rear
			case 2: LINK_ADD_REAR(&pStart, GET_VAL()); break;
			// 3: print
			case 3: LINK_PRINT(pStart); break;
			case 0: break;
			default: printf("\t [ warning ]\n"); break;
		}
	}
	return 0;
}
// add front
void LINK_ADD_FRONT(NODE **pStart, int val){
	// create new node
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->val = val; newNode->next = NULL;
	// if link is empty
	if(pStart[0] == NULL)
		pStart[0] = newNode;
	else{
		// newNode next = pstart
		newNode->next = pStart[0];
		// pstart = newNode
		pStart[0] = newNode;
	}
}
// add rear
void LINK_ADD_REAR(NODE **pStart, int val){
	// create newNode
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	newNode->val = val; newNode->next = NULL;
	// if link is empty
	if(pStart[0] == NULL)
		pStart[0] = newNode;
	else{
		NODE *tmp = pStart[0];
		// ptmp point to rear
		while(tmp->next)
			tmp = tmp->next;
		// newNode next = ptmp->next
		newNode->next = tmp->next;
		// ptmp->next = newNode
		tmp->next = newNode;
	}
}
// print
void LINK_PRINT(NODE *pStart){
	//while (ptmp is not null)
	while(pStart){
		// print val of node
		printf("[%d]-", pStart->val);
		// ptmp = next
		pStart = pStart->next;
	}printf("|END\n");
}
// get input element
int GET_VAL(void){
	int ret = 0;
	printf("請輸入欲增加元素值: ");
	scanf("%d", &ret);
	return ret;
}