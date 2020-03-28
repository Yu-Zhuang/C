#include<stdio.h>
#include<stdlib.h>
/*
date: 20200228;
purpose: 判斷字串是否獨特;
precondition: "字串";
return: ture or false;
*/
bool ifUni(char *str){
	int check_table[256]={0}, i=0;
	while(str[i]){
		if(check_table[str[i]]) return 0; //遇到重複return 0;
		check_table[str[i]]+=1; //非重複table+=1;
		i++;
	}
	return 1; //皆出現一次return 1;
}

int main(void){
	char string[]="hello";
	int ret;

	ret=ifUni(string);
	
	if(ret) printf("is unique");
	else printf("not unique");

    return 0;
}
