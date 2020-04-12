#include<stdio.h>
#include<stdlib.h>

void add(int a,int b);

int main(void){
	void (*ad)(int a, int b) = &add;
	
	(*ad)(5,3);

	return 0;
}

void add(int a,int b){ 
	printf("%d\n", a+b); 
}
/*
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>
// DEFINE struct
typedef struct node{
	int val;
	void (*chs)(struct node*, int);
	struct node *next;
}NODE;
// FUNCTION annoucement
void CHOSE(NODE *head, int chose);
// MAIN
int main(void){  
	NODE *head= (NODE*)malloc(sizeof(NODE));
	head->chs = &CHOSE;
	head->chs(head, 2);
	free(head);
// END_MAIN
    return 0;  
}
// FUNCTION
void CHOSE(NODE *head, int chose){
	switch(chose){
		case 1:
			printf("function 1 run\n");
			break;
		case 2:
			printf("function 2 run\n");
			break;
		default:
			printf("function 3 run\n");
			break;
	}
}
*/
