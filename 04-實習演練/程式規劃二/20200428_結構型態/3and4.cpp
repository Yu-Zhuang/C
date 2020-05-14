#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX 21 //帳密最大不超過20字元
typedef struct db{ //定義database
	char account[MAX];
	char password[MAX];
}DB; 

DB* DB_CREATE(int n);
bool DB_FIND(DB *db, int size, char *target);
void DB_FIND_ELEMENT(DB *db, int size, char *target);
void DB_EDIT(DB *db, int size, char *target);
void DB_PRINT(DB *db, int size);
int main(void){
	srand(time(NULL));
	int n=0, chose=1;
	DB *db;
	start:
	printf("請問要有幾筆資料: ");
	scanf("%d", &n);
	while(n<1) { printf("錯誤!\n"); goto start; }
	db = DB_CREATE(n);
	DB_PRINT(db, n);
	while(chose && n){
		printf("\t@主選單@\n(1)搜尋帳戶\n(2)編輯密碼\n(3)印出目前帳戶\n(0)結束\n請輸入: ");
		scanf("%d", &chose);
		if(chose==0) break;
		else if(chose==1){
			char tmp[MAX];
			printf("請輸入欲查詢帳號: ");
			scanf("%s", tmp); getchar();
			DB_FIND_ELEMENT(db, n, tmp);
		}
		else if(chose==2){
			char tmp[MAX];
			printf("請輸入欲編輯帳號: ");
			scanf("%s", tmp); getchar();
			if( ! DB_FIND(db, n, tmp) ) { printf("沒有此帳號\n"); continue; }
			DB_EDIT(db, n, tmp);
		}
		else if(chose==3) DB_PRINT(db, n);
		else printf("\t[ warnning ]: 輸入錯誤\n");
	}

	free(db);
	return 0;
}
// 編輯 密碼
void DB_EDIT(DB *db, int size, char *target){
	char tmp_p[MAX], tmp_p2[MAX];
	int i=0;
	// 找到該帳戶
	for(i=0;i<size;i++)
		if( !strcmp(db[i].account, target) ) break;
	// 確認密碼
	printf("請輸入舊密碼: ");
	scanf("%s", tmp_p); getchar();
	if( strcmp(db[i].password,tmp_p) ) { printf("密碼輸入錯誤!\n"); return; }
	// 輸入 新密碼
	printf("輸入新密碼: ");
	scanf("%s", tmp_p); getchar();
	// 確認 新密碼
	printf("確認新密碼: ");
	scanf("%s", tmp_p2); getchar();
		//確認錯誤
	if( strcmp(tmp_p2,tmp_p) ) { printf("錯誤!\n"); return; }
	// 將該帳戶密碼更改
	strcpy(db[i].password, tmp_p);
}
// 印出資料庫
void DB_PRINT(DB *db, int size){
	printf("[帳號]\t\t[密碼]\n");
	for(int i=0;i<size;i++)
		printf("%s \t%s\n", db[i].account, db[i].password);
}
// 找該帳號 並印出密碼
void DB_FIND_ELEMENT(DB *db, int size, char *target){
	for(int i=0;i<size;i++)
		if( ! strcmp(db[i].account, target) ) { printf("密碼是:%s\n", db[i].password); return; }
	printf("沒此帳號\n");
}
// 創建資料庫
DB* DB_CREATE(int n){
	char tmp_c[MAX], tmp_p[MAX];
	// 合法字元
	char templet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	int tlen = strlen(templet);
	memset(tmp_c,'\0',MAX);
	memset(tmp_p,'\0',MAX);
	DB *ret = (DB*)malloc(sizeof(DB)*n);
	// 依序創建n個帳戶
	for(int i=0;i<n;i++){
		//輸入新帳號
		printf("請輸入新帳號: ");
		scanf("%s", tmp_c); getchar();
		//確認有無重複
		if(DB_FIND(ret, i, tmp_c)) {printf("已有此帳號"); i--; continue;}
		int p_size = 10;
		// 創建密碼(10個字元)
		for(int j=0;j<p_size;j++) tmp_p[j]=templet[rand()%tlen];
		strcpy(ret[i].account, tmp_c);
		strcpy(ret[i].password, tmp_p);
	}
	return ret;
}
// 尋找是否有該帳號, 回傳boolean
bool DB_FIND(DB *db, int size, char *target){
	for(int i=0;i<size;i++)
		if( ! strcmp(db[i].account,target) ) return true;
	return false;
}



