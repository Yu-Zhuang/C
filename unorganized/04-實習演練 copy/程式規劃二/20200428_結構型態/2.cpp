#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* STR_CRATE(int n); // 統計各字元數量
void STR_COUNT(char *str);

int main(void){
	srand(time(NULL));
	int n=0;
	char *str;
	start:
	printf("請輸入字串大小: ");
	scanf("%d", &n);
	while(n<1) { printf("錯誤!\n"); goto start; }
	str = STR_CRATE(n);
	puts(str);
	STR_COUNT(str);
	free(str);
	return 0;
}
// 統計各字元數量
void STR_COUNT(char *str){
	int list[256]={0}; // 用來統計的list[]
	int slen = strlen(str);
	char ch;
	// 統計 個字元數量
	for(int i=0;i<slen;i++){
		int tmp=str[i];
		// 如果 是小寫字母 以大寫統計(英文大小寫不分去統計)
		if(str[i]>='a'&&str[i]<='z') tmp-=32;
		list[tmp]++;
	}
	// 印出 統計結果
	for(int i=0;i<256;i++)
		if(list[i]){
			ch = i;
			printf("%c: %d\n", ch, list[i]);
		}
}
// 創建字串
char* STR_CRATE(int n){
	char *str = (char*)malloc(sizeof(char)*(n+1));
	// 合法字元
	char templet[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ,. ";
	int tlen = strlen(templet);
	memset(str,'\0',n+1);
	// 產生n大小的字串
	for(int i=0;i<n;i++)
		str[i] = templet[rand()%tlen];
	// 回傳string
	return str;
}



