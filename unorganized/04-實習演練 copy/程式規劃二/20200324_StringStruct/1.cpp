#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
1.搜尋子字串
讓使用者輸入一個字串substr，z的訊息。
Ex:
原字串: "The C library function char *gets(char *str) reads a line from stdin and stores it into the string pointed to by"
要搜尋的子字串: "char"
有找到子字串"char"，index是23, 34
*/
#define MAX 1000
void FindSub(char *, char *);
int main(void){
	char str[MAX], substr[MAX];
	memset(str,'\0',MAX); memset(str,'\0',MAX);
	int len;
	bool flag;
	//input string 
	printf("請輸入主字串: ");
	scanf("%[^\n]", str);
	fflush(stdin);
	//input substring
	printf("請輸入子字串: ");
	scanf("%[^\n]", substr);
	// has substr in mainstr or not?
	flag=strstr(str, substr);
	//has
	if(flag) FindSub(str, substr); 
	// has not
	else printf("沒有子字串\n");

	return 0;
}
void FindSub(char *str, char *substr){
	int len_1=strlen(str), len_2=strlen(substr);
	int i=0, j=0, tmp=0;

	while(str[i]!='\0'){
		tmp=i; j=0;
		while(str[tmp] == substr[j] && substr[j]!='\0' && str[tmp]!='\0') { tmp++; j++; }
		//find substr in str: print the index
		if(j== len_2) printf("%d ", i);
		i++;
	}
	printf("\n");
}




