#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	char str[30]; memset(str,'\0',30);
	int number=0;
	char ch='a', ch2='a';

	//input char;
	printf("input a alpha: ");
	scanf("%c", &ch2);
	//清除緩衝區 換行字元( ascii=10 );
	fflush(stdin);
	//input string
	printf("input a string: ");
	scanf("%[^\n]", str); //use "%[^\n] instead "%s" to input a whole sentence include space"
	//清除緩衝區 換行字元( ascii=10 );
	ch=getchar();
	//input number
	printf("input a number: ");
	scanf("%d", &number);
	//output 
	printf("string: %s\nnumber: %d\nch: %d\n", str, number, ch);
	
	return 0;
}

