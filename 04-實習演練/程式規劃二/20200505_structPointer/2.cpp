#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//	defien struct
#define MAX 100
typedef struct db{
	char name[MAX];
	char role[MAX];
}DB;
// function_annoucement
void GROUP_CREATE(DB ***LIST, int n);
void GROUP_SUB_CREATE(DB **LIST, int listSize,int *templet);
void GROUP_INPUT(DB **LIST, int listSize, int *templet);
void GROUP_PRINT(DB **LIST, int listSize, int *templet);

int main(void){
	// input N
	int n = 0;
	start:
	printf("請輸入要有幾組: ");
	scanf("%d", &n);
	if(n<1) { printf("\t[輸入錯誤!]\n"); goto start; }
	// create 2d pointer of DB
	DB **LIST;
	GROUP_CREATE(&LIST, n);
	// input each nums of group in array
	int *record = (int*)malloc(sizeof(int)*n);
	printf("*** 請依序輸入各組人數 ***\n");
	for(int i=0;i<n;i++){
		printf("第%d組人數:", i+1);
		scanf("%d", &record[i]);
	}
	// create complete DB according to the array
	GROUP_SUB_CREATE(LIST, n, record);
	// input DB
	GROUP_INPUT(LIST, n, record);
	// print DB
	GROUP_PRINT(LIST, n, record);
	return 0;
}
// create 2d pointer of DB
void GROUP_CREATE(DB ***LIST, int n){
	LIST[0] = (DB**)malloc(sizeof(DB*)*n);
}
// create complete DB according to the array
void GROUP_SUB_CREATE(DB **LIST, int listSize,int *templet){
	// go through LIST
	for(int i=0;i<listSize;i++)
		// alloc size of each group according to templet array
		LIST[i] = (DB*)malloc(sizeof(DB)*templet[i]);
}
// input DB
void GROUP_INPUT(DB **LIST, int listSize, int *templet){
	//go through LIST
	for(int i=0;i<listSize;i++){
		// input each element of group in LIST according to templet array
		printf("輸入第%d組人員資料(共%d人, 至少要有一個組長): \n", i+1, templet[i]);
		for(int j=0;j<templet[i];j++){
			// input each member info
			printf("請輸入第%d人 姓名 角色: ", j+1);
			scanf("%s %s", LIST[i][j].name, LIST[i][j].role);
			fflush(stdin); // 清除緩衝區記憶體;
		}
	}
}
void GROUP_PRINT(DB **LIST, int listSize, int *templet){
	//go through LIST
	for(int i=0;i<listSize;i++){
		printf("第%d組人員資料(共%d人): \n", i+1, templet[i]);
		printf("[姓名]\t[角色]\n");
		// print each member info of group in DB
		for(int j=0;j<templet[i];j++)
			printf("%s\t%s\n", LIST[i][j].name, LIST[i][j].role);
		printf("============\n");
	}	
}