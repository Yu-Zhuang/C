# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define SIZE 10
typedef struct link{
	int val;
	struct link *next;
}NODE;

void DB_INIT(NODE *db);
void DB_INSERT(NODE *db, int element);
void DB_RPINT(NODE *db);
void DB_FIND(NODE *db, int element);

int GET_TARGET(void);

int main(void){
	srand(time(NULL));
	// alloc pointer array
	NODE DB[SIZE];
	// initialize pointerArray
	DB_INIT(DB);
	// input chose
	int chose = 1;
	while(chose){
		printf("\n\t@主選單@\n(1)search\n(2)add\n(3)print\n(0)end\nEnter chose: ");
		scanf("%d", &chose);
		// switch
		switch(chose){
			// search element
			case 1: 
				{int num=GET_TARGET(); if(num>=0&&num<100) DB_FIND(&DB[num/10], num);\
										else printf("not find\n");} 
				break;
			// add element
			case 2:
				{int num=GET_TARGET(); if(num>=0&&num<100) DB_INSERT(&DB[num/10], num);\
										else printf("\t[ failed add ]\n");} 
				break;
			// print DB	
			case 3: DB_RPINT(DB); break;
			case 0: printf("\t[ 結束 ]\n"); break;
			default: printf("\t[ warning ]\n"); break;
		}	
	}
	return 0;
}
void DB_INIT(NODE *db){
	int num = 0;
	// init array
	for(int i=0;i<SIZE;i++)
		{ db[i].next = NULL; db[i].val = 0; }
	// put 20 rand num to DB
	for(int i=0;i<20;i++){
		// rand(0,99)
		num = rand()%100;
		// insert to pedigree of DB
		DB_INSERT(&db[num/10], num);
	}
}
void DB_FIND(NODE *db, int element){
	// if pedigree isn't empty
	if(db->val){
		// go through pedigree
		NODE *tmp = db->next;
		while(tmp){
			// if find print and return
			if(tmp->val == element){
				printf("\t[ Find ]\n");
				return;
			}
			tmp = tmp->next;
		}
	}
	// print failed 
	printf("\t[ Not Find ]\n");
}
void DB_INSERT(NODE *db, int element){
	// create newNODE
	NODE *newNODE = (NODE*)malloc(sizeof(NODE));
	newNODE->val = element;
	// newNODE next = db[0] next
	newNODE->next = db->next;
	// db[0] next = newNODE
	db->next = newNODE;
	// db[0] val += 1
	db->val ++;
}
void DB_RPINT(NODE *db){
	NODE *tmp = NULL;
	printf("[n]\t[link]\n");
	for(int i=0;i<SIZE;i++){
		printf("%d.\t", i);
		tmp = db[i].next;
		while(tmp)
			{ printf("[%d]-", tmp->val); tmp = tmp->next; }
		printf("|END\n");
	}
}
int GET_TARGET(void){
	int ret = 0;
	printf("Enter element: ");
	scanf("%d", &ret);
	return ret;
}