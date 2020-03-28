#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX 100000
#define SIZE 16

void Add(char ACT[][SIZE], char PSW[][SIZE], int chose);
int Search(char *Find, char Templet[][SIZE], int chose);
void Edit(char ACT[][SIZE], char PSW[][SIZE], int chose);
void Remove(char ACT[][SIZE], char PSW[][SIZE], int chose);
void Print(char ACT[][SIZE], char PSW[][SIZE]);

int main(void){
	srand(time(NULL));
	char ACT[MAX][SIZE], PSW[MAX][SIZE];
	int chose=0;
	while(chose!=-1){
		printf("\t@主 選 單@\n");
		printf("(1)新增帳號\n(2)編輯帳號\n(3)刪除帳號\n(4)查詢帳號\n");
		printf("請輸入選擇: ");
		scanf("%d", &chose);
		if(chose == -1) { printf("程式結束\n"); break; }
		else if(chose == 1) Add(ACT, PSW, chose);
		else if(chose == 2) Edit(ACT, PSW, chose);
		else if(chose == 3) Remove(ACT, PSW, chose);
		else if(chose == 4) {
			char tmp[SIZE];
			int adr=0;
			printf("請輸入帳號: ");
			scanf("%s", tmp);
			adr=Search(tmp , ACT, chose);
			if(adr == 0) printf("無此帳號!\n");
			else{
				adr-=1;
				printf("有此帳號, 密碼為: ");
				printf("%s\n", PSW[adr]);
			}
		}
		Print(ACT, PSW);
	}

	return 0;
}
void Remove(char ACT[][SIZE], char PSW[][SIZE], int chose){
	char tmp[SIZE], tmp2[SIZE];
	memset(tmp,'\0',SIZE); memset(tmp2,'\0',SIZE);
	int adr=0;
	printf("請輸入帳號: ");
	scanf("%s", tmp);
	//search
	adr=Search(tmp, ACT, chose);
	if(adr == 0) printf("無此帳號!\n");
	else{
		int k=0, m=0;
		adr-=1;
		while(ACT[k][0]!='\0') k++;
		k-=1;
		//swap;
		memset(PSW[adr],'\0',SIZE);
		memset(ACT[adr],'\0',SIZE);
		while(ACT[k][m]!='\0') { ACT[adr][m]=ACT[k][m]; m++; }
		m=0;
		while(PSW[k][m]!='\0') { PSW[adr][m]=PSW[k][m]; m++; }
		memset(PSW[k],'\0',SIZE);
		memset(ACT[k],'\0',SIZE);
	}
}
void Edit(char ACT[][SIZE], char PSW[][SIZE], int chose){
	char tmp[SIZE], tmp2[SIZE];
	memset(tmp,'\0',SIZE); memset(tmp2,'\0',SIZE);
	int adr=0;
	printf("請輸入帳號: ");
	scanf("%s", tmp);
	//search;
	adr=Search(tmp, ACT, chose);
	if(adr == 0) printf("無此帳號!\n");
	else{
		adr-=1;
		memset(PSW[adr],'\0',SIZE);
		printf("請輸入新密碼: ");
		scanf("%s", tmp2);
		int i=0;
		while(tmp2[i]!='\0') { PSW[adr][i]=tmp2[i]; i++; }
	}
}
int Search(char *Find, char Templet[][SIZE], int chose){
	int adr;
	int F_len=strlen(Find), T_len=0;
	//查詢
	int i=0, k=0;
	while(Templet[i][0]!='\0'){
		k=0;
		while(Templet[i][k] == Find[k]&& Find[k]!='\0') k++;
		T_len=strlen(Templet[i]);
		//printf("%d %d %d %d\n",i, F_len, T_len, k);
		if(k==T_len && k==F_len){ //找到
			//printf("find!\n");
			if(chose == 1) return 1;
			else if(chose == 2 || chose == 3) return i+1;
			else if(chose == 4) return i+1;
		}
		i++;
	}	
	//return adr;
	return 0;
}
void Add(char ACT[][SIZE], char PSW[][SIZE], int chose){
	start:
	char tmp[SIZE], tmp2[SIZE];
	memset(tmp,'\0',SIZE); memset(tmp2,'\0',SIZE);
	printf("請輸入增加帳號(max=15): ");
	scanf("%s", tmp);
	//search
	if(Search(tmp, ACT, chose)!=0){
		printf("帳號已存在\n");
		goto start;
	}
	//add
	else{
		int i=0, k=0;
		while(ACT[i][0]!='\0') i++;
		while(tmp[k]!='\0') { ACT[i][k]=tmp[k]; k++; }
		k=0;
		printf("請輸入增加密碼(max=15): ");
		scanf("%s", tmp2);
		while(tmp2[k]!='\0') { PSW[i][k]=tmp2[k]; k++; }
	}
}
void Print(char ACT[][SIZE], char PSW[][SIZE]){
	int i=0;
	printf("============資料庫============\n");
	while(ACT[i][0]!='\0'){
		printf("\t帳號\t密碼\n");
		printf("%d.\t%s\t%s\n", i+1, ACT[i],PSW[i]);
		i++;
	}
	printf("============END 資料庫============\n");
}









