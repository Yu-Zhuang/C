# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX 20

typedef struct p{
	char name[MAX];
	char id[MAX];
	char time[MAX];
	char phone[MAX];
	bool reserve;
	bool finish;
	struct p *next;
}PERSON;

void GET_TARGET(char *target){
	printf("請輸入身分證字號: ");
	scanf("%s", target);
}

void DB_PRINT(PERSON *DB){
	printf("[Name] \t [ ID ] \t [Time] \t [Phone] \t[Reserve]\t[Finish]\n");
	while(DB->next){
		printf("%s\t%s\t%s\t%s\t \t%d  \t  %d  \n", DB->next->name, DB->next->id, DB->next->time, DB->next->phone, DB->next->reserve, DB->next->finish);
		DB = DB->next;
	}
}
PERSON* DB_FIND(PERSON *DB, char *target){
	while(DB->next){
		if(strcmp(DB->next->id, target) == 0)
			return DB->next;
		DB = DB->next;
	}
	return NULL;
}
void DB_INSERT(PERSON *DB, char *target){
	PERSON *cur = DB_FIND(DB, target);
	// 已有該人
	if( cur ){
		int chose = 1;
		printf("%s\t%s\t%s\t%s\t%d\t%d\n", cur->name, cur->id, cur->time, cur->phone, cur->reserve, cur->finish);
		printf("是否要更新? 1是, 0不更新: ");
		scanf("%d", &chose);
		// 更新
		if(chose){
			printf("請輸入欲更新資料 姓名 身分證字號 時間 電話: ");
			scanf("%s %s %s %s", cur->name, cur->id, cur->time, cur->phone);
			fflush(stdin);
		}
	}
	// 新增
	else{
		// create new node
		PERSON *newNode = (PERSON*)malloc(sizeof(PERSON));
		printf("請輸入新資料 姓名 時間 電話: ");
		scanf("%s %s %s", newNode->name, newNode->time, newNode->phone);
		strcpy(newNode->id, target);
		newNode->reserve = true;
		newNode->finish = false;
		newNode->next = DB->next;
		DB->next = newNode;
		fflush(stdin);		
	}
}

void DB_CANCEL(PERSON *DB, char *target){
	PERSON *cur = DB_FIND(DB, target);
	// 有此資料
	if( cur )
		// 取消預約
		cur->reserve = false;
	else
		printf("\t [ 無此資料 ]\n");
}

void DB_FINISH(PERSON *DB, char *target){
	PERSON *cur = DB_FIND(DB, target);
	// 有此資料
	if( cur )
		// 更動為 已看診
		cur->finish = true;
	else
		printf("\t [ 無此資料 ]\n");
}

int main(void){
	PERSON *DB = (PERSON*)malloc(sizeof(PERSON));
	DB->next = NULL;
	// input chose
	int chose = 1;
	char target[MAX] ={'\0'};
	while( chose ){
		printf("\t@主選單@\n(1)印出所有資料\n(2)新增\n(3)取消預約\n(4)完成看診\n(0)結束\n請輸入: ");
		scanf("%d", &chose);
		if(chose>1 && chose<5)
			GET_TARGET(target);
		switch(chose){
		// print db
			case 1: DB_PRINT(DB); break;
		// add person
			case 2: DB_INSERT(DB, target); break;
		// cancel reserve
			case 3: DB_CANCEL(DB, target); break;
		// finish
			case 4: DB_FINISH(DB, target); break;
			case 0: printf("\t[ 結束 ]\n"); break;
			default: break;
		}
	}
	// end
	return 0;
}