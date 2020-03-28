#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
2. 切割字
將原字串copy到另一個字元陣列。使用函式strtok()將str的副本依照空白、逗號、句號、驚嘆號、
左括弧、右括弧等字元切割，然後將切割出來的子字串一一copy到一個「字串陣列」中。
並判斷切出來的子字串是不是都是數字或是全部大寫，例如23, NBA。
Ex:
原字串: "The C library function char *gets(char *str) reads a line from stdin and 
stores it into the string pointed to by"

*/
int main(void){
	char origin[]="The C library function char *gets (char *str) reads a line from stdin 23 and stores it into the string pointed to by";
	char copy[1000]; memset(copy,'\0',1000);
	char ret[1000][1000]; for(int i=0;i<1000;i++) memset(ret[i],'\0',1000);
	bool flag=false;
	char *token;
	int i=0, total=0;
//slice
	strcpy(copy,origin);
	token=strtok(copy," .,!()");
	while(token){ strcpy(ret[i], token); token=strtok(NULL," .,!()"); i++; }
//print slice result
	for(int k=0;k<i;k++){
		if(ret[k][0]!='\0') puts(ret[k]);
	}
//check whether all upper or not 
	printf("全部都大寫: \n");
	for(int k=0;k<i;k++){
		if(ret[k][0]!='\0'){
			int len= strlen(ret[k]), flag=1;
			for(int h=0;h<len;h++) { if(ret[k][h]>'Z' || ret[k][h]<'A'){flag=0; break;}  }
			if(flag) puts(ret[k]);
		}
	}
//check whether all number or not
	printf("\n全部都數字: \n");
	for(int k=0;k<i;k++){
		if(ret[k][0]!='\0'){
			int len= strlen(ret[k]), flag=1;
			for(int h=0;h<len;h++) { if(ret[k][h]>'9' || ret[k][h]<'0'){flag=0; break;}  }
			if(flag) puts(ret[k]);
		}
	}
	return 0;
}