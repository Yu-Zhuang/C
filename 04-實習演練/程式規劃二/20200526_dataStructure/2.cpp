# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX 100

typedef struct q{
	int number;
	int count;
	char name[MAX+1];
	struct q *next;
}QUEUE;

QUEUE* NODE_CREATE(int count, char *tName){
	QUEUE *ret = (QUEUE*)malloc(sizeof(QUEUE));
	ret->number = 0;
	ret->count = count;
	ret->next = NULL;
	if(tName)
		strcpy(ret->name, tName);
	return ret;
}

void ENQUEUE(QUEUE *head){
	int tCount = 0;
	char tName[MAX];
	// input element
	while(tCount < 1){
		printf("請依序輸入 商品名 數量: ");
		scanf("%s %d", tName, &tCount);
		fflush(stdin);
		if(tCount < 1)
			printf("err! \n");
	}
	// 統計目前訂單有的node ++;
	head->count += 1;
	QUEUE *newnode = NODE_CREATE(tCount, tName);
	// 給訂單號碼
	newnode->number = head->count;
	// 放入 queue 中
	QUEUE *tmp = head;
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = newnode;
}

void DEQUEUE(QUEUE *head){
	// head 中是否有元素
	if(head->count){
		// 統計目前訂單有的node -= 1;
		head->count -= 1;
		printf("號碼 \t 名稱 \t 數量\n"); // 印出欲刪除元素
		printf("%d\t%s\t%d\n", head->next->number, head->next->name, head->next->count);
		QUEUE *tmp = head->next;
		// 刪除
		head->next = head->next->next;
		free(tmp);
		QUEUE *temp = head;
		for(int i=1;i<head->count+1;i++){
			temp->next->number = i;
			temp = temp->next;
		}
	}
	// 沒有元素
	else{
		printf("\t[ Stack is empty ]\n");
	}
}

void PRINT(QUEUE *head){
	printf("號碼 \t 名稱 \t 數量\n");
	while(head->next){
		printf("%d\t%s\t%d\n", head->next->number, head->next->name, head->next->count);
		head = head->next;
	}
}

int main(void){
	// input chose
	int chose = 1;
	QUEUE *head = NODE_CREATE(0, NULL);
	while(chose){
		printf("\t@主選單@\n(1)新增\n(2)刪除\n(3)印出\n請輸入選擇: ");
		scanf("%d", &chose);
		if(chose == 1)
			ENQUEUE(head);
		else if(chose == 2)
			DEQUEUE(head);
		else if(chose == 3)
			PRINT(head);
		else if(chose == 0)
			break;
		else
			printf("wrong chose\n");
	}
	return 0;
}