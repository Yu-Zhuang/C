#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void){
	char input[21], tmp;
	int size=0, i=0, j;
	memset(input,'\0',21);
	
	scanf("%s", input);
	while(input[size]!='\0') size++;
	j=size;
	printf("原始字串: ");
	for(i=0;i<size;i++) printf("%c", input[i]);
	printf("\n");
	i=0; j=size;
	while(i<j){
		tmp=input[i];
		input[i]=input[j];
		input[j]=tmp;
		i++; j--;
	}
	printf("反轉字串: ");
	for(i=0;i<=size;i++) printf("%c", input[i]);
    return 0;
}