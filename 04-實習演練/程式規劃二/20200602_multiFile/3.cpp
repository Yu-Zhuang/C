# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# define MAX 100

void REVER_PRINT(char *input, int site){
	if(input[site] == '\0')
		return;
	REVER_PRINT(input, site+1);
	printf("%c", input[site]);
}

int main(void){
	char input[MAX] = {'\0'};
	printf("input a string: ");
	scanf("%[^\n]", input);
	fflush(stdin);
	REVER_PRINT(input, 0);
	printf("\n");
	return 0;
}