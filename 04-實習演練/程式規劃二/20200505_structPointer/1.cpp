#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 20

void USER_CREATE(char ***DB, int size);
void USER_INPUT(char **DB, int size);

void DB_PRINT(char **DB, int size); 
char* DB_FIND(char **DB, int DBsize, char *target);
void DB_ADD(char ***DB, int *DBsize, int *oriSize, char *target);
void DB_DELETE(char **DB, int *DBsize, char *target);
void DB_RESIZE(char ***DB, int DBsize, int *oriSize);
void DB_EDIT(char **DB, int DBsize, char *target, char *element);

void GET_CHOSE(int *chose);
void GET_TARGET(int chose, char *target, char *element);

int main(void){
	int n = 5, oriSize=5, chose = 1;
	char **DB, target[MAX]="John", element[MAX]="John";

	start:
	printf("請輸入要有幾組資料: "); scanf("%d", &n);
	if(n<1) {printf("\t[ 錯誤, 請重新輸入 ]\n"); goto start;}
	USER_CREATE(&DB, n);
	USER_INPUT(DB, n);
	oriSize = n+3;

	while(chose){
		GET_CHOSE(&chose);
		GET_TARGET(chose, target, element);
		switch(chose){
			case 0: break;
			case 1: DB_PRINT(DB, n); break;
			case 2: puts(DB_FIND(DB, n, target)); break;
			case 3: DB_ADD(&DB, &n, &oriSize, element); break;
			case 4: DB_EDIT(DB, n, target, element); break;
			case 5: DB_DELETE(DB, &n, target); break;
			default: printf("\t[ 輸入錯誤 ]\n"); break;
		}
	}
    return 0;
}
void DB_EDIT(char **DB, int DBsize, char *target, char *element){
	for(int i=0;i<DBsize;i++)
		// 找到目標;
		if( strcmp(DB[i],target) == 0 ){
			strcpy(DB[i],element); //將目標 更改成 新資料;
			return;
		}
	printf("\t[ 無此帳號 ]\n");
}
void DB_DELETE(char **DB, int *DBsize, char *target){
	if(DB_FIND(DB, DBsize[0], target) == NULL) // 找不到;
		{ printf("\t[ 此帳號不存在 ]\n"); return; }
	for(int i=0;i<DBsize[0];i++)
		if(strcmp(DB[i],target) == 0){ //找到後將後面的資料依序往前;
			for(int j=i;j<DBsize[0]-1;j++)
				strcpy(DB[j], DB[j+1]);
			memset(DB[DBsize[0]-1],'\0',MAX); //初始化最後一個元素
			DBsize[0] -= 1; //size -= 1;
			return;
		}	
}
void DB_ADD(char ***DB, int *DBsize, int *oriSize, char *target){
	if(DB_FIND(DB[0], DBsize[0], target) != NULL) //已有 return;
		{ printf("\t[ 此帳號已存在 ]\n"); return; }
	if(DBsize[0]+1 == oriSize[0]){ //如超過 已有空間 則 resize;
		printf("resize!\n");
		DB_RESIZE(DB, DBsize[0],oriSize);
		return;
	}
	strcpy(DB[0][DBsize[0]], target); // 新增
	DBsize[0]+=1; // size ++;
}
char* DB_FIND(char **DB, int DBsize, char *target){
	for(int i=0;i<DBsize;i++) 
		if(strcmp(DB[i],target)==0) //找到則return 該筆資料;
			return DB[i];
	return NULL;
}
void DB_PRINT(char **DB, int size){
	printf("\n========== 全部帳號 ==========\n");
	for(int i=0;i<size;i++) //依序 print;
		printf("%4d\t%s\n", i+1, DB[i]);
}
void DB_RESIZE(char ***DB, int DBsize, int *oriSize){
	oriSize[0]+=10;
	DB[0] = (char**)realloc(DB[0],sizeof(char*)*oriSize[0]);
	for(int i=DBsize;i<oriSize[0];i++)
		DB[0][i] = (char*)malloc(sizeof(char)*MAX);
}
void USER_INPUT(char **DB, int size){
	printf("請依序輸 %d 個帳號:\n", size);
	for(int i=0;i<size;i++){
		printf("第%d個: ", i+1);
		scanf("%s", DB[i]); getchar();
	}
}
void USER_CREATE(char ***DB, int size){
	DB[0] = (char**)malloc(sizeof(char*)*(size+3));
	for(int i=0;i<(size+3);i++)
		DB[0][i] = (char*)malloc(sizeof(char)*MAX);
}
void GET_TARGET(int chose, char *target, char *element){
	if(chose==2 || chose==4 || chose==5){
		printf("請輸入目標帳號: ");
		scanf("%s", target); getchar();
	}
	if(chose==4 || chose==3){
		printf("請輸入新帳號: ");
		scanf("%s", element); getchar();
	}
}
void GET_CHOSE(int *chose){
	char tmp[MAX];
	char hint[]="\n\t@主選單@\n(1)印出全部帳號\n(2)搜尋\n(3)新增\n(4)更改\n(5)刪除\n(0)結束\n請輸入選擇: ";
	printf("%s", hint);
	scanf("%s", tmp); getchar();
	if(tmp[0]<'0'||tmp[0]>'9') { printf("\t[ 輸入錯誤 ]\n");return; }
	sscanf(&tmp[0],"%d", chose);
}